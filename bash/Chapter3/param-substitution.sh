#!/usr/bin/env bash

# ./param-substitution.sh
# FOO=XYZ ./param-substitution.sh
# FOO= ./param-substitution.sh
echo ${FOO:-BAR}
echo $FOO
echo ${FOO-BAR}
echo $FOO
echo ${FOO:=BAR}
echo $FOO
