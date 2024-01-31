#pragma once
#include "List.h"

template<typename T>
Node<T>::Node():data(T()), prev(nullptr), next(nullptr) {}

template<typename T>
Node<T>::Node(const Node<T> &that) = default;

template<typename T>
Node<T>::Node(int data): data(data), prev(nullptr), next(nullptr) {}

template<typename T>
void Node<T>::add_after(T data) {

	Node<T> *new_node = new Node<T>(data);
	Node<T> *before = this;
	Node<T> *after = this->next;

	new_node->prev = before;
	new_node->next = after;
	before->next = new_node;
	if ( after != nullptr )
		after->prev = new_node;
}

template<typename T>
void Node<T>::add_before(T data) {

	Node<T> *new_node = new Node<T>;
	new_node->data = data;
	Node<T> *after = this;
	Node<T> *before = this->prev;

	new_node->next = after;
	new_node->prev = before;
	after->prev = new_node;
	if ( after != nullptr )
		before->next = new_node;

}

template<typename T>
void Node<T>::remove() {

	Node<T> *after = this->next;
	Node<T> *before = this->prev;

	after->prev = before;
	before->next = after;

	delete this;

}

template<typename T>
void Node<T>::set_data(T data) { this->data = data; }



template<typename T>
List<T>::List(): _size(0) {
	head_tail = new Node<T>();
	head_tail->prev = head_tail;
	head_tail->next = head_tail;
}

template<typename T>
List<T>::List(int size, T value):_size(size) {
	head_tail = new Node<T>();
	head_tail->prev = head_tail;
	head_tail->next = head_tail;

	Node<T> *it = head_tail;
	while ( size-- ) {
		it->add_after(value);
		it = it->next;
	}
}

template<typename T>
List<T>::List(const List<T> &that) {
	for ( Node<T> *node : that ) {
		this->push_back(node->data);
	}
}

template<typename T>
List<T> List<T>::operator=(const List<T> &that) {
	return List<T>();
}

template<typename T>
List<T>::~List() {

	this->clear();
	if ( head_tail ) {
		delete head_tail;
		head_tail = nullptr;
	}
}

template<typename T>
typename List<T>::Iterator List<T>::begin() {
	return List<T>::Iterator(this->head_tail->next);
}

template<typename T>
typename List<T>::Iterator List<T>::end() {
	return List<T>::Iterator(this->head_tail);
}

template<typename T>
T &List<T>::operator[](int i) {
	if ( i < 0 || i >= this->_size )
		throw exception("out of range");
	int ctr = 0;
	for ( Node<T> *it : *this ) {
		if ( ctr++ == i )
			return it->data;
	}
}

template<typename T>
void List<T>::insert(int i, const T &data) {
	if ( i < 0 || i >= this->_size )
		throw exception("out of range");
	int ctr = 0;
	for ( Node<T> *it : *this ) {
		if ( ctr++ == i ) {
			it->add_before(data);
			this->_size++;
		}
	}
}

template<typename T>
void List<T>::insert(List<T>::Iterator where, const T &data) {
	(*where)->add_before(data);
	this->_size++;
}

template<typename T>
T List<T>::erase(int i) {
	if ( i < 0 || i >= this->_size )
		throw exception("out of range");
	int ctr = 0;
	for ( Node<T> *it : *this ) {
		if ( ctr++ == i ) {
			T data = it->data;
			it->remove();
			this->_size--;
			return data;
		}
	}
}

template<typename T>
T List<T>::erase(List<T>::Iterator it) {
	return this->erase(this->get_index(it));
}

template<typename T>
void List<T>::erase(List<T>::Iterator first, List<T>::Iterator last) {
	if ( first == last )
		return;

	while ( (*first)->next != (*last) ) {
		(*first)->next->remove();
		this->_size--;
	}
	(*first)->remove();
	this->_size--;


}

