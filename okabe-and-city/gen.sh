#!/bin/bash

# Usage: ./gen_and_run.sh 10     # generates 10 test cases

set -e  # Exit on any error

NUM_CASES=$1

mkdir -p in out

g++ -O2 model.cpp -o model.out

g++ -O2 edge.cpp -o edge.out
g++ -O2 random_gen.cpp -o random.out


for ((i = 1; i <= NUM_CASES; i++)); do
    echo "[INFO] Generating test case $i..."

    INPUT_FILE="in/input${i}.txt"
    OUTPUT_FILE="out/output${i}.txt"

    if [ "$i" -eq "$NUM_CASES" ]; then
        ./edge.out > "$INPUT_FILE"
    else
        ./random.out > "$INPUT_FILE"
    fi

    ./model.out < "$INPUT_FILE" > "$OUTPUT_FILE"

    echo "[OK] input${i}.txt → output${i}.txt"
done