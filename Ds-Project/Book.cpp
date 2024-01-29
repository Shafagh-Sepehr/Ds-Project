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

void Book::printBook() {
	cout << endl << "book name: " << this->name
		<< endl << "book genre: " << this->genre
		<< endl << "book writer: " << this->writer
		<< endl << "owner: " << ((this->owner) ? this->owner : -1);
}
