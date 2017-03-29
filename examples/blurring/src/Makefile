OPENCV = -lopencv_core -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_videoio -lopencv_video -lopencv_videostab 

SLIBS = -lm -lpthread 

LIBS = $(OPENCV) $(SLIBS) 
 
CFLAG = -g -std=c++11 -I /usr/local/include/opencv2

test: test.cpp
	g++ $(CFLAG) $(LIBS) -o $@ $<

all: test
