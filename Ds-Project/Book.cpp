#include "Book.h"

Book::Book(string genre, string name, string date, string writer) {
	this->genre = genre;
	this->name = name;
	this->print_date = date;
	this->writer = writer;
	this->owner = 0;
	this->user_reserved_id = Queue<int>(10);
	books.push_back(this);
	last_date_borrowed.day = -1;
	last_date_borrowed.month = -1;
	last_date_borrowed.year = -1;
}
int Book::setBookOwner(int id) {
	if ( !this->owner ) {
		this->owner = id;
		return 0;
	}
	this->user_reserved_id.queue(id);
	return 1;
}

void Book::printBook() {
	cout << "\n-----------------------------"
		<< endl << "book name: " << this->name
		<< endl << "book genre: " << this->genre
		<< endl << "book writer: " << this->writer
		<< endl << "owner: " << ((this->owner) ? this->owner : -1)
		<< "\n-----------------------------";
}

bool Book::operator==(Book *b1) {
	return this->name == b1->name && this->genre == b1->genre
		&& this->owner == b1->owner && this->writer == b1->writer;
}

void Book::returnBook() {
	if ( this->user_reserved_id.isEmpty() )
		this->owner = 0;
	else {

	}
}

bool Book::isThisMyTurn(int id) {
	if (this->user_reserved_id.isEmpty())
		return true;
	auto currentTime = std::chrono::system_clock::now();
	std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	std::tm* currentTime_tm = std::localtime(&currentTime_t);
	int day = currentTime_tm->tm_mday;
	int month = currentTime_tm->tm_mon;
	int year = currentTime_tm->tm_year;
	int years_passed = year - this->last_date_borrowed.year;
	int monthes_passed = month - this->last_date_borrowed.month;
	int days_passed = day - this->last_date_borrowed.day + 30 * monthes_passed + 360 * years_passed;
	int user_id;
	for (int i = 0; i <= days_passed / 3; i++) {
		if (this->user_reserved_id.isEmpty())
			return true;
		if (this->user_reserved_id.last() == id) {
			this->user_reserved_id.Dequeue();
			return true;
		}
	}
	if (user_id == id)
		return true;
	else
		return false;
}

List<Book *> Book::get_books_list() {
	return books;
}

string Book::get_name() {
	return name;
}
