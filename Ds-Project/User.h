#pragma once
#include <iostream>
#include "Book.h"
#include "List.h"
#include "List.cpp"
using namespace std;

struct element {
	Book* book;
	int day;
	int month;
};

class User {
private:
	List<element> book_list;
	string name, last_name, username, password;
	int code;
	bool admin;
	static List<User *> users;
public:
	User(string name, string lname, string username, string pass, int code);
	void addBook(Book* book);
	void returnBook(element b1);
	void setOwner(User* u1,Book* b1);
	void printList();
};

List<User *> User::users = List<User *>();