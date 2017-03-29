#!/bin/bash
set -x

#../../../bellerophon/build/bellerophon -l
../../../bellerophon/build/bellerophon -p ./ -objs /usr/local/lib/libopencv_imgcodecs.so,/usr/local/lib/libopencv_calib3d.so,/usr/local/lib/libopencv_core.so,/usr/local/lib/libopencv_features2d.so,/usr/local/lib/libopencv_flann.so,/usr/local/lib/libopencv_highgui.so,/usr/local/lib/libopencv_imgproc.so,/usr/local/lib/libopencv_ml.so,/usr/local/lib/libopencv_objdetect.so,/usr/local/lib/libopencv_photo.so,/usr/local/lib/libopencv_shape.so,/usr/local/lib/libopencv_stitching.so,/usr/local/lib/libopencv_superres.so,/usr/local/lib/libopencv_videoio.so,/usr/local/lib/libopencv_video.so,/usr/local/lib/libopencv_videostab.so  -r ../chimera/output/mutants/test.cpp/2/loop_report.csv -t LoopAprx -P loopex.param 1000
