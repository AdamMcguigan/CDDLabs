/*
    Adam Mcguigan 14/02/2023
    GNU GENERAL PUBLIC LICENSE
    Version 3, 29 June 2007
*/

/* Code: */
#ifndef BARRIER_H
#define BARRIER_H
#include "Semaphore.h"

class Barrier {
    int numThreads;
    int count;
    Semaphore* mutex = new Semaphore(1);
    Semaphore* barrier = new Semaphore(0);
    Semaphore* barrier2 = new Semaphore(1);
public:
    Barrier(int numThreads);
    virtual ~Barrier();
    void wait();
};

#endif

/* Barrier.h ends here */
