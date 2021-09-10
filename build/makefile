CFLAGS = -g

ReadImage.o:	../include/image.h ../src/ReadImage.cpp
	g++ -c $(CFLAGS) ../src/ReadImage.cpp

ReadImageHeader.o:	../include/image.h ../src/ReadImageHeader.cpp
	g++ -c $(CFLAGS) ../src/ReadImageHeader.cpp

WriteImage.o:	../include/image.h ../src/WriteImage.cpp
	g++ -c $(CFLAGS) ../src/WriteImage.cpp

image.o:	../include/image.h ../src/image.cpp
	g++ -c $(CFLAGS) ../src/image.cpp

Threshold:	../include/image.h image.o ReadImage.o ReadImageHeader.o WriteImage.o \
		../src/Threshold.cpp
	g++ -o Threshold $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o ../src/Threshold.cpp
