#include "Book.h"

Book::Book(string genre, string name, string date, string writer) {
	this->genre = genre;
	this->name = name;
	this->print_date = date;
	this->writer = writer;
	this->owner = 0;
	this->user_reserved_id = Queue<int>(10);
}
int Book::setBookOwner(int id) {
	if (!this->owner) {
		this->owner = id;
		return 0;
	}
	this->user_reserved_id.queue(id);
	return 1;
}

void Book::printBook() {
	cout << "\n-----------------------------"
		<<endl << "book name: " << this->name
		<< endl << "book genre: " << this->genre
		<< endl << "book writer: " << this->writer
		<< endl << "owner: " << ((this->owner) ? this->owner : -1)
		<< "\n-----------------------------";
}

bool Book::operator==(Book* b1) {
	return this->name == b1->name && this->genre == b1->genre
		&& this->owner == b1->owner && this->writer == b1->writer;
}

void Book::unown() {
	
}
