#!/bin/bash

block.sh "Environment and user variables scope"
export FOO=BAR
echo "echo FOO=\$FOO" > tmp.sh
bash tmp.sh

XYZ=ABC
echo "echo FOO=\$XYZ" > tmp.sh
bash tmp.sh

rm -f tmp.sh
