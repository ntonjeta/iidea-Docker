#!/bin/bash
set -x

rm -rf output
../../../clang-chimera/build/clang-chimera -v -fun-op conf.csv -generate-mutants -o output  ../src/test.cpp -- -std=c++11 -I ../src/include/
