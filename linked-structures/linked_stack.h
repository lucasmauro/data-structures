/* Copyright [2016] <Lucas Mauro de Souza>
 * linked_stack.h
 */

#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include "./linked_list.h"  //!< List used to store the data.

namespace structures {

template<typename T>
/*!
 * Array Stack
 *
 * Represents a stack, a structure in which every element may only be added on the top,
 * and only retrieved from the top. The size of the stack can always be verified.
 * 
 * @see ArrayStack::push()
 * @see ArrayStack::pop()
 * @see ArrayStack::top()
 */
class LinkedStack {
 public:
    /*!
     * Builds an empty stack.
     */
    LinkedStack();

    /*!
    * Destructs the stack.
    */
    ~LinkedStack();

    /*!
    * Clears the stack.
    */
    void clear();

    /*!
    * Pushes (or adds) data to the top of the stack, if the stack is not full.
    *
    * @param data The given data to be stacked.
    */
    void push(const T& data);

    /*!
    * Removes data from the top of the stack, if the stack is not empty.
    */
    T pop();

    /*!
    * Retrieves the data at the top of the list without removing it.
    */
    T& top();

    /*!
    * Returns whether the stack is empty or not.
    */
    bool empty() const;

    /*!
    * Returns how many elements are currently stacked.
    */
    std::size_t size() const;

 private:
    structures::LinkedList<T> list;  //<! The list used to store the data.
};

}  // namespace structures

#include "linked_stack.ipp"
#endif
