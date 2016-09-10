/* Copyright [2016] <Lucas Mauro de Souza>
 * linked_queue.h
 */

#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

    #include "linked_list.h" //!< List used to store the data.
    #include "node.hpp" //!< Node used to store and handle the data.

    namespace structures {

        template<typename T>
        /*!
         * Linked Queue
         *
         * Represents a queue, a structure in which every element may only be added at the end
         * and taken out from the front. The size of the queue can always be verified.
         *
         * @see ArrayStack::enqueue()
         * @see ArrayStack::dequeue()
         * @see ArrayStack::size()
         */
        class LinkedQueue {
            public:
                /*!
                * Builds an empty queue with its default maximum size.
                */
                LinkedQueue();

                /*!
                * Destructs the queue.
                */
                ~LinkedQueue();

                /*!
                * Clears the queue.
                */
                void clear(); // limpar

                /*!
                * Inserts a given data at the end of the queue.
                */
                void enqueue(const T& data); // enfilerar

                /*!
                * Removes the element at the beginning of the queue.
                */
                T dequeue();

                /*!
                * Returns the element at the beginning of the queue.
                */
                T& front();

                /*!
                * Returns the element at the end of the queue.
                */
                T& back();

                /*!
                * Returns wether the queue is empty.
                */
                bool empty() const;

                /*!
                * Returns the size of the queue (how many elements are stored in it).
                */
                std::size_t size() const;

            private:
                structures::LinkedList<T> list; //<! The list used to store the data.
                Node<T>* tail; //<! The node at the end of the queue.
        };

    }

#include "linked_queue.ipp"
#endif