/*
    Adam Mcguigan 02/02/2023
    GNU GENERAL PUBLIC LICENSE
    Version 3, 29 June 2007
*/
#include <vector>
#include "Semaphore.h"

/*! 
 * \brief A thread-safe buffer
 */
template<typename T>
class SafeBuffer
{
    public:
        SafeBuffer(int t_size);

        /*!
         * \brief Put item in the buffer if no other thread is getting item fron it
         */ 
        void put(T item);
        
        /*!
         * \brief Get an item from the buffer if no other thead is putting item in it
         */ 
        T get();

    private:
        int m_size;
        std::vector<char> m_buffer;

        Semaphore m_spaces;
        Semaphore m_mutex;
        Semaphore m_items;
};


/* SafeBuffer.h ends here */

