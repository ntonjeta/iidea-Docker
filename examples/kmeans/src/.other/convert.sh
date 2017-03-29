#!/bin/bash

#rm -rf train.data/output/bin
#mkdir train.data/output/bin
benchmark=kmeans
for f in test.data/input/*.rgb
do
	filename=$(basename "$f")
	extension="${filename##*.}"
	filename="${filename%.*}"

	#./bin/${benchmark} ${f} test.data/output/${filename}_${benchmark}.rgb
        python ./scripts/png2rgb.py png ${f} ${f}_${benchmark}.png > /dev/null
	#mv hadianeh.parroto.data train.data/output/bin/${filename}_${benchmark}.bin 
done