template<typename T>
T List<T>::replace(int i, const T &data) {
	if ( i < 0 || i >= this->_size )
		throw exception("out of range");
	int ctr = 0;
	for ( Node<T> *it : *this ) {
		if ( ctr == i ) {
			T old_data = it->data;
			it->data = data;
			return old_data;
		}
		ctr++;
	}
}

template<typename T>
T List<T>::replace(List<T>::Iterator where, const T &data) {

	T old_data = (*where)->data;
	(*where)->data = data;
	return old_data;

}

template<typename T>
T List<T>::replace(List<T>::Iterator where, Node<T> node) {
	T old_data = (*where)->data;
	(*where)->data = node.data;
	return old_data;
}

template<typename T>
void List<T>::swap(int a, int b) {
	swap(get_Iterator(a), get_Iterator(b));
}

template<typename T>
void List<T>::swap(List<T>::Iterator ita, List<T>::Iterator itb) {

	T temp = (*ita)->data;
	(*ita)->data = (*itb)->data;
	(*itb)->data = temp;
}

template<typename T>
void List<T>::sort() {


}

template<typename T>
bool List<T>::empty() { return this->_size == 0; }

template<typename T>
void List<T>::clear() {
	while ( _size ) {
		this->pop_back();
	}
}

template<typename T>
void List<T>::kill() {
	this->~List();

}



template<typename T>
int List<T>::get_index(List<T>::Iterator it) {

	int ctr = 0;
	for ( Node<T> *node : *this ) {
		if ( node == *it )
			return ctr;
		ctr++;
	}
	return -1;
}

template<typename T>
typename List<T>::Iterator List<T>::get_Iterator(int i) {
	if ( i < 0 || i >= this->_size )
		throw exception("out of range");
	int ctr = 0;
	for ( List<T>::Iterator it = this->begin(); it != this->end(); it++ ) {
		if ( ctr == i )
			return it;
		ctr++;
	}
	return List<T>::Iterator();
}

template<typename T>
void List<T>::push_back(const T &new_data) {
	head_tail->add_before(new_data);
	this->_size++;
}

template<typename T>
void List<T>::push_front(const T &new_data) {
	head_tail->add_after(new_data);
	this->_size++;
}

template<typename T>
T List<T>::pop_back() {
	if ( this->_size == 0 )
		throw exception("poping from empty list");
	T data = head_tail->prev->data;
	head_tail->prev->remove();
	this->_size--;
	return data;
}

template<typename T>
T List<T>::pop_front() {
	if ( this->_size == 0 )
		throw exception("poping from empty list");
	T data = head_tail->next->data;
	head_tail->next->remove();
	this->_size--;
	return data;
}

template<typename T>
T &List<T>::front() {
	return head_tail->next->data;
}

template<typename T>
T &List<T>::back() {
	return head_tail->prev->data;
}

template<typename T>
void List<T>::print() {
	for ( Node<T> *node : *this ) {
		cout << node->data << ", ";
	}
	cout << endl;
}





template<typename T>
List<T>::Iterator::Iterator():ptr(nullptr) {}

template<typename T>
List<T>::Iterator::Iterator(Node<T> *node) : ptr(node) {}

template<typename T>
List<T>::Iterator::Iterator(const Node<T> &that) : ptr(that.ptr) {}

template<typename T>
List<T>::Iterator::Iterator(const List<T>::Iterator &that) = default;



template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator=(Node<T> node) {
	this->ptr = node;
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++() {
	ptr = ptr->next;
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--() {
	ptr = ptr->prev;
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
	ptr = ptr->next;
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
	ptr = ptr->prev;
	return *this;
}

template<typename T>
Node<T> *List<T>::Iterator::operator*() {
	return ptr;
}

template<typename T>
bool List<T>::Iterator::operator==(const List<T>::Iterator &that) {
	return this->ptr == that.ptr;
}

template<typename T>
bool List<T>::Iterator::operator!=(const List<T>::Iterator &that) {
	return this->ptr != that.ptr;
}


