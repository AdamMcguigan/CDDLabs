/*
	Adam Mcguigan 02/02/2023
		GNU GENERAL PUBLIC LICENSE
	Version 3, 29 June 2007
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \class Signal
	\brief An Implementation of a Rendezvous using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! First semaphore signals
	Then the Second semaphore waits
	Second text will show up once both first texts in both functions are shown*/
void taskOne(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore>  secondSem, int delay) {
	std::this_thread::sleep_for(std::chrono::seconds(delay));
	std::cout << "Task One has arrived! " << std::endl;
	//THIS IS THE RENDEZVOUS POINT!
	firstSem->Signal();
	secondSem->Wait();
	std::cout << "Task One has left!" << std::endl;
}
/*! Second semaphore signals
	Then the first semaphore waits
	Second text will show up once both first texts in both functions are shown*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay) {
	std::this_thread::sleep_for(std::chrono::seconds(delay));
	std::cout << "Task Two has arrived " << std::endl;
	secondSem->Signal();
	firstSem->Wait();
	std::cout << "Task Two has left " << std::endl;
}

/*!
    \brief implementation of main
*/
int main(void) {
	std::thread threadOne, threadTwo;
	std::shared_ptr<Semaphore> sem1(new Semaphore);
	std::shared_ptr<Semaphore> sem2(new Semaphore);
	int taskOneDelay = 5;
	int taskTwoDelay = 1;
	/**< Launch the threads  */
	threadOne = std::thread(taskTwo, sem1, sem2, taskTwoDelay);
	threadTwo = std::thread(taskOne, sem1, sem2, taskOneDelay);
	std::cout << "Launched from the main\n";
	threadOne.join();
	threadTwo.join();
	return 0;
}
