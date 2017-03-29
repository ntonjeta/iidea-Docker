#!/bin/bash
set -x
# Clean build
rm -rf ./build/*
#rm -rf ./chimera/output
set +x
target="./src/bessel.cpp"
# Restore original file
if [ -e ${target}.ori ]; then
  # Restore the original file
  mv ${target}.ori ${target}
  echo "Restored original file"
fi
