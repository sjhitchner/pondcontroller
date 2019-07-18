#!/bin/sh

GIT=/usr/bin/git
DATE=`date +%Y%m%d`
TAG="pondcontroller:$GIT_SHA"
NAME="pondcontroller-onion"
HOST="omega-d0ff.local"

GITSHA=`$GIT rev-parse --short HEAD`
if [[ -z "$GITSHA" ]]; then
        echo "Need to run within a GIT repo"
        exit -1
fi

echo "Compiling Go binary"
GOOS=linux GOARCH=mipsle go build -o ${NAME} -ldflags "-X main.VERSION=$GITSHA" . 
if [ "$?" != "0" ]; then
        echo "Failed building binary"
        exit -1
fi

rsync -P -a $NAME $HOST:/root
# scp $NAME root@omega-1349.local:/root
if [ "$?" != "0" ]; then
        echo "Failed tagging $GITSHA container as latest"
        exit -1
fi
