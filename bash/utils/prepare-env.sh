#!/usr/bin/env bash

# Usage:
#   source prepare-env.sh

export PATH=$(find -type d -name utils -exec readlink -f {} \; | grep KnowladgeBase/bash):$PATH
