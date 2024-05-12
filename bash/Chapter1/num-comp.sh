#!/bin/bash

function delimeter () {
    echo "====================="
    echo $1
}

delimeter "Single square brackets number comparison"
[ $([ 5 -eq 3 ]) -eq $(test 5 -eq 3 ) ]; echo $?
[ $([ 5 -ge 3 ]) -eq $(test 5 -ge 3 ) ]; echo $?
[ $([ 5 -gt 3 ]) -eq $(test 5 -gt 3 ) ]; echo $?

[ $([ 5 -le 3 ]) -eq $(test 5 -le 3 ) ]; echo $?
[ $([ 5 -lt 3 ]) -eq $(test 5 -lt 3 ) ]; echo $?
[ $([ 5 -ne 3 ]) -eq $(test 5 -ne 3 ) ]; echo $?

delimeter "Single square brackets number comparison with if ... else"
if [ 5 -gt 3 ]
then
    echo 5 greater then 3
fi

if test 5 -gt 3
then
    echo 5 greater then 3
fi

delimeter "Double square brackets number comparison"
[[ 6 > 4 ]]; echo $?
[[ 6 < 4 ]]; echo $?
[[ 6 == 6 ]]; echo $?

delimeter "Double round brackets number comparison"
(( 6 >= 4 )); echo $?
(( 6 <= 4 )); echo $?
