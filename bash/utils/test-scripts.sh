#!/usr/bin/env bash

set -eu

TEST_DIRS=(
    Chapter1
    Chapter2
    "ABS Guide"
)

for item in ${!TEST_DIRS[@]}; do
    find "${TEST_DIRS[item]}" -type f -name *.sh -print0 | xargs -0 bash
done

block.sh "All checks passed"
