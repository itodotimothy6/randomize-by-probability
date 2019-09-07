#!/bin/bash

# Get all arguments and append into a file called "input.txt"
>input.txt  # Create/Empty the input.txt
for arg in "$@"
do
    echo "$arg" >> "input.txt"
done

# Compile and run solution.cpp
g++ solution.cpp && ./a.out