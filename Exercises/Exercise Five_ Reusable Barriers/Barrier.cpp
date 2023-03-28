/*
    Adam Mcguigan 14/02/2023
    GNU GENERAL PUBLIC LICENSE
    Version 3, 29 June 2007
*/

// Code:
#include "Semaphore.h"
#include "Barrier.h"
Barrier::Barrier(int numThreads)
{
    this->numThreads = numThreads;
    count = 0;
}

// Stops all semaphores once the first task is finished, it then resumes once all semaphores have reached the same point
void Barrier::wait()
{
    mutex->Wait();
    count += 1;
    if (count == numThreads)
    {
        std::cout << std::endl << "Last" << std::endl;
        barrier2->Wait();
        barrier->Signal();
    }
    mutex->Signal();

    barrier->Wait();
    barrier->Signal();

    mutex->Wait();
    count -= 1;
    if (count == 0)
    {
        barrier->Wait();
        barrier2->Signal();
    }
    mutex->Signal();

    barrier2->Wait();
    barrier2->Signal();
}

Barrier::~Barrier()
{
    delete mutex;
    delete barrier;
    delete barrier2;
}

// 
// Barrier.cpp ends here
