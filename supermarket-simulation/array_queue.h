/* Copyright [2016] <Lucas Mauro de Souza>
 * array_queue.h
 */

/*!
 * Array Queue
 *
 * Represents a queue, a structure in which every element may only be added at the end
 * and taken out from the front. The size of the queue can always be verified.
 *
 * @see ArrayStack::enqueue()
 * @see ArrayStack::dequeue()
 * @see ArrayStack::size()
 */

#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> //!< std::size_t included
#include <stdexcept> //!< C++ exceptions included

namespace structures {

    template<typename T>
    class ArrayQueue {
        public:
            /*!
            * Builds an empty queue with its default maximum size.
            *
            * @see ArrayQueue::DEFAULT_SIZE
            */
            ArrayQueue();

            /*!
            * Builds an empty queue with a given maximum size.
            *
            * @param max The given maximum size for the queue.
            */
            ArrayQueue(std::size_t max);

            /*!
            * Destructs the queue
            */
            ~ArrayQueue();

            /*!
            * Inserts data at the end of the queue.
            *
            * @param data The given data to be inserted at the end of the queue.
            */
            void enqueue(const T& data);

            /*!
            * Removes the first element of the queue, if the queue is not empty.
            */
            T dequeue();

            /*!
            * Returns the last element of the queue.
            */
            T& back();

            /*!
            * Returns the first element of the queue.
            */
            T& front();

            /*!
            * Clears the queue.
            */
            void clear();

            /*!
            * Returns how many elements are stored in the queue.
            */
            std::size_t size();

            /*!
            * Returns the maximum possible size of the queue.
            */
            std::size_t max_size();

            /*!
            * Returns whether the queue is empty or not.
            */
            bool empty();

            /*!
            * Returns whether the queue is full or not.
            */
            bool full();

        private:
            T* contents; //!< The queue in which the elements shall be kept.
            std::size_t size_; //!< The current size of the stack, or how high is its top.
            std::size_t max_size_; //!< The maximum size of the given stack.

            const static auto DEFAULT_SIZE = 10u; //!< The default maximum size of the stack, in case a size is not given at its construction.

            /*
            * Verifies whether the queue is full and throws an exception if so.
            */
            void assure_that_queue_is_not_full() {
                if(full()) {
                    throw std::out_of_range("The queue is full.");
                }
            }

            /*
            * Verifies whether the queue is empty and throws an exception if so.
            */
            void assure_that_queue_is_not_empty() {
                if(empty()) {
                    throw std::out_of_range("The queue is empty.");
                }
            }
        };

}

#include "array_queue.ipp"
#endif
