#!/bin/bash

# Build all .cc files in the specified directory (or current if not specified)
# and its subdirectories using g++ with C++17 standard.

INPUT_PATH="${1:-.}"
CPP_STANDARD="${2:-c++17}"
GENERATE_MAP="${3:-false}"

build_file() {
    local file="$1"
    local dir=$(dirname "$file")
    local filename=$(basename "$file" .cc)
    local output="$dir/$filename"
    
    echo "Building $file..."
    local compile_cmd="g++ -std=\"$CPP_STANDARD\" -Wall -Wextra -pthread -o \"$output\" \"$file\" -ltbb"
    
    if [ "$GENERATE_MAP" = "true" ]; then
        compile_cmd="$compile_cmd -Wl,-Map=\"$output.map\""
    fi
    
    eval "$compile_cmd"
    
    if [ $? -eq 0 ]; then
        echo "Successfully built $output"
        if [ "$GENERATE_MAP" = "true" ]; then
            echo "Map file generated: $output.map"
        fi
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