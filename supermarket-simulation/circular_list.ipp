#ifndef STRUCTURES_CIRCULAR_LIST_IPP
#define STRUCTURES_CIRCULAR_LIST_IPP

#include "./circular_list.h"

template<typename T>
structures::CircularList<T>::CircularList() {
    this->size_ = 0;
    this->sentinel = new Node<T>();
    this->head = new Node<T>();
    this->head->next(this->sentinel);

}

template<typename T>
structures::CircularList<T>::~CircularList() {
    this->clear();
}

template<typename T>
void structures::CircularList<T>::push_back(const T& data) {
    if (this->empty()) {
           return this->push_front(data);
       }
    Node<T> *previousNode = this->sentinel;
       auto i = 0;
       auto max = this->size_-1;
       while(i < max) {
            previousNode = previousNode->next();
            i++;
        }

        Node<T> *newNode = new Node<T>(data, sentinel);
        previousNode->next(newNode);
        this->size_++;

    }

template<typename T>
void structures::CircularList<T>::push_front(const T& data) {
    Node<T>* fresh = new Node<T>(data, this->sentinel->next());
    this->sentinel->next(fresh);
    this->size_++;
}

template<typename T>
    T& CircularList<T>::at(std::size_t index) {
        this->assureNotEmpty();
        this->assureValidRetrievalPosition(index);

        auto i = 0;
        Node<T> *currentNode = this->sentinel->next();
        while (i < index) {
            currentNode = currentNode->next();
            i++;
        }

        return currentNode->data();
    }


template<typename T>
T structures::CircularList<T>::pop_front() {
    this->assureNotEmpty();

    T data = LinkedList<T>::pop_front();
    int i = 0;
    int max = this->size_ - 1;
    for (; i < max; i++) {
        sentinel = sentinel->next();
    }
    sentinel->next(this->head->next());
    this->head->next(sentinel);
    return data;
    return this->head->data();
}

template<typename T>
T structures::CircularList<T>::pop_back() {
    T data = LinkedList<T>::pop_back();
    Node<T>* sentinel = this->head;
    int max = this->size_ - 1;
    for (int i = 0; i < max; i++) {
        sentinel = sentinel->next();
    }
    sentinel->next(this->head);
    return data;
}

#endif
