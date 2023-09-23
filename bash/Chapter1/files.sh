#!/bin/bash

[ -d ../chapter1 ]; echo "-d $?"
[ -e files.sh ]; echo "-e $?"

[ -f ../chapter1 ]; echo "-f $?"
[ -f files.sh ]; echo "-f $?"

[ -r ../chapter1 ]; echo "-r $?"
[ -r files.sh ]; echo "-r $?"
TMP_FILE=tmp.txt; echo foo > $TMP_FILE; chmod -r $TMP_FILE; cat $TMP_FILE
[ -r $TMP_FILE ]; echo "-r $?"
rm $TMP_FILE

[ -w /etc/hostname ]; echo "-w $?"

[ -x files.sh ]; echo "-x $?"

[ math.sh -nt var.sh ]; echo "-nt $?"
[ math.sh -ot var.sh ]; echo "-ot $?"

touch -d 20000101 older
touch -d 20100101 newer
[ older -ot newer ]; echo "older older than newer: $?"
echo foo > older
[ older -ot newer ]; echo "older older than newer: $?"
rm older newer

touch -d 20000101 older
touch -d 20000101 newer
[ older -ot newer ]; echo "equal birth date: $?"
[ older -nt newer ]; echo "equal birth date: $?"
echo foo > older
[ older -ot newer ]; echo "older older than newer: $?"
[ older -nt newer ]; echo "newer newer than older: $?"
rm older newer

[ -O math.sh ]; echo "-O $?"
[ -G math.sh ]; echo "-G $?"
