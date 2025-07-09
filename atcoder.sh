#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <problem-directory>"
    exit 1
fi

DIR="$1"

if [ ! -d "$DIR" ]; then
    echo "Error: '$DIR' is not valid"
    exit 1
fi

cd "$DIR"
cd in
../../rename_atcoder.sh input
cd ../out
../../rename_atcoder.sh output
cd ../../