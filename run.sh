#!/bin/bash

# Run all compiled executables corresponding to .cc files in the 
# specified directory (or current if not specified).

INPUT_PATH="${1:-.}"

if [ -f "$INPUT_PATH" ]; then
    if [ -x "$INPUT_PATH" ]; then
        echo "------------------------------------------------"
        echo "Running $INPUT_PATH ..."
        
        # If path doesn't start with / or ./ or ../, prepend ./ to make it executable
        if [[ "$INPUT_PATH" != /* && "$INPUT_PATH" != ./* && "$INPUT_PATH" != ../* ]]; then
            ./"$INPUT_PATH"
        else
            "$INPUT_PATH"
        fi
        
        echo ""
    else
        echo "Error: '$INPUT_PATH' is a file but not executable."
    fi
elif [ -d "$INPUT_PATH" ]; then
    echo "Running executables in directory '$INPUT_PATH'..."
    find "$INPUT_PATH" -name "*.cc" | sort | while read -r source_file; do
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
else
    echo "Error: '$INPUT_PATH' is not a valid file or directory."
    exit 1
fi
