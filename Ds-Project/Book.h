#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class Book {
private:
	string genre, name, print_date, writer;
	User* owner;
public:
	Book(string genre, string name, string date, string wirter);
	void setBookOwner(User* u1);
};