#!/bin/bash

function delimeter () {
    echo "====================="
    echo $1
}

delimeter "Compare string with single square brackets"
[ "foo" = "bar" ]; echo $?
[ "foo" != "bar" ]; echo $?
[ "aaa" \> "bbbb" ]; echo $?
[ "aaa" \< "bbbb" ]; echo $?

delimeter "Compare with different upper/lower case"
[ "aaa" \> "bbbb" ]; echo $?
[ "aaa" \> "Bbbb" ]; echo $?

delimeter "Compare string with double square brackets"
[[ "aaa" > "bbbb" ]]; echo $?
[[ "aaa" < "bbbb" ]]; echo $?

delimeter "Zero length string tests"
[ -n "aaa" ]; echo $?
[ -n "" ]; echo $?
[ -n ]; echo $?
[ -z "aaa" ]; echo $?
[ -z "" ]; echo $?
[ -z ]; echo $?
