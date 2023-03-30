#Adam Mcguigan 02/02/2023
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

OBJS = Semaphore.o main.o
SOURCE = Semaphore.cpp main.cpp
HEADER = Semaphore.h
OUT = main.out
CC=g++
LFLAGS = 

ALL: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS)

#this is customary and just deletes all .o files
CLEAN:
	rm -f $(OBJS)
