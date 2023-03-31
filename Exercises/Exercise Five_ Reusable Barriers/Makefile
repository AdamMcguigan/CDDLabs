#Adam Mcguigan 02/02/2023
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

OBJECTS = Semaphore.o main.o Barrier.o

SOURCES = Semaphore.cpp main.cpp Barrier.cpp
HEADERS = Semaphore.h Barrier.h

OUTPUTS = main.out

CC=g++
CFLAGS= -std=c++11 -pthread -Wall
LFLAGS= 

#SIMPLE:
#	$(CC) $(CFLAGS) $(SOURCES) $(HEADERS) $(OBJECTS)
# -g is for debugging
all: $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(OUTPUTS) $(LFLAGS)
	make CLEAN #run clean
CLEAN:
	rm -f $(OBJECTS) #removes all object by force
