#include "Book.h"

Book::Book(string genre, string name, string date, string wirter) {
	this->genre = genre;
	this->name = name;
	this->print_date = date;
	this->writer = writer;
	this->owner = NULL;
}
void Book::setBookOwner(User* u1) {
	if (this->owner == NULL)
		this->owner = u1;
	else
		throw "this book is owned";
}
