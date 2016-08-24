/* Copyright [2016] <Lucas Mauro de Souza>
 * array_stack.h
 */

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

#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint> //!< std::size_t included
#include <stdexcept> //!< C++ exceptions included

namespace structures {

	template<typename T>
	class ArrayStack {
		public:
			/*!
		     * Builds an empty stack with its default size.
		     *
		     * @see ArrayStack::DEFAULT_SIZE
		     */
		    ArrayStack();

		    /*!
		    * Builds an empty stack of given maximum size.
		    *
		    * @param max The given maximum size for the stack.
		    */
		    ArrayStack(std::size_t max);

	    	/*!
	    	* Destructs the stack.
	    	*/
		    ~ArrayStack();

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

		    /*
		    * Retrieves the data at the top of the list without removing it.
		    */
		    T& top();

			/*
			* Clears the stack.
			*/
		    void clear();

		    /*
		    * Returns how many elements are currently stacked.
		    */
		    std::size_t size();

		    /*
		    * Returns the stack's maximum possible size.
		    */
		    std::size_t max_size();

		    /*
		    * Returns whether the stack is empty or not.
		    */
		    bool empty();

			/*
		    * Returns whether the full is empty or not.
		    */
		    bool full();

		private:
		    T* contents; //!< The stack in which the elements shall be kept.
		    int top_; //!< The current size of the stack, or how high is its top.
		    std::size_t max_size_; //!< The maximum size of the given stack.

		    const static auto DEFAULT_SIZE = 10u; //!< The default maximum size of the stack, in case a size is not given at its construction.
		    
		    void assure_that_stack_is_not_empty() {
		        if(empty()) {
		            throw std::out_of_range("The stack is empty.");
		        }
		    }
		    
		    void assure_that_stack_is_not_full() {
		        if(full()) {
		            throw std::out_of_range("The stack is full.");
		        }
		    }
	};

}

#include "array_stack.cpp"
#endif
