#Adam Mcguigan 14/03/2023
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

# Name of the final executable file
TARGET_EXEC := rendezvous

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: Semaphore.o main.o 
	$(CC) -o ${TARGET_EXEC} Semaphore.o main.o $(CFLAGS)

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
