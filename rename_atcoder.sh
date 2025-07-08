#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <prefix>"
    exit 1
fi

prefix="$1"

i=1
for file in $(ls | sort); do
    echo "renaming $file to ${prefix}${i}.txt"
    mv "$file" "${prefix}${i}.txt"
    ((i++))
done