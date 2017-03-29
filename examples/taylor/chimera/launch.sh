#!/bin/bash
set -x

rm -rf output
../../../clang-chimera/build/clang-chimera -v -fun-op conf.csv -o output -generate-mutants ../src/test.cpp -- -std=c++11
