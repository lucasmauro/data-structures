#include "linked_stack.h"

#ifndef STRUCTURES_LINKED_STACK_IPP
#define STRUCTURES_LINKED_STACK_IPP

    using namespace structures;

    template<typename T>
    LinkedStack<T>::LinkedStack() {
    }

    template<typename T>
    LinkedStack<T>::~LinkedStack() {
        this->list.~LinkedList();
    }

    template<typename T>
    void LinkedStack<T>::clear() {
        this->list.clear();
    }

    template<typename T>
    void LinkedStack<T>::push(const T& data) {
        this->list.push_front(data);
    }

    template<typename T>
    T LinkedStack<T>::pop() {
        return this->list.pop_front();
    }

    template<typename T>
    T& LinkedStack<T>::top() {
        return this->list.at(0);
    }

    template<typename T>
    bool LinkedStack<T>::empty() const {
        return this->list.empty();
    }

    template<typename T>
    std::size_t LinkedStack<T>::size() const {
        return this->list.size();
    }

#endif