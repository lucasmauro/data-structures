/* Copyright [2016] <Lucas Mauro de Souza>
 * doubly_linked_list.ipp
 */

#ifndef STRUCTURES_DOUBLY_LINKED_LIST_IPP
#define STRUCTURES_DOUBLY_LINKED_LIST_IPP

    #include "doubly_linked_list.h"

    using namespace structures;

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList() {
        this->head = nullptr;
    }

    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() {
        this->clear();
    }

    template<typename T>
    void DoublyLinkedList<T>::clear() {
        while (!this->size_ == 0) {
            this->pop_front();
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::push_back(const T& data) {
        if (this->size_ == 0)
            return this->push_front(data);
        
        DoubleNode<T>* temp = this->head;
        for (auto i = 0; i < this->size_-1; i++) {
            temp = temp->next();
        }
        DoubleNode<T> *fresh = new DoubleNode<T>(data, temp, nullptr);
        temp->next(fresh);
        this->size_++;
    }

    template<typename T>
    void DoublyLinkedList<T>::push_front(const T& data) {
        this->head = new DoubleNode<T>(data, nullptr, this->head);
        
        if (this->head->next() != nullptr)
            this->head->next()->prev(this->head);

        this->size_++;
    }

    template<typename T>
    void DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
        this->assureValidInsertionPosition(index);
        if (index == 0 || this->empty())
            return this->push_front(data);

        index--;

        DoubleNode<T> *prev = this->head;
        for (auto i = 0; i < index; i++) {
            prev = prev->next();
        }
        DoubleNode<T>* fresh = new DoubleNode<T>(data, prev, prev->next());
        if (fresh->next() != nullptr)
            fresh->next()->prev(fresh);
        prev->next(fresh);
        this->size_++;
    }

    template<typename T>
    void DoublyLinkedList<T>::insert_sorted(const T& data) {
        if (this->size_ == 0)
            return this->push_front(data);

        DoubleNode<T>* temp = this->head;
        auto i = 0;
        auto max = this->size_-1;

        while (i < max && data > temp->data()) {
            temp = temp->next();
            i++;
        }

        if(data > temp->data())
            return this->insert(data, i+1);
        return this->insert(data, i);
    }

    template<typename T>
    T DoublyLinkedList<T>::pop(std::size_t index) {
        this->assureNotEmpty();
        this->assureValidRetrievalPosition(index);
        if (this->size_ == 1)
            return this->pop_front();

        index--;
        DoubleNode<T>* temp = this->head;
        for (auto i = 0; i < index; i++) {
            temp = temp->next();
        }
        T data = temp->next()->data();
        DoubleNode<T>* newNext = temp->next()->next();
        delete temp->next();
        temp->next(newNext);
        this->size_--;
        return data;
    }

    template<typename T>
    T DoublyLinkedList<T>::pop_back() {
        this->assureNotEmpty();
        
        DoubleNode<T>* temp = this->head;
        if (this->size_ == 1)
            return this->pop_front();

        for (auto i = 0; i < this->size_-2; i++) {
            temp = temp->next();
        }
        T data = temp->next()->data();
        delete temp->next();
        temp->next(nullptr);
        this->size_--;
        return data;
    }

    template<typename T>
    T DoublyLinkedList<T>::pop_front() {
        this->assureNotEmpty();

        DoubleNode<T>* temp = this->head;
        T data = temp->data();
        this->head = temp->next();
        if (this->head != nullptr) {
            this->head->prev(nullptr);
        }
        this->size_--;
        return data;
    }

    template<typename T>
    void DoublyLinkedList<T>::remove(const T& data) {
        auto index = this->find(data);
        if (index == this->size_)
            throw std::out_of_range("Element not found.");
        this->pop(index);
    }

    template<typename T>
    bool DoublyLinkedList<T>::empty() const {
        return this->size_ == 0;
    }

    template<typename T>
    bool DoublyLinkedList<T>::contains(const T& data) const {
        return this->find(data) != this->size_;
    }

    template<typename T>
    T& DoublyLinkedList<T>::at(std::size_t index) {
        this->assureValidRetrievalPosition(index);
        DoubleNode<T>* temp = this->head;
        for (auto i = 0; i < index; i++) {
            temp = temp->next();
        }
        return temp->data();
    }

    template<typename T>
    const T& DoublyLinkedList<T>::at(std::size_t index) const {
        return this->at(index);
    }

    template<typename T>
    std::size_t DoublyLinkedList<T>::find(const T& data) const {
        if (this->empty())
            throw std::out_of_range("The list is empty.");

        auto i = 0;
        DoubleNode<T> *currentNode = this->head;
        while (i < this->size_) {
            if (currentNode->data() == data)
                return i;
            currentNode = currentNode->next();
            i++;
        }

        return this->size_;
    }

    template<typename T>
    std::size_t DoublyLinkedList<T>::size() const {
        return this->size_;
    }

#endif
