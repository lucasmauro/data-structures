/* Copyright [2016] <Lucas Mauro de Souza>
 * array_list.h
 */

/*!
 * Linked List
 *
 * Represents a list, a structure in which elements may be added at the beginning, top or middle
 * of the structure. The number of elements stored can always be verified. 
 * Elements on the list are linked between each other.
 *
 * @see LinkedList::push()
 * @see LinkedList::push_back()
 * @see LinkedList::push_front()
 * @see LinkedList::pop()
 * @see LinkedList::pop_back()
 * @see LinkedList::pop_front()
 * @see LinkedList::size()
 */

#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

    template<typename T>
    class LinkedList {
        public:
            /*!
            * Constructs an empty list.
            */
            LinkedList();

            /*!
            * Destructs the list andi ts elements.
            */
            ~LinkedList();

            /*!
            * Clears the list.
            */
            void clear();

            /*!
            * Inserts an element at the back of the list.
            */
            void push_back(const T& data);

            /*!
            * Inserts an element at the front of the list.
            */
            void push_front(const T& data);

            /*!
            * Inserts an element at the given index.
            */
            void insert(const T& data, std::size_t index);

            /*!
            * Inserts an element according to its sorting settings.
            */
            void insert_sorted(const T& data);

            
            T& at(std::size_t index);

            /*!
            * Removes an element at the given index.
            */
            T pop(std::size_t index);

            /*!
            * Removes the element at the top of the list.
            */
            T pop_back();

            /*!
            * Removes the element at the front of the list.
            */
            T pop_front();

            /*!
            * Removes a given element.
            */
            void remove(const T& data);

            /*!
            * Returns whether the list is full or not.
            */
            bool empty() const;

            /*!
            * Returns whether the list contains an element or not.
            */
            bool contains(const T& data) const;

            /*!
            * Returns the position of a given element.
            */
            std::size_t find(const T& data) const;

            /*!
            * Returns the size of the list.
            */
            std::size_t size() const;

        private:
            
            /*!
            * Verifies whether the list is not empty. Throws an exception otherwise.
            */
            void assureNotEmpty() {
                if (this->empty())
                    throw std::out_of_range("The list is empty.");
            }
            
            /*!
            * Verifies whether an index is fit to be used for retrieving an element. Throws an exception if negative.
            */
            void assureValidRetrievalPosition(std::size_t index) {
                if (index < 0 || index >= this->size_)
                    throw std::out_of_range("Invalid position.");
            }
            
            /*!
            * Verifies whether an index is fit to be used for insertion. Throws an exception if negative.
            */
            void assureValidInsertionPosition(std::size_t index) {
                if (index < 0 || index > this->size_)
                    throw std::out_of_range("Invalid position.");
            }

            /*!
             * Node
             *
             * A placeholder for the data within each list element.
             *
             */
            class Node { // Elemento
            public:
                /*!
                * Constructs a new Node with given data.
                *
                * @param data The given data to be stored.
                */
                Node(const T& data):
                    data_{data}
                {}

                /*!
                * Constructs a new Node with given data and next element.
                *
                * @param data The given data to be stored.
                * @param next Element to be linked as next element.
                */
                Node(const T& data, Node* next):
                    data_{data},
                    next_{next}
                {}

                /*!
                * Returns the element's data stored in the node.
                */
                T& data() {
                    return data_;
                }

                /*!
                * Returns the constant element's data stored in the node.
                */
                const T& data() const {
                    return data_;
                }

                /*!
                * Returns the next linked element.
                */
                Node* next() {
                    return next_;
                }

                /*!
                * Returns the constant next linked element.
                */
                const Node* next() const {
                    return next_;
                }

                /*!
                * Sets the next linked element.
                */
                void next(Node* node) {
                    next_ = node;
                }
            private:
                T data_; //<! The element's data stored within the node
                Node* next_{nullptr}; //<! The next linked element. Default: nullptr.
            };

            /*!
            * Returns the last linked element.
            */
            Node* end() {
                auto it = head;
                for (auto i = 1u; i < size(); ++i) {
                    it = it->next();
                }
                return it;
            }

            Node* head{nullptr}; //<! The head of the list, pointing to the first element. Default: nullptr.
            std::size_t size_{0u}; //<! The size of the list. Default: 0u.
    };

}

#include "linked_list.ipp"
#endif

