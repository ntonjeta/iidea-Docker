#!/bin/bash
set -x


../../../iideaa/build/iideaa -debug-only=iideaa -p ./ -no-dominance -flap-report ../chimera/output/mutants/test.cpp/1/loop_report.csv 50000
