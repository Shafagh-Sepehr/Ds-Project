#pragma once
#include <iostream>
using namespace std;

class Book {
private:
	string genre, name, print_date, writer;
public:
	Book(string genre, string name, string date, string wirter);
};