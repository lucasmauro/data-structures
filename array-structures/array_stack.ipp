#ifndef STRUCTURES_ARRAY_STACK_IPP
#define STRUCTURES_ARRAY_STACK_IPP

    #include "array_stack.h"

    using namespace structures;
    
    template<typename T>
    ArrayStack<T>::ArrayStack() {
        this->ArrayStack(this->DEFAULT_SIZE);
    }

    template<typename T>
    ArrayStack<T>::ArrayStack(std::size_t max) {
        this->contents = new T[max];
        this->top_ = -1;
        this->max_size_ = max;
    }

    template<typename T>
    ArrayStack<T>::~ArrayStack() {
        this->top_ = -1;
        delete[] this->contents;
    }

    template<typename T>
    void ArrayStack<T>::push(const T& data) {
        this->assure_that_stack_is_not_full();
        this->top_++;
        this->contents[top_] = data;
    }

    template<typename T>
    T ArrayStack<T>::pop() {
        this->assure_that_stack_is_not_empty();
        this->top_--;
        return this->contents[top_+1];
    }

    template<typename T>
    T& ArrayStack<T>::top() {
        this->assure_that_stack_is_not_empty();
        return this->contents[top_];
    }

    template<typename T>
    void ArrayStack<T>::clear() {
        this->top_ = -1;
    }

    template<typename T>
    std::size_t ArrayStack<T>::size() {
        return this->top_ + 1;
    }

    template<typename T>
    std::size_t ArrayStack<T>::max_size() {
        return this->max_size_;
    }

    template<typename T>
    bool ArrayStack<T>::empty() {
        return this->top_ == -1;
    }

    template<typename T>
    bool ArrayStack<T>::full() {
        return this->top_ == (max_size_ - 1);
    }

#endif
