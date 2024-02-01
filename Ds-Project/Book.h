#ifndef BOOK_H
#define BOOK_H

#pragma once
#pragma warning(disable : 4996)
#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
#include <chrono>
using namespace std;

class Book {
private:
	string genre, name, print_date, writer;
	int owner; 
	Queue<int> user_reserved_id;
public:
	Book(string genre, string name, string date, string writer);
	int setBookOwner(int id);
	void printBook();
	bool operator==(Book* b1);
	void unown();
};

#endif // !BOOK_H