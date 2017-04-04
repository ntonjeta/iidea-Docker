#!/bin/bash
set -x

#rm -rf output
clang-chimera -v -fun-op conf.csv -generate-mutants  ../src/sobel.cpp -o output -- -std=c++11  -I../src/boost_1_63_0 -I../src/include 
