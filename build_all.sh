#!/bin/bash

# Build all .cc files in the specified directory (or current if not specified)
# and its subdirectories using g++ with C++17 standard.

TARGET_DIR="${1:-.}"
CPP_STANDARD="${2:-c++17}"

if [ ! -d "$TARGET_DIR" ]; then
    echo "Error: Directory '$TARGET_DIR' does not exist."
    exit 1
fi

echo "Starting build process in '$TARGET_DIR' using standard $CPP_STANDARD..."

find "$TARGET_DIR" -name "*.cc" | while read -r file; do
    dir=$(dirname "$file")
    filename=$(basename "$file" .cc)
    output="$dir/$filename"
    
    echo "Building $file..."
    g++ -std="$CPP_STANDARD" -pthread -o "$output" "$file"
    
    if [ $? -eq 0 ]; then
        echo "Successfully built $output"
    else
        echo "Failed to build $file"
    fi
done

echo "Build process completed."
