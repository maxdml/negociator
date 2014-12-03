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

# if [ $( `$SCRIPT -p 0 $PARAMS` ) ] 
#then
#    echo "launching ${TYPE} cramming on p0 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 1 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p1 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 2 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p2 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 3 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p3 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 4 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p4 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 5 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p5 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 6 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p6 for ${DUR} sec"
#fi
#if [ $( `$SCRIPT -p 7 $PARAMS` & ) ] 
#then
#    echo "launching ${TYPE} cramming on p7 for ${DUR} sec"
#fi
