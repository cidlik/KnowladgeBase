#!/bin/bash

block.sh "Simple until"
i=0
until [ $i -ge 5 ]
do
    echo Current i = $i
    (( i++ ))
done
