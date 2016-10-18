#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>  //!< std::size_t included
#include <stdexcept>  //!< C++ exceptions included
#include "./linked_list.h"  //!< Base class

namespace structures {

template<typename T>
/*!
 * Circular List
 *
 * Represents a circular list, a structure that has no beginning nor an end.
 * Elements may be stored and removed in and from anywhere.
 * The number of elements stored can always be verified. 
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
class CircularList : public LinkedList<T> {
 public:
    /*!
    * Constructs an empty list.
    */
    CircularList();

    /*!
    * Destructs the list.
    */
    ~CircularList();

    /*!
    * Inserts an element at the front of the list.
    */
    void push_front(const T& data);

    /*!
    * Removes the element at the front of the list.
    */
    T pop_front();

    /*!
    * Removes the element at the top of the list.
    */
    T pop_back();
};

}  // namespace structures

#include "circular_list.ipp"
#endif
