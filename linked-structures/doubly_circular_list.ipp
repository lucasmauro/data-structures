#ifndef STRUCTURES_DOUBLY_CIRCULAR_LIST_IPP
#define STRUCTURES_DOUBLY_CIRCULAR_LIST_IPP

#include "doubly_circular_list.h"

template<typename T>
structures::DoublyCircularList<T>::DoublyCircularList() {
	DoubleNode<T>* sentinel = new DoubleNode<T>(0, nullptr, nullptr);
	sentinel->prev(sentinel);
	sentinel->next(sentinel);
	this->head = sentinel;
	this->size_ = 0;
}

template<typename T>
structures::DoublyCircularList<T>::~DoublyCircularList() {
	this->clear();
}

template<typename T>
void structures::DoublyCircularList<T>::push_back(const T& data) {
	if (this->empty())
		return this->push_front(data);

	DoubleNode<T>* sentinel = this->head->prev();
	DoubleNode<T>* temporary = sentinel->prev();

	DoubleNode<T>* fresh = new DoubleNode<T>(data, temporary, sentinel);

	temporary->next(fresh);
	sentinel->prev(fresh);

	this->size_++;
}

template<typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
	DoubleNode<T>* sentinel = this->head->prev();
	DoubleNode<T>* fresh = new DoubleNode<T>(data, sentinel, this->head);

	this->head = fresh;

	sentinel->next(fresh);
	fresh->next()->prev(fresh);

	this->size_++;
}

template<typename T>
T structures::DoublyCircularList<T>::pop_back() {
	this->assureNotEmpty();

	if (this->size_ == 1)
		return this->pop_front();

	DoubleNode<T>* sentinel = this->head->prev();
	DoubleNode<T>* temporary = sentinel->prev();

	T data = temporary->data();
	temporary->prev()->next(sentinel);
	sentinel->prev(temporary->prev());

	delete temporary;
	this->size_--;
	return data;
}

template<typename T>
T structures::DoublyCircularList<T>::pop_front() {
	this->assureNotEmpty();

	DoubleNode<T>* sentinel = this->head->prev();
	DoubleNode<T>* temporary = this->head;

	temporary->next()->prev(sentinel);

	T data = temporary->data();

	if (temporary->next() != nullptr) {
		temporary->next()->prev(sentinel);
		sentinel->next(temporary->next());
		this->head = temporary->next();
		delete temporary;
	}

	this->size_--;
	return data;
}

#endif
