#!/bin/bash
set -x

#rm -rf output
../../../clang-chimera/build/clang-chimera -v -fun-op conf.csv -generate-mutants  ../src/bessel.cpp -o output -- -std=c++11  -I../src/ -I../src/include/ 
