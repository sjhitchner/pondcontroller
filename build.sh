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
GOOS=linux GOARCH=mipsle go build -o ${NAME} -ldflags "-s -w -X main.VERSION=$GITSHA" . 
if [ "$?" != "0" ]; then
        echo "Failed building binary"
        exit -1
fi

rsync -P -a rc.local $HOST:/etc/rc.local
if [ "$?" != "0" ]; then
        echo "Failed uploading boot config"
        exit -1
fi

rsync -P -a $NAME onion-setup.sh $HOST:/root
if [ "$?" != "0" ]; then
        echo "Failed uploading binary setup files"
        exit -1
fi

