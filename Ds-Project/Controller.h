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

	static void add_user(string name, string lname, string username, string pass);
	static void add_book(string genre, string name, string date, string writer);
	static Book *search_book(string name);
	static void borrow_book(Book *book, User *user);
	static void return_book(element book);
	static void show_user_borrowed_books();
	static void show_all_books();
	static void extendBorrow(User* user, Book* book);





};

User *Controller::logged_in_user = nullptr;