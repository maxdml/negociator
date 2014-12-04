#!/usr/bin/bash

DUR=$1
BW=$2
timeStart=`date +%s`
endTime=$(($timeStart+$DUR))
cachebench="/opt/llcbench/cachebench/cachebench -m $BW -e 1 -x 2 -d 1 -r"
echo $cachebench

for ((i=$timeStart; i <= $endTime; i=$(date +%s)));
do
    $cachebench
done
