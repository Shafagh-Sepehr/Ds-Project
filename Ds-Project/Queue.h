#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
	T* arr;
	int front;
	int rear;
	int size;
	int items_in_queue;
public:
	Queue() = default;
	Queue(const Queue<T>& queue);
	Queue(int size);
	T Dequeue();
	void queue(T data);
	int GetItemsInQueue();
	int GetSize();
};