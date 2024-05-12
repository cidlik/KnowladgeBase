#!/usr/bin/env bash

# Usage example:
#   * ./get-all-args.sh first second third
#   * ./get-all-args.sh "first arg" "second arg" "third arg"

echo Print all args via \$*: $*
echo Print all args via \$@: $@

echo Loop over \&* args
for a in $*; do
    echo $a
done

echo Loop over \&@ args
for a in $@; do
    echo $a
done
