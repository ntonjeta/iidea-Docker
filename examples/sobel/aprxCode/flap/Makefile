# Project: Project1

CPP  = g++
CC   = clang++


RES       = libfap.a 
OBJ       = sobel.o convolution.o rgbimage.o $(RES)
LINKOBJ   = sobel.o convolution.o rgbimage.o $(RES)

CXXINCS   = -I ../../src/include -I ../../src/boost_1_63_0
BIN  	  = sobel
CXXFLAGS  = -g -Wall -fno-use-cxa-atexit -std=c++11  $(CXXINCS) 
CFLAGS	  = -Wall -lboost_regex -fno-use-cxa-atexit  $(CXXINCS) 
LFLAGS	  = -lboost_regex
RM 	  = rm -f


.PHONY: all all-before all-after clean clean-custom

all: all-before sobel all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) -g $(LINKOBJ) -o "sobel" $(LFLAGS) $(LIBS)

sobel.o: sobel.cpp
	$(CPP) -c sobel.cpp -o sobel.o $(CXXFLAGS)

rgbimage.o: rgb_image.cpp
	$(CPP) -c rgb_image.cpp -o rgbimage.o $(CXXFLAGS)

convolution.o: convolution.cpp
	$(CPP) -c convolution.cpp -o convolution.o $(CXXFLAGS)
