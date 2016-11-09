#ifndef STRUCTURES_ARRAY_LIST_IPP
#define STRUCTURES_ARRAY_LIST_IPP

    using namespace structures;

    template<typename T>
    ArrayList<T>::ArrayList() {
        this->ArrayList(this->DEFAULT_MAX);

    }

    template<typename T>
    ArrayList<T>::ArrayList(std::size_t max_size) {
        this->contents = new T[max_size];
        this->size_ = 0;
        this->max_size_ = max_size;
    }

    template<typename T>
    ArrayList<T>::~ArrayList() {
        delete[] this->contents;
    }

    template<typename T>
    void ArrayList<T>::clear() {
        this->size_ = 0;
    }

    template<typename T>
    void ArrayList<T>::push_back(T data) {
        this->insert(data, this->size_);
    }

    template<typename T>
    void ArrayList<T>::push_front(T data) {
        this->insert(data, 0);
    }


    template<typename T>
    void ArrayList<T>::insert(T data, std::size_t index) {
        this->assureNotFull();
        this->assureValidInsertPosition(index);

        for (auto i = this->size_; i > index; i--) {
            this->contents[i] = this->contents[i-1];
        }

        this->size_++;
        this->contents[index] = data;
    }

    template<typename T>
    void ArrayList<T>::insert_sorted(T data) {
        this->assureNotFull();

        auto i = 0;
        while (i < this->size_ && data > this->contents[i]) {
            i++;
        }

        this->insert(data, i);
    }

    template<typename T>
    T ArrayList<T>::pop(std::size_t index) {
        this->assureNotEmpty();
        this->assureValidPopPosition(index);
        
        auto i = index;
        T data = this->contents[index];

        while (i < this->size_) {
            this->contents[i] = this->contents[i+1];
            i++;
        }
        
        this->size_--;
        return data;
    }

    template<typename T>
    T ArrayList<T>::pop_back() {
        return this->pop(this->size_-1);
    }

    template<typename T>
    T ArrayList<T>::pop_front() {
        return this->pop(0);
    }

    template<typename T>
    void ArrayList<T>::remove(T data) {
        auto position = this->find(data);
        this->pop(position);
    }

    template<typename T>
    bool ArrayList<T>::full() const {
        return this->size_ == this->max_size_;
    }

    template<typename T>
    bool ArrayList<T>::empty() const {
        return this->size_ == 0;
    }

    template<typename T>
    bool ArrayList<T>::contains(const T& data) const {
        return this->find(data) != this->size_;
    }

    template<typename T>
    std::size_t ArrayList<T>::find(const T& data) const {
        for (auto i = 0; i <= this->size_; i++) {
            if (this->contents[i] == data)
                return i;
        }
        return this->size_;
    }

    template<typename T>
    std::size_t ArrayList<T>::size() const {
        return this->size_;
    }

    template<typename T>
    std::size_t ArrayList<T>::max_size() const {
        return this->max_size_;
    }

    template<typename T>
    T& ArrayList<T>::at(std::size_t index) {
        this->assureValidPopPosition(index);
        return this->contents[index];
    }

    template<typename T>
    T& ArrayList<T>::operator[](std::size_t index) {
        return this->contents[index];
    }

    template<typename T>
    const T& ArrayList<T>::at(std::size_t index) const {
        this->assureValidPopPosition(index);
        return this->content[index];
    }

    template<typename T>
    const T& ArrayList<T>::operator[](std::size_t index) const {
        return this->content[index];
    }

#endif