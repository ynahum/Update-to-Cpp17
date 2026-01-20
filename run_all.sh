#!/bin/bash

# Run all compiled executables corresponding to .cc files in the 
# specified directory (or current if not specified).

TARGET_DIR="${1:-.}"

if [ ! -d "$TARGET_DIR" ]; then
    echo "Error: Directory '$TARGET_DIR' does not exist."
    exit 1
fi

echo "Running executables in '$TARGET_DIR'..."

find "$TARGET_DIR" -name "*.cc" | sort | while read -r source_file; do
    dir=$(dirname "$source_file")
    filename=$(basename "$source_file" .cc)
    executable="$dir/$filename"

    if [ -f "$executable" ] && [ -x "$executable" ]; then
        echo "------------------------------------------------"
        echo "Running $executable ..."
        "$executable"
        echo "" 
    fi
done
