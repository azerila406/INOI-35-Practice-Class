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

g++ -O2 "$DIR/accept.cpp"

IN_DIR="$DIR/in"
OUT_DIR="$DIR/out"
EXE="./a.out"
TMP="tmp.txt"

touch "$TMP"

for infile in "$IN_DIR"/input*.txt; do
    [ -e "$infile" ] || continue
    num=$(basename "$infile" | grep -o -E '[0-9]+')
    outfile="$OUT_DIR/output${num}.txt"
    if [ ! -f "$outfile" ]; then
        echo "[FAIL] Missing $outfile"
        exit 1
    fi

    "$EXE" < "$infile" > "$TMP"

    if diff -wB "$TMP" "$outfile" > /dev/null; then
        echo "[PASS] Test $num passed"
    else
        echo "[FAIL] Test $num failed"
    fi
done

rm "$EXE"
rm "$TMP"
