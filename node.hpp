/* Copyright [2016] <Lucas Mauro de Souza>
 * node.hpp
 */

#ifndef LINKED_NODE_HPP
#define LINKED_NODE_HPP

template<typename T>
/*!
 * Node
 *
 * A placeholder for the data within each list element.
 *
 */
class Node {
 public:
    /*!
    * Constructs a new Node with given data.
    *
    * @param data The given data to be stored.
    */
    explicit Node(const T& data):
        data_{data}
    {}

     /*!
    * Constructs a new Node with given data.
    *
    * @param data The given data to be stored.
    */
    Node():
        next_{nullptr}
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
    T data_;  //<! The element's data stored within the node
    Node* next_{nullptr};  //<! The next linked element.
};

#endif
