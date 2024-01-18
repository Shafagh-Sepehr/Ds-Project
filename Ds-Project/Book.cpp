#include "Book.h"

Book::Book(string genre, string name, string date, string writer) {
	this->genre = genre;
	this->name = name;
	this->print_date = date;
	this->writer = writer;
	this->owner = 0;
}
void Book::setBookOwner(int id) {
	if (!this->owner)
		this->owner = id;
	else
		throw "this book is owned";
}
