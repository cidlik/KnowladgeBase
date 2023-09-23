#!/bin/bash

export FOO=BAR
echo "echo \$FOO" > tmp.sh
bash tmp.sh

XYZ=ABC
echo "echo \$XYZ" > tmp.sh
bash tmp.sh

rm -f tmp.sh
