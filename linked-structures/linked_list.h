/* Copyright [2016] <Lucas Mauro de Souza>
 * linked_list.h
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
            * Builds an empty list.
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
            class Node { // Elemento
            public:
                Node(const T& data):
                    data_{data}
                {}

                Node(const T& data, Node* next):
                    data_{data},
                    next_{next}
                {}

                T& data() { // getter: dado
                    return data_;
                }

                const T& data() const { // getter const: dado
                    return data_;
                }

                Node* next() { // getter: próximo
                    return next_;
                }

                const Node* next() const { // getter const: próximo
                    return next_;
                }

                void next(Node* node) { // setter: próximo
                    next_ = node;
                }
            private:
                T data_;
                Node* next_{nullptr};
            };

            Node* end() { // último nodo da lista
                auto it = head;
                for (auto i = 1u; i < size(); ++i) {
                    it = it->next();
                }
                return it;
            }

            Node* head{nullptr};
            std::size_t size_{0u};
    };

}

#include "linked_list.ipp"
#endif

