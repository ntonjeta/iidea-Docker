#!/bin/bash
set -x

bellerophon -v -objs fap.o,/usr/lib/libboost_regex.so -p ./ -r ../chimera/output/mutants/convolution.cpp/1/flap_float_report.csv -t FLAPAprx -P std.param 5
