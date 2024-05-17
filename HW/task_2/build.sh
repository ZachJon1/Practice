#!/usr/bin/env bash

clang++ -o subtract.o -c src/subtract.cpp -I./include/
clang++ -o sum.o -c src/sum.cpp -I./include/
clang++ -o main.o -c src/main.cpp -I./include/

clang++ main.o sum.o subtract.o -o main

