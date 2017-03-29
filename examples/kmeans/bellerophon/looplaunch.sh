#!/bin/bash
set -x

bellerophon -p ./ -r ../chimera/output/mutants/segmentation.cpp/2/loop_report.csv -t LoopAprx -P loopex.param 100
