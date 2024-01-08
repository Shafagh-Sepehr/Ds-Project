#include "Queue.h"

template <typename T>
Queue<T>::Queue(const Queue<T>& queue) {
	this->size = queue.size;
	this->arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = queue.arr[i];
	this->rear = queue.rear;
	this->front = queue.front;
	this->items_in_queue = queue.items_in_queue;
}

template <typename T>
Queue<T>::Queue(int size) {
	arr = new T[size];
	this->size = size;
	this->rear = this->front = 0;
	this->items_in_queue = 0;
}

template <typename T>
void Queue<T>::queue(T data) {
	if (this->items_in_queue == this->size)
		return;
	this->arr[this->front] = data;
	this->items_in_queue++;
	(++this->front) %= this->size;
}

template <typename T>
T Queue<T>::Dequeue() {
	if (!this->items_in_queue)
		return NULL;
	T tmp = this->arr[this->rear];
	(++this->rear) %= this->size;
	this->items_in_queue--;
	return tmp;
}

template <typename T>
int Queue<T>::GetItemsInQueue() {
	return this->items_in_queue;
}

template <typename T>
int Queue<T>::GetSize() {
	return this->size;
}
