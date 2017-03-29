#!/bin/bash
set -x

rm -rf output
../../../clang-chimera/build/clang-chimera -v -fun-op conf.csv -generate-mutants  ../src/test.cpp -o output -- -std=c++11 -I /usr/include/opencv2 -I ../src/include/
