#!/bin/bash

# ############################################################
# ###################  Author: Shiva    ######################
# ###################  Date: 12-6-2024  ######################
# ############################################################

# ####################  Description  #########################
# This script monitors a specified C++ file for changes &
# when changes are detected, it compiles and runs the file.

# #######################  Usage    ##########################
# - Open unix terminal, use WSL for windows. Run the following
#  ./leetcode/runcpp.sh <path-to-cpp-file>
# Example: ./leetcode/runcpp.sh ./leetcode/microsoft/31_next_permutation.cpp

# Check if the script received a file path as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <path-to-cpp-file>"
    exit 1
fi

# Path of the single cpp file
CPP_FILE="$1"

# Check if the file exists
if [ ! -f "$CPP_FILE" ]; then
    echo "Error: File '$CPP_FILE' does not exist."
    exit 1
fi

# Determine the directory and base name of the C++ file
DIR=$(dirname "$CPP_FILE")
BASE=$(basename "$CPP_FILE" .cpp)

# Define the output binary path
OUT_FILE="$DIR/out"

# Remove the existing output file if it exists
if [ -f "$OUT_FILE" ]; then
    echo "Removing existing output file: $OUT_FILE"
    rm "$OUT_FILE"
fi

# Monitor the file for changes using find and entr
echo "Watching '$CPP_FILE' for changes. Press Ctrl+C to stop."
find "$DIR" -wholename "$CPP_FILE" | entr -c sh -c \
    "g++ -std=c++17 $CPP_FILE -o $OUT_FILE && $OUT_FILE"
