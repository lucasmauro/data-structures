#ifndef STRUCTURES_ARRAY_QUEUE_IPP
#define STRUCTURES_ARRAY_QUEUE_IPP

    #include "array_queue.h"

    using namespace structures;

    template<typename T>
    ArrayQueue<T>::ArrayQueue() {
        this->ArrayQueue(this->DEFAULT_SIZE);
    }

    template<typename T>
    ArrayQueue<T>::ArrayQueue(std::size_t max) {
        this->contents = new T[max];
        this->size_ = -1;
        this->max_size_ = max;
    }

    template<typename T>
    ArrayQueue<T>::~ArrayQueue() {
        this->size_ = -1;
        delete this-> contents;
    }

    template<typename T>
    void ArrayQueue<T>::enqueue(const T& data) {
        this->assure_that_queue_is_not_full();
        this->size_++;
        this->contents[this->size_] = data;
    }

    template<typename T>
    T ArrayQueue<T>::dequeue() {
        this->assure_that_queue_is_not_empty();
        T data = this->contents[0];
        int size = this->size();
        for (int i = 1; i < size; i++) {
            this->contents[i-1] = this->contents[i];
        }
        this->size_--;
        return data;
    }

    template<typename T>
    T& ArrayQueue<T>::back() {
        this->assure_that_queue_is_not_empty();
        return this->contents[this->size_];
    }

    template<typename T>
    void ArrayQueue<T>::clear() {
        this->size_ = -1;
    }

    template<typename T>
    std::size_t ArrayQueue<T>::size() {
        return this->size_ + 1;
    }

    template<typename T>
    std::size_t ArrayQueue<T>::max_size() {
        return this->max_size_;
    }

    template<typename T>
    bool ArrayQueue<T>::empty() {
        return this->size_ == -1;
    }

    template<typename T>
    bool ArrayQueue<T>::full() {
        return this->size_ == (this->max_size_ - 1);
    }

#endif
