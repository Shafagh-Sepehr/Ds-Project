#pragma once
#include <iostream>
#include "AvlTree.h"
#include "AvlTree.cpp"
#include "List.h"
#include "List.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Book.h"
#include "User.h"
using namespace std;

class Controller {
private:
	static User *logged_in_user;




public:

	static bool add_user(string name, string lname, string username, string pass);
	static void add_book(string genre, string name, string date, string writer);
	static Book *search_book(string name);
	static Book *search_user_borrowed_book(string name);
	static void borrow_book(Book *book, User *user);
	static void return_book(Book *book, User *user);
	static List<pair<string, Book>> show_user_borrowed_books();
	static List<pair<string, Book>> show_all_books();
	static void extendBorrow(User *user, Book *book);
	static bool isAdminControl();
	static bool searchUser(string username, string pass);
	static User *getUser(string username, string pass);



};

