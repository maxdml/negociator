#!/usr/bin/bash

DIR=`pwd`
SCRIPT=${DIR}'/unit_s'
DUR=$1
TYPE=$2
PARAMS="-${TYPE} -d ${DUR}"

for (( i=0; i<8; i++ ));
do
COMMAND="$SCRIPT -p $i $PARAMS"
echo $COMMAND
$COMMAND &
done
