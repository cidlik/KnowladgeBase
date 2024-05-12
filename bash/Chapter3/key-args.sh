#!/usr/bin/env bash

# Usage:
#   * ./key-args.sh -a
#   * ./key-args.sh -a -c
#   * ./key-args.sh -a -c -d

while [ -n "$1" ]; do
    case "$1" in
        -a) echo Found -a option ;;
        -b) echo Found -b option ;;
        -c) echo Found -c option ;;
        *) echo Unknown argument $1 ;;
    esac
    shift
done
