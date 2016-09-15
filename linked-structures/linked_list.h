/* Copyright [2016] <Lucas Mauro de Souza>
 * linked_list.h
 */

#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>  //!< std::size_t included
#include <stdexcept>  //!< C++ exceptions included
#include "node.hpp"  //!< Node used to store and handle the data.

namespace structures {

template<typename T>
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

    /*!
    * Returns the element at a given index.
    */
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

 protected:
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
    * Returns the last linked element.
    */
    Node<T>* end() {
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    /*!
    * The head of the list, also first element.
    */
    Node<T>* head{nullptr};

    /*!
    * The head of the list, also first element.
    */
    std::size_t size_{0u};
};

}  // namespace structures

#include "linked_list.ipp"
#endif

