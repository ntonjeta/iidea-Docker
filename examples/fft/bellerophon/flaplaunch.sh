#!/bin/bash
set -x

bellerophon -v -objs fap.o -p ./ -r ../chimera/output/mutants/segmentation.cpp/1/flap_float_report.csv -t FLAPAprx -P loopex.param 10000
