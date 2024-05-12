#!/bin/bash

block.sh "Simple while"
i=0
while [ $i -le 5 ]
do
    echo Current i = $i
    (( i++ ))
    # i=$(( $i + 1 ))
done
