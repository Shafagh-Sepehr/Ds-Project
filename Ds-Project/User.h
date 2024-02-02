#pragma once
#include <iostream>
#include "Book.h"
#include "List.h"
#include "List.cpp"
using namespace std;

struct element {
	Book *book;
	int day;
	int month;
	int year;
};

class User {
private:
	List<element *> book_list;
	string name, last_name, username, password;
	int id;
	static int code;
	bool admin;
	static List<User *> users;
public:
	User() = default;
	User(string name, string lname, string username, string pass);
	void addBook(Book *book);
	/*void returnBook(element b1);*/
	/*void setOwner(User *u1, Book *b1);*/
	/*void printList();*/
	int get_id();
	List<element *>* get_book_list();
	void extend(Book *book);
	bool isAdmin();
	static List<User *> get_users_list();
	bool checkLogin(string username, string pass);
};

