#pragma once
#include "Queue.h"
#include "Queue.cpp"
#include "List.h"
#include "List.cpp"
#include <iostream>
#include <chrono>
using namespace std;

class Book {
private:
	string genre, name, print_date, writer;
	int owner;
	Queue<int> user_reserved_id;

	static List<Book *> books;
public:
	Book(string genre, string name, string date, string writer);
	int setBookOwner(int id);
	void printBook();
	bool operator==(Book *b1);
	void returnBook();
	static List<Book *> get_books_list();

	string get_name();
};

List<Book *> Book::books = List<Book *>();

