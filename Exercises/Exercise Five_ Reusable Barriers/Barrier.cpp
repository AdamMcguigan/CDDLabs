/*
    Adam Mcguigan 14/02/2023
    GNU GENERAL PUBLIC LICENSE
    Version 3, 29 June 2007
*/

// Code:
#include "Barrier.h"
#include <iostream>

Barrier::Barrier(int numThreads)
{
    this->numThreads = numThreads;
    count = 0;
}

/// Inspiration taken from the concurrency slides
/*! \class Barrier
    \brief A Barrier Implementation
    stops all semaphores once the first task is finished, it resumes once all semaphores have reached the same point
    Information taken from the concurrency slides.
*/
void Barrier::wait()
{
    mutex->Wait();
    count += 1;
    
    if(count == numThreads)
    {
        secondBarrier->Wait();
        firstBarrier->Signal();
    }
    
    mutex->Signal();

    firstBarrier->Wait();
    firstBarrier->Signal();

    mutex->Wait();
    count -= 1;
    
    if(count == 0)
    {
        firstBarrier->Wait();
        secondBarrier->Signal();
    }
    
    mutex->Signal();
    secondBarrier->Wait();
    secondBarrier->Signal();
}

Barrier::~Barrier()
{
    delete mutex;
    delete firstBarrier;
    delete secondBarrier;
}
//
// Barrier.cpp ends here
