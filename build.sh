#!/bin/bash

# Build all .cc files in the specified directory (or current if not specified)
# and its subdirectories using g++ with C++17 standard.

INPUT_PATH="${1:-.}"
CPP_STANDARD="${2:-c++17}"

build_file() {
    local file="$1"
    local dir=$(dirname "$file")
    local filename=$(basename "$file" .cc)
    local output="$dir/$filename"
    
    echo "Building $file..."
    g++ -std="$CPP_STANDARD" -pthread -o "$output" "$file"
    
    if [ $? -eq 0 ]; then
        echo "Successfully built $output"
    else
        echo "Failed to build $file"
    fi
}

if [ -f "$INPUT_PATH" ]; then
    echo "Building single file '$INPUT_PATH' using standard $CPP_STANDARD..."
    build_file "$INPUT_PATH"
elif [ -d "$INPUT_PATH" ]; then
    echo "Starting build process in directory '$INPUT_PATH' using standard $CPP_STANDARD..."
    find "$INPUT_PATH" -name "*.cc" | while read -r file; do
        build_file "$file"
    done
else
    echo "Error: '$INPUT_PATH' is not a valid file or directory."
    exit 1
fi

echo "Build process completed."
