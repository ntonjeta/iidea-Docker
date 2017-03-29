#!/bin/bash
set -e
target_name="bessel.cpp"
target="../src/${target_name}"

if [ -e ${target}.ori ]; then
  # Restore the original file
  mv ${target}.ori ${target}
  echo "Restored original file"
fi

#rm -rf output/
# To launch, remote output dir
if [ ! -d "output" ]; then
  set -x
  clang-chimera -p ../build/ -fun-op conf.csv -generate-mutants -o output ${target}
  set +x
fi

# Copy the mutated file
if [ ! -e ${target}.ori ]; then
  # Rename the original file
  mv ${target} ${target}.ori
  echo "Renamed $target in ${target}.ori"
fi

cp ./output/mutants/${target_name}/1/${target_name} ../src
echo "Copied mutated file"
cp ./output/mutants/${target_name}/1/flap_float_report.csv ./
echo "Copied flap report"
