/* Copyright [2016] <Lucas Mauro de Souza>
 * doubly_linked_list.h
 */

#include <cstdint>  //!< std::size_t included
#include <stdexcept>  //!< C++ exceptions included
#include "./double_node.hpp"

#include <iostream>

#ifndef STRUCTURES_DOUBLY_LINKED_LIST_H
#define STRUCTURES_DOUBLY_LINKED_LIST_H

namespace structures {

template<typename T>
/*!
 * Doubly Linked List
 *
 * Represents a list, a structure in which elements may be added at the beginning, top or middle
 * of the structure. Elements are linked to both previous and next elements, thus, doubly linked list.
 * The number of elements stored can always be verified.
 *
 * @see LinkedList::push()
 * @see LinkedList::push_back()
 * @see LinkedList::push_front()
 * @see LinkedList::pop()
 * @see LinkedList::pop_back()
 * @see LinkedList::pop_front()
 * @see LinkedList::size()
 */
class DoublyLinkedList {
 public:
    /*!
    * Constructs an empty list.
    */
    DoublyLinkedList();

    /*!
    * Destructs an empty list.
    */
    ~DoublyLinkedList();

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
    * Returns the element at a given index.
    */
    T& at(std::size_t index);

    /*!
    * Returns the constant element at a given index.
    */
    const T& at(std::size_t index) const;

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
    * The head of the list, also first element.
    */
    DoubleNode<T>* head{nullptr};

    /*!
    * The head of the list, also first element.
    */
    std::size_t size_{0u};

    /*!
    * Verifies whether an index is fit to be used for insertion. Throws an exception if negative.
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
};

}  // namespace structures

#include "doubly_linked_list.ipp"
#endif
