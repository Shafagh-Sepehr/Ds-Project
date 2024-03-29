#pragma once
#pragma warning(disable:4996)
#include "Queue.h"
#include "Queue.cpp"
#include "List.h"
#include "List.cpp"
#include <iostream>
#include <chrono>
using namespace std;

struct date {
	int day, month, year;
};

class Book {
private:
	string genre, name, print_date, writer;
	int owner;
	date last_date_borrowed;

	static List<Book *> books;
public:
	Queue<int> user_reserved_id;
	Book() = default;
	Book(string genre, string name, string date, string writer);
	int setBookOwner(int id);
	void printBook();
	bool operator==(Book *b1);
	bool isThisMyTurn(int id);
	static List<Book *> get_books_list();
	void setDate(int day, int month, int year);
	void setOwner(int owner);
	string get_name();
	bool isQueueEmpty();
};



