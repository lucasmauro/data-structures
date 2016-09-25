/* Copyright [2016] <Lucas Mauro de Souza>
 * doubly_circular_list.h
 */

#ifndef STRUCTURES_DOUBLY_CIRCULAR_LIST_H
#define STRUCTURES_DOUBLY_CIRCULAR_LIST_H

#include "./doubly_linked_list.h"  //<! Base class
#include <cstdint>  //!< std::size_t included
#include <stdexcept>  //!< C++ exceptions included

namespace structures {

template<typename T>
/*!
 * Doubly Circular List
 *
 * Represents a doubly circular list, a structure that has no beginning nor an end.
 * Elements may be stored and removed in and from anywhere.
 * The number of elements stored can always be verified. 
 * Elements on the list are doubly linked between each other.
 *
 * @see LinkedList::push()
 * @see LinkedList::push_back()
 * @see LinkedList::push_front()
 * @see LinkedList::pop()
 * @see LinkedList::pop_back()
 * @see LinkedList::pop_front()
 * @see LinkedList::size()
 */
class DoublyCircularList: public DoublyLinkedList<T> {
 public:
    /*!
    * Constructs an empty list.
    */
	DoublyCircularList();

	/*!
    * Destructs the list.
    */
	~DoublyCircularList();

    /*!
    * Inserts an element at the end of the list.
    */
	void push_back(const T& data);

	/*!
    * Inserts an element at the front of the list.
    */
	void push_front(const T& data);

    /*!
    * Removes the element at the top of the list.
    */
	T pop_back();

	/*!
    * Removes the element at the front of the list.
    */
	T pop_front();
};
}  // namespace structures
#include "./doubly_circular_list.ipp"
#endif
