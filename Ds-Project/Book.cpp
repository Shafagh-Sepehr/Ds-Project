#include "Book.h"

Book::Book(string genre, string name, string date, string writer) {
	this->genre = genre;
	this->name = name;
	this->print_date = date;
	this->writer = writer;
	this->owner = 0;
	Queue<int> user(10);
	Queue<int> day(10);
	this->user_reserved_id = user;
	this->day_reserved = day;

	books.push_back(this);
}
int Book::setBookOwner(int id) {
	if ( !this->owner ) {
		this->owner = id;
		return 0;
	}
	this->user_reserved_id.queue(id);
	auto currentTime = std::chrono::system_clock::now();
	std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	std::tm *currentTime_tm = std::localtime(&currentTime_t);
	int day = currentTime_tm->tm_mday;
	this->day_reserved.queue(day);
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

void Book::unown() {

}
