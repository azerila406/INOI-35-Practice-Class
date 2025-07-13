#!/bin/bash

# Usage: ./gen_and_run.sh 10     # generates 10 test cases

set -e  # Exit on any error

NUM_CASES=$1

mkdir -p in out

g++ -O2 model.cpp -o model.out


for ((i = 1; i <= NUM_CASES; i++)); do
    echo "[INFO] Generating test case $i..."

    INPUT_FILE="in/input${i}.txt"
    OUTPUT_FILE="out/output${i}.txt"

    python3 create_test.py > "$INPUT_FILE"

    ./model.out < "$INPUT_FILE" > "$OUTPUT_FILE"

    echo "[OK] input${i}.txt → output${i}.txt"
done
