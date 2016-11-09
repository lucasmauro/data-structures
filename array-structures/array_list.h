/* Copyright [2016] <Lucas Mauro de Souza>
 * array_list.h
 */

/*!
 * Array List
 *
 * Represents a list, a structure in which elements may be added at the beginning, top or middle
 * of the structure. The number of elements stored can always be verified.
 *
 * @see ArrayList::push()
 * @see ArrayList::push_back()
 * @see ArrayList::push_front()
 * @see ArrayList::pop()
 * @see ArrayList::pop_back()
 * @see ArrayList::pop_front()
 * @see ArrayList::size()
 */
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>  //!< std::size_t included
#include <stdexcept>  //!< C++ exceptions included


namespace structures {

template<typename T>
/*!
* Represents a list. 
* A structure in which each element may be inserted and removed from
* any index.
*/
class ArrayList {
 public:
    /*!
    * Builds an empty list with its default maximum size.
    *
    * @see ArrayList::DEFAULT_MAX
    */
    ArrayList();

    /*!
    * Builds an empty list with given size.
    */
    explicit ArrayList(std::size_t max_size);

    /*!
    * Destructs the list andi ts elements.
    */
    ~ArrayList();

    /*!
    * Clears the list.
    */
    void clear();

    /*!
    * Inserts an element at the back of the list.
    */
    void push_back(T data);

    /*!
    * Inserts an element at the front of the list.
    */
    void push_front(T data);

    /*!
    * Inserts an element at the given index.
    */
    void insert(T data, std::size_t index);

    /*!
    * Inserts an element according to its sorting settings.
    */
    void insert_sorted(T data);

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
    void remove(T data);

    /*!
    * Returns whether the list is full or not.
    */
    bool full() const;

    /*!
    * Returns wether the list is empty or not.
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

    /*!
    * Returns the maximum size of the list.
    */
    std::size_t max_size() const;

    /*!
    * Returns the element stored at the given index, verifying the index boundaries.
    */
    T& at(std::size_t index);

    /*!
    * Returns the element stored at the given index, without verifying the index boundaries.
    */
    T& operator[](std::size_t index);

    /*!
    * Returns the constant element stored at the given index, verifying the index boundaries.
    */
    const T& at(std::size_t index) const;

    /*!
    * Returns the constant element stored at the given index, without verifying the index boundaries.
    */
    const T& operator[](std::size_t index) const;

 private:
    T* contents;  //!< The array containing the elements.
    std::size_t size_;  //!< The current size of the list.
    std::size_t max_size_;  //!< The maximum possible size of the list.

    static const auto DEFAULT_MAX = 10u;  //!< The default maximum size.

    /*!
    * Verifies whether the list is not full. Throws an exception otherwise.
    */
    void assureNotFull() {
        if (this->full())
            throw std::out_of_range("The list is full.");
    }

    /*!
    * Verifies whether the list is not empty. Throws an exception otherwise.
    */
    void assureNotEmpty() {
        if (this->empty())
            throw std::out_of_range("The list is empty.");
    }

    /*!
    * Verifies whether an index is fit to be used for exclusion. Throws an exception if negative.
    */
    void assureValidPopPosition(std::size_t index) {
        if (index >= this->max_size_ || index < 0 || index >= this->size_)
            throw std::out_of_range("Invalid position.");
    }

    /*!
    * Verifies whether an index is fit to be used for insertion. Throws an exception if negative.
    */
    void assureValidInsertPosition(std::size_t index) {
        if (index >= this->max_size_ || index < 0 || index > this->size_)
            throw std::out_of_range("Invalid position.");
    }
};

}  // namespace structures

#include "array_list.ipp"
#endif
