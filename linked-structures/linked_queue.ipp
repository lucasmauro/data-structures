#ifndef STRUCTURES_LINKED_QUEUE_IPP
#define STRUCTURES_LINKED_QUEUE_IPP

    using namespace structures;

    template<typename T>
    LinkedQueue<T>::LinkedQueue() {
        this->tail = nullptr;
    }

    template<typename T>
    LinkedQueue<T>::~LinkedQueue() {
        this->list.~LinkedList();
    }

    template<typename T>
    void LinkedQueue<T>::clear() {
        this->list.clear();
    }

    template<typename T>
    void LinkedQueue<T>::enqueue(const T& data) {
        this->list.push_back(data);
    }

    template<typename T>
    T LinkedQueue<T>::dequeue() {
        return this->list.pop_front();
    }

    template<typename T>
    T& LinkedQueue<T>::front() {
        return this->list.at(0);
    }

    template<typename T>
    T& LinkedQueue<T>::back() {
        return this->list.at(this->list.size()-1);
    }

    template<typename T>
    bool LinkedQueue<T>::empty() const {
        return this->list.empty();
    }

    template<typename T>
    std::size_t LinkedQueue<T>::size() const {
        return this->list.size();
    }

#endif