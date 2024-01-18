#ifndef BOOK_H
#define BOOK_H

#pragma once
#include <iostream>
using namespace std;

class Book {
private:
	string genre, name, print_date, writer;
	int owner;
public:
	Book(string genre, string name, string date, string writer);
	void setBookOwner(int id);
};

#endif // !BOOK_H