#===============================================================================
#
#FILE:              Makefile
#
#DESCRIPTION:       This is an all purpose Makefile
#
#COMPILER:          Linux make 

#NOTES:             Put other information here ...
#
#MODIFICATION HISTORY:
#
#Author                  Date               Version
#================================================================================
#Shawn Ray       	    2018-10-06          Version 1.0 started Assignment
#Shawn Ray       	    2021-09-10          Version 1.1 Modified objects for new project
#================================================================================
#
CC = g++
CXXFLAGS = -pedantic -std=c++14 -Wall -g
#
#Building will be done from the build directory
SRCXXDIR = ../src/
HEADXXDIR = ../include/
BUILDXXDIR = ../build/
#
#
OUTPUT 	= main
#
OBJXXFILES = main.o image.o
#ImageSampling.o ImageQuantization.o HistogramEqualization.o HistogramSpecification.o WriteImage.o ReadImage.o ReadImageHeader.o 

all: $(OUTPUT)

$(OUTPUT): $(OBJXXFILES)
	$(CC) $(CXXFLAGS) -o $(OUTPUT) $(OBJXXFILES)



main.o: $(addprefix $(SRCXXDIR), main.cpp) 
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), main.cpp) -o main.o 

#ImageSampling.o: $(addprefix $(SRCXXDIR), ImageSampling.cpp) 
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), ImageSampling.cpp) -o ImageSampling.o WriteImage.o ReadImage.o ReadImageHeader.o image.o
#
#ImageQuantization.o: $(addprefix $(SRCXXDIR), ImageQuantization.cpp)  
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), ImageQuantization.cpp) -o ImageQuantization.o
#
#HistogramEqualization.o: $(addprefix $(SRCXXDIR), HistogramEqualization.cpp) 
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), HistogramEqualization.cpp) -o HistogramEqualization.o
#
#HistogramSpecification.o: $(addprefix $(SRCXXDIR), HistogramSpecification.cpp) 
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), HistogramSpecification.cpp) -o HistogramSpecification.o
#
#WriteImage.o: $(addprefix $(SRCXXDIR), WriteImage.cpp) 
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), WriteImage.cpp) -o WriteImage.o
#
#ReadImage.o: $(addprefix $(SRCXXDIR), ReadImage.cpp) 
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), ReadImage.cpp) -o ReadImage.o
#
#ReadImageHeader.o: $(addprefix $(SRCXXDIR), ReadImageHeader.cpp) 
#	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), ReadImageHeader.cpp) -o ReadImageHeader.o

image.o: $(addprefix $(SRCXXDIR), image.cpp) 
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), image.cpp) -o image.o


clean:
#	
	rm -f $(OUTPUT)
	rm -f *.o
	reset
	@echo
	@echo
	@echo
	@echo Make clean, removed object and executable files ...
	@echo Contents in this Directory ...
	ls -lt
	@echo
	@echo
	@echo