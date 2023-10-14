#!/usr/bin/env bash

help () {
    echo    Usage:
    echo    \* ./key-and-param-args.sh -a -b privv
    echo    \* ./key-and-param-args.sh -d d_key -a -c -b "b key"
}

while [ -n "$1" ]; do
    case $1 in
        -a) echo Simple key -a ;;
        -b) echo Key -b with value $2
            KEY_B=$2
            shift ;;
        -c) echo Another simple key -c ;;
        -d) echo Key -d with value $2
            KEY_D=$2
            shift ;;
        -h|--help) help
            exit 0 ;;
    esac
    shift
done

echo arg -b after loop: $KEY_B
echo arg -d after loop: $KEY_D
