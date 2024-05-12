#!/usr/bin/env bash

# Usage:
#   * ./key-args.sh -a
#   * ./key-args.sh -a -c
#   * ./key-args.sh -a -c -d

while getopts "abc:(h|help)" opt; do
    case $opt in
        a) echo Option -a ;;
        b) echo Option -b ;;
        c) echo Option -c ;;
        h|help) echo Help
            exit 0 ;;
    esac
done
