#!/bin/bash

iideaa_exec="iideaa"
target_exec="bessel"

set -x
# Remove old files
#rm outs*.txt
#rm dbgs*.txt
#rm *_oracle.txt

set -e
# Create the oracle
#../build/${target_exec}

# Launch iideaa
${iideaa_exec} -debug-only=iideaa -p ../build/ -flap-report ../chimera/flap_float_report.csv -objs ../flap/flap.o 10e-12 > outs_12_d.txt 2> dbgs_12_d.txt &

${iideaa_exec} -debug-only=iideaa -p ../build/ -flap-report ../chimera/flap_float_report.csv -objs ../flap/flap.o -no-dominance 10e-12 > outs_12_no_d.txt 2> dbgs_12_no_d.txt &

#${iideaa_exec} -debug-only=iideaa -p ../build/ -flap-report ../chimera/flap_float_report.csv -objs ../flap/flap.o 10e-8 > outs_8_d.txt 2> dbgs_8_d.txt &

#${iideaa_exec} -debug-only=iideaa -p ../build/ -flap-report ../chimera/flap_float_report.csv -objs ../flap/flap.o -no-dominance 10e-8 > outs_8_no_d.txt 2> dbgs_8_no_d.txt &

set +x
