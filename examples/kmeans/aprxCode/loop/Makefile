# Project: Project1

CPP  = clang++
CC   = clang++
#WINDRES = windres.exe
RES  =  
OBJ  = main.o segmentation.o $(RES)
LINKOBJ  = main.o segmentation.o $(RES)
BIN  = kmean
CXXFLAGS = -fno-use-cxa-atexit -I ./include -std=c++11  #$(CXXINCS)  
CFLAGS =  -fno-use-cxa-atexit -I./include#$(INCS)  
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before kmean all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "kmean" $(LIBS)


main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

#rgbimage.o: rgbimage.c
	#$(CPP) -c rgbimage.c -o rgbimage.o $(CXXFLAGS)

#distance.o: distance.c
	#$(CPP) -c distance.c -o distance.o $(CXXFLAGS)

segmentation.o: segmentation.cpp
	$(CPP) -c segmentation.cpp -o segmentation.o $(CXXFLAGS)
