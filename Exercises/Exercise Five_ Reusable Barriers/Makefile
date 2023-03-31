#Adam Mcguigan 31/03/2023
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

# Name of the build file
TARGET_EXEC := reusable_barrier

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Link .objects files, and ask make to compile them if they are in the list
ALL: Barrier.o Semaphore.o main.o 
	$(CC) -o ${TARGET_EXEC} Barrier.o Semaphore.o main.o $(CFLAGS) $(DEBUGFLAGS)

# Debug rule to compile the program to use gdb to debug it
DEBUG: DEBUGFLAGS = -DDEBUG -Wall
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
