#!/usr/bin/env bash

set -e

block.sh "String length"
TEST_STRING="fooo"
echo length ${TEST_STRING} = ${#TEST_STRING}

block.sh "Concat string"
STR1="foo"
STR2="bar"
STR3=$STR1+$STR2
echo $STR3
STR3="${STR1}${STR2}"
echo $STR3
STR3="$STR1$STR2"
echo $STR3
STR3+="xyz"
echo $STR3
STR3=$[ $STR1 + $STR2 ]
echo $STR3

block.sh "Substrings"
STR="foobar"
echo ${STR:2}
echo ${STR:2:2}
echo ${STR#foo}
echo ${STR#fob}
echo ${STR##foo}
echo ${STR%bar}

block.sh "Substrings with replacement"
STR="foobarfoobar"
echo ${STR/"foo"/"xyz"}
echo ${STR//"foo"/"xyz"}
