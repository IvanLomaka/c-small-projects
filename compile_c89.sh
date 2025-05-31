#!/bin/zsh

# Script to compile C files with C89 standard

# Check if a filename was provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.c> [additional_options]"
    echo "Example: $0 quesito2.c"
    echo "Example with options: $0 quesito2.c -lm"
    exit 1
fi

filename=$1
shift  # Remove the first argument (filename) so that $@ contains only additional options

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' not found."
    exit 1
fi

# Set output file name to 'output' instead of using the base name
output_file="output"

# Compile the file with C89 standard and all warnings enabled
gcc -std=c89 -Wall -Werror -pedantic "$filename" -o "$output_file" "$@"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Created executable: $output_file"
    echo "Run with: ./$output_file"
else
    echo "Compilation failed."
    exit 1
fi
