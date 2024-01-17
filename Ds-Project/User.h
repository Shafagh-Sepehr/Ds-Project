#pragma once
#include <iostream>
#include "Book.h"
#include "List.h"
#include "List.cpp"
using namespace std;

class User {
private:
	List<Book*> book_list;
	string name, last_name, username, password;
	int code;
	bool admin;
public:
	User(sting name, string lname, string username, string pass, int code);
	void addBook(Book* book);
	Book* returnBook();
	void setOwner(User* u1, Book* b1);

};