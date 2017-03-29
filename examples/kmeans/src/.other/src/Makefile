# Project: Project1

CPP  = clang++
CC   = clang
#WINDRES = windres.exe
RES  = 
OBJ  = main.o segmentation.o $(RES)
LINKOBJ  = main.o segmentation.o $(RES)
#LIBS =  -L"C:/programmi/Dev-Cpp/lib"  
#INCS =  -I"C:/programmi/Dev-Cpp/include" 
#CXXINCS =  -I"C:/programmi/Dev-Cpp/lib/gcc/mingw32/3.4.2/include"  -I"C:/programmi/Dev-Cpp/include/c++/3.4.2/backward"  -I"C:/programmi/Dev-Cpp/include/c++/3.4.2/mingw32"  -I"C:/programmi/Dev-Cpp/include/c++/3.4.2"  -I"C:/programmi/Dev-Cpp/include" 
BIN  = kmean
CXXFLAGS = -fno-use-cxa-atexit #$(CXXINCS)  
CFLAGS =  -fno-use-cxa-atexit#$(INCS)  
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before kmean all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "kmean" $(LIBS)


main.o: main.c
	$(CPP) -c main.c -o main.o $(CXXFLAGS)

#rgbimage.o: rgbimage.c
	#$(CPP) -c rgbimage.c -o rgbimage.o $(CXXFLAGS)

#distance.o: distance.c
	#$(CPP) -c distance.c -o distance.o $(CXXFLAGS)

segmentation.o: segmentation.c
	$(CPP) -c segmentation.c -o segmentation.o $(CXXFLAGS)
