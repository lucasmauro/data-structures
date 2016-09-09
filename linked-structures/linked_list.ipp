#ifndef STRUCTURES_LINKED_LIST_IPP
#define STRUCTURES_LINKED_LIST_IPP
    
    #include "linked_list.h"

    using namespace structures;

    template<typename T>
    LinkedList<T>::LinkedList() {
        this->size_ = 0;
        this->head = nullptr;
    }

    template<typename T>
    LinkedList<T>::~LinkedList() {
        this->clear();
    }

    template<typename T>
    void LinkedList<T>::clear() {
        while(!this->empty()) {
            this->pop_front();
        }
    }

    template<typename T>
    void LinkedList<T>::push_back(const T& data) {
        if (this->empty()) {
            return this->push_front(data);
        }
        Node *previousNode = this->head;

        while(previousNode->next() != nullptr) {
            previousNode = previousNode->next();
        }

        Node *newNode = new Node(data, nullptr);
        previousNode->next(newNode);
        this->size_++;

    }

    template<typename T>
    void LinkedList<T>::push_front(const T& data) {
        Node *newNode = new Node(data, this->head);
        this->head = newNode;
        this->size_++;
    }

    template<typename T>
    void LinkedList<T>::insert(const T& data, std::size_t index) {
        this->assureValidInsertionPosition(index);
        if (index == 0) {
            return this->push_front(data);
        }

        Node *newNode, *previousNode;

        previousNode = this->head;

        auto i = 0;

        while(i < index-1) {
            previousNode = previousNode->next();
            i++;
        }

        newNode = new Node(data, previousNode->next());
        previousNode->next(newNode);
        this->size_++;
    }

    template<typename T>
    void LinkedList<T>::insert_sorted(const T& data) {
        if (this->empty()) {
            return this->push_front(data);
        }
        Node *currentNode = this->head;

        auto i = 0;
        while (i < this->size_-1 && data > currentNode->data()) {
            currentNode = currentNode->next();
            i++;
        }
        (data > currentNode->data()) ? this->insert(data, i+1) : this->insert(data, i);
    }

    template<typename T>
    T& LinkedList<T>::at(std::size_t index) {
        this->assureNotEmpty();
        this->assureValidRetrievalPosition(index);

        auto i = 0;
        Node *currentNode = this->head;
        while (i < index) {
            currentNode = currentNode->next();
            i++;
        }

        return currentNode->data();
    }

    template<typename T>
    T LinkedList<T>::pop(std::size_t index) {
        this->assureValidRetrievalPosition(index);

        if (index == 0) {
            this->pop_front();
        }

        Node *currentNode = this->head;
        auto i = 0;
        while (i < index-1) {
            currentNode = currentNode->next();
            i++;
        }

        Node *nodeToRemove = currentNode->next();
        currentNode->next(nodeToRemove->next());
        this->size_--;

        T data = nodeToRemove->data();
        delete nodeToRemove;
        return data;
    }

    template<typename T>
    T LinkedList<T>::pop_back() {
        this->assureNotEmpty();
        if (this->size_ == 1) {
            return this->pop_front();
        }
        Node *temporaryNode = this->head;
        while (temporaryNode->next()->next() != nullptr) {
            temporaryNode = temporaryNode->next();
        }

        Node *toBeDeletedNode = temporaryNode->next();
        temporaryNode->next(nullptr);
        T data = toBeDeletedNode->data();
        delete toBeDeletedNode;
        this->size_--;
        return data;
    }

    template<typename T>
    T LinkedList<T>::pop_front() {
        this->assureNotEmpty();

        this->size_--;
        Node *node = this->head;
        T data = node->data();
        this->head = this->head->next();
        delete node;
        return data;
    }

    template<typename T>
    void LinkedList<T>::remove(const T& data) {
        this->assureNotEmpty();
        auto index = this->at(data);
        this->pop(index);
    }

    template<typename T>
    bool LinkedList<T>::empty() const {
        return this->size_ == 0;
    }

    template<typename T>
    bool LinkedList<T>::contains(const T& data) const {
        return this->find(data) != this->size_;
    }

    template<typename T>
    std::size_t LinkedList<T>::find(const T& data) const {
        if (this->empty()) {
            throw std::out_of_range("The list is empty.");
        }

        auto i = 0;
        Node *currentNode = this->head;
        while (i < this->size_) {
            if (currentNode->data() == data) {
                return i;
            }
            currentNode = currentNode->next();
            i++;
        }

        return this->size_;
    }

    template<typename T>
    std::size_t LinkedList<T>::size() const {
        return this->size_;
    }

#endif

