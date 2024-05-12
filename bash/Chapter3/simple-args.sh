#!/usr/bin/env bash

# Usage examples:
#   * ./simple-args.sh first second third fourth fifth sixth seventh eighth ninth tenth
#   * ./simple-args.sh "first second third fourth fifth sixth seventh eighth ninth tenth"

echo Script name: $0
echo First arg: $1
echo Second arg: $2
echo Third arg: $3
echo Fourth arg: $4
echo Fifth arg: $5
echo Sixth arg: $6
echo Seventh arg: $7
echo Eighth arg: $8
echo Ninth arg: $9
echo "Non-tenth arg: $10; tenth arg: ${10}"
echo Args num: $#
echo Last arg: ${!#}

echo All args: $*
echo All args: $@

block.sh "Args shift"
echo Script name: $0
echo First arg: $1
echo Second arg: $2
shift
echo Script name: $0
echo First arg: $1
echo Second arg: $2
