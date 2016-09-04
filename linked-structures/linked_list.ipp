#ifndef STRUCTURES_LINKED_LIST_IPP
#define STRUCTURES_LINKED_LIST_IPP
    
    #include "linked_list.h"

    using namespace structures;

    template<typename T>
    LinkedList<T>::LinkedList() {
        size_ = 0;
        head = nullptr;
    }

    template<typename T>
    LinkedList<T>::~LinkedList() {
        clear();
    }

    template<typename T>
    void LinkedList<T>::clear() {
        while(!empty()) {
            pop_front();
        }
    }

    template<typename T>
    void LinkedList<T>::push_back(const T& data) {
        if(empty()) {
            push_front(data);
            return;
        }
        Node *previousNode = head;

        while(previousNode->next() != nullptr) {
            previousNode = previousNode->next();
        }

        Node *newNode = new Node(data, nullptr);
        previousNode->next(newNode);
        size_++;

    }

    template<typename T>
    void LinkedList<T>::push_front(const T& data) {
        Node *newNode = new Node(data, head);
        head = newNode;
        size_++;
    }

    template<typename T>
    void LinkedList<T>::insert(const T& data, std::size_t index) {
        if (index == 0) {
            push_front(data);
        } else if (index < 0 || index > size_) {
            throw std::out_of_range("Invalid position.");
        }

        Node *newNode, *previousNode;

        previousNode = head;

        auto i = 0;

        while(i < index-1) {
            previousNode = previousNode->next();
            i++;
        }

        newNode = new Node(data, previousNode->next());
        previousNode->next(newNode);
        size_++;
    }

    template<typename T>
    void LinkedList<T>::insert_sorted(const T& data) {
        if (empty()) {
            push_front(data);
            return;
        }

        Node *currentNode = head;
        size_--;

        auto i = 0;
        while(currentNode->next() != nullptr && data > currentNode->data()) {
            currentNode = currentNode->next();
            i++;
        }

        if (data > currentNode->data()) {
            insert(data, i+1);
            return;
        }

        insert(data, i);

    }

    template<typename T>
    T& LinkedList<T>::at(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("The list is empty");
        } else if (index < 0 || index > size_) {
            throw std::out_of_range("Invalid position.");
        }

        auto i = 0;
        Node *currentNode = head;
        while (i < index) {
            currentNode = currentNode->next();
            i++;
        }

        return currentNode->data();
    }

    template<typename T>
    T LinkedList<T>::pop(std::size_t index) {
        if (index < 0 || index > size_) {
            throw std::out_of_range("Invalid position.");
        } else if (index == 0) {
            pop_front();
        }

        Node *currentNode = head;
        auto i = 0;
        while (i < index) {
            currentNode = currentNode->next();
            i++;
        }

        Node *nodeToRemove = currentNode->next();
        currentNode->next(nodeToRemove->next());
        size_--;

        T data = nodeToRemove->data();
        delete nodeToRemove;
        return data;
    }

    template<typename T>
    T LinkedList<T>::pop_back() {
        if (empty()) {
            throw std::out_of_range("The list is empty.");
        }
        Node *temporaryNode = head;
        auto maximum = size_ - 2;
        if (maximum < 0) {
            return pop_front();
        }
        for (auto i = 0; i < maximum; i++) {
            temporaryNode = temporaryNode->next();
            if (temporaryNode == NULL) {
                throw std::out_of_range("Shit happened");
            }
        }
        Node *nextNode = temporaryNode->next();
        T valor = nextNode->data();
        temporaryNode->next(nextNode->next());
        delete nextNode;
        size_--;
        return valor;
    }

    template<typename T>
    T LinkedList<T>::pop_front() {
        if (empty()) {
            throw std::out_of_range("The list is empty.");
        }

        size_--;
        Node *node = head;
        T data = node->data();
        head = head->next();
        delete node;
        return data;
    }

    template<typename T>
    void LinkedList<T>::remove(const T& data) {}

    template<typename T>
    bool LinkedList<T>::empty() const {
        return size_ == 0;
    }

    template<typename T>
    bool LinkedList<T>::contains(const T& data) const {
        return find(data) != size_+1;
    }

    template<typename T>
    std::size_t LinkedList<T>::find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("The list is empty.");
        }

        size_t i = 0;
        Node *currentNode = head;
        while (!empty() && i < size_) {
            if (currentNode->data() == data) {
                return i;
            }
            currentNode = currentNode->next();
            i++;
        }

        return size_+1;
    }

    template<typename T>
    std::size_t LinkedList<T>::size() const {
        return size_;
    }

#endif

