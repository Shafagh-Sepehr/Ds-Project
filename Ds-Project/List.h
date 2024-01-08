#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Node;


template <typename T>
class List {
public:
	class Iterator {
	private:
		Node<T> *ptr;

	public:
		Iterator();
		Iterator(Node<T> *node);
		Iterator(const Node<T> &that);
		Iterator(const List<T>::Iterator &that);


		List<T>::Iterator operator=(Node<T> node);
		List<T>::Iterator operator++();
		List<T>::Iterator operator--();
		List<T>::Iterator operator++(int);
		List<T>::Iterator operator--(int);

		Node<T> *operator*();

		bool operator==(const List<T>::Iterator &that);
		bool operator!=(const List<T>::Iterator &that);


	};


private:
	int _size;
	Node<T> *head_tail;


public:


	List();
	List(int size, T value = T());
	List(const List<T> &that);
	List<T> operator=(const List<T> &that);

	~List();

	List<T>::Iterator begin();
	List<T>::Iterator end();

	T &operator[](int i);

	void insert(int i, const T &data);
	void insert(List<T>::Iterator where, const T &data);

	T erase(int i);
	T erase(List<T>::Iterator it);
	void erase(List<T>::Iterator first, List<T>::Iterator last);

	T replace(int i, const T &data);
	T replace(List<T>::Iterator where, const T &data);
	T replace(List<T>::Iterator where, Node<T> node);

	void swap(int a, int b);
	void swap(List<T>::Iterator ita, List<T>::Iterator itb);

	void sort();

	bool empty();
	void clear();
	void kill();

	int get_index(List<T>::Iterator it);
	List<T>::Iterator get_Iterator(int i);

	void push_back(const T &new_data);
	void push_front(const T &new_data);

	T pop_back();
	T pop_front();

	T &front();
	T &back();

	int size() { return _size; }

	void print();



};


template<typename T>
class Node {
	friend List<T>;
	//friend List<T>::Iterator;

private:

	T data;
	Node *next;
	Node *prev;

public:

	Node();
	Node(const Node &that);
	Node(int data);

	void add_after(T data);
	void add_before(T data);
	void remove();
	void set_data(T data);

};

