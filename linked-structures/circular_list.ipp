#ifndef STRUCTURES_CIRCULAR_LIST_IPP
#define STRUCTURES_CIRCULAR_LIST_IPP

#include "./circular_list.h"

template<typename T>
structures::CircularList<T>::CircularList() {
    this->head = new Node<T>(0, nullptr);
    this->head->next(this->head);
    this->size_ = 0;
}

template<typename T>
structures::CircularList<T>::~CircularList() {
    this->clear();
}

template<typename T>
void structures::CircularList<T>::push_front(const T& data) {
    Node<T>* fresh = new Node<T>(data, this->head);
    this->head = fresh;
    this->size_++;
    Node<T> *sentinel = this->head;
    auto max = this->size_;

    for (auto i = 0; i < max; i++) {
        sentinel = sentinel->next();
    }

    sentinel->next(this->head);
}

template<typename T>
T structures::CircularList<T>::pop_front() {
    this->assureNotEmpty();

    T data = LinkedList<T>::pop_front();
    Node<T>* sentinel = this->head;
    int i = 0;
    int max = this->size_ - 1;
    for (; i < max; i++) {
        sentinel = sentinel->next();
    }
    sentinel->next(this->head);
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
