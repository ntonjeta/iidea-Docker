#!/bin/bash

#rm -rf train.data/output/bin
#mkdir train.data/output/bin
benchmark=kmeans
for f in test.data/input/*.rgb
do
	filename=$(basename "$f")
	extension="${filename##*.}"
	filename="${filename%.*}"

	./bin/${benchmark} ${f} test.data/output/${filename}_${benchmark}.rgb
        python ./scripts/png2rgb.py png test.data/output/${filename}_${benchmark}.rgb test.data/output/${filename}_${benchmark}.png > /dev/null

	#compare -metric RMSE test.data/output/${filename}.rgb_orig.png test.data/output/${filename}_${BENCHMARK}.png null > tmp.log 2> tmp.err


	#mv hadianeh.parroto.data train.data/output/bin/${filename}_${benchmark}.bin 
done
