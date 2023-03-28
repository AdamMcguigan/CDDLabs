#Izabela Zelek 02/02/2023
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread -Wall

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o Barrier.o
	$(CC) -o barrier Barrier.o main.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
