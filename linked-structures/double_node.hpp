/* Copyright [2016] <Lucas Mauro de Souza>
 * double_node.hpp
 */

#ifndef DOUBLY_LINKED_NODE_HPP
#define DOUBLY_LINKED_NODE_HPP

template<typename T>
/*!
 * Double Node
 * A placeholder for the data within each list element.
 */
class DoubleNode {
 public:
    /*!
    * Constructs a new double node with given data.
    *
    * @param data The given data to be stored.
    */
    explicit DoubleNode(const T& data):
        data_{data}
    {}

    /*!
    * Constructs a new double nodeode with given data and next element.
    *
    * @param data The given data to be stored.
    * @param previous Element to be linked as previous element.
    * @param next Element to be linked as next element.
    */
    explicit DoubleNode(const T& data, DoubleNode* prev, DoubleNode* next):
        data_{data},
        prev_{prev},
        next_{next}
    {}

    /*!
    * Returns the previous linked element.
    */
    DoubleNode* prev() {
        return prev_;
    }

    /*!
    * Returns the constant previous linked element.
    */
    const DoubleNode* prev() const {
        return prev_;
    }

    /*!
    * Sets the previous linked element.
    */
    void prev(DoubleNode* node) {
        prev_ = node;
    }

    /*!
    * Returns the next linked element.
    */
    DoubleNode* next() {
        return next_;
    }

    /*!
    * Returns the constant next linked element.
    */
    const DoubleNode* next() const {
        return next_;
    }

    /*!
    * Sets the next linked element.
    */
    void next(DoubleNode* node) {
        next_ = node;
    }

    /*!
    * Returns the constant element's data stored in the node.
    */
    const T& data() const {
        return data_;
    }

    /*!
    * Returns the element's data stored in the node.
    */
    T& data() {
        return data_;
    }

 private:
    T data_;  //<! The element's data stored within the node
    DoubleNode* prev_{nullptr};  //<! The previous linked element.
    DoubleNode* next_{nullptr};  //<! The next linked element.
};

#endif
