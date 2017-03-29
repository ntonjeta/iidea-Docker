#!/bin/bash
set -x

../../../iideaa/build/iideaa -no-dominance -p ./ -flap-report ../chimera/output/mutants/test.cpp/2/loop_report.csv 10

#-debug-only=iideaa
