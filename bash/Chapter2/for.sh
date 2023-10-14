#!/bin/bash

block.sh "Simple loop"
for color in red blue green yellow
do
    echo Current color: $color
done
echo Out of loop color: $color

block.sh "Files in chapter1"
for f in $(ls ../chapter1/*)
do
    echo $f
done

block.sh "Experiment with IFS"
TMP_FILE=test.txt
# Generate file
cat > $TMP_FILE << EOF
fooo
bar xyz
Simple "text with" quotes
	text with tab indent
!dsadsa!
EOF
# Read
IFS_BAK=$IFS
IFS=$'\n'  # comment me
for l in $(cat $TMP_FILE)
do
    echo $l
done
IFS=$IFS_BAK
rm $TMP_FILE

block.sh "C-style"
for (( a = 1; a < 10; a++ ))
do
    echo Current number $a
done

block.sh "Searching pattern in file via loop"
TMP_FILE=test.txt
PATTERN=pattern
# Generate file
cat > $TMP_FILE << EOF
dspdlsapdsla
sdosapd lpsdlspldsp da
dapsdl spdlsdpsdp alsp ds
sp dlspdl psad
sa dld spsdspdl spdlspd s
ds dp alspd lspdl $PATTERN das
d[sd;a[dsa]]
EOF
# Search
IFS_BAK=$IFS
IFS=$'\n'
for l in $(cat $TMP_FILE)
do
    IFS=' '
    for w in $l
    do
        if [ $w = $PATTERN ]
        then
            echo I found $PATTERN in line \"$l\"
        fi
    done
done
IFS=$IFS_BAK
rm $TMP_FILE
