#include "User.h"

User::User(string name, string lname, string username, string pass) {
	this->id = ++this->code;
	this->name = name;
	this->last_name = lname;
	this->username = username;
	this->password = pass;
	if ( this->username == "admin" && this->password == "1234" )
		this->admin = true;
	else
		this->admin = false;

	users.push_back(this);
}

void User::addBook(Book *b1) {
	auto currentTime = std::chrono::system_clock::now();
	std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	std::tm *currentTime_tm = std::localtime(&currentTime_t);
	int day = currentTime_tm->tm_mday;
	int month = currentTime_tm->tm_mon;
	int year = currentTime_tm->tm_year;
	element tmp;
	tmp.book = b1;
	tmp.day = day;
	tmp.month = month;
	tmp.year = year;
	this->book_list.push_back(tmp);
}

void User::returnBook(element *b1) {
	for ( int i = 0; i < this->book_list.size(); i++ )
		if ( this->book_list[i]->book == b1->book ) {
			this->book_list.erase(i);
			return;
		}
}

//void User::setOwner(User *u1, Book *b1) {
//	if ( this->admin ) {
//		if ( b1->setBookOwner(u1->code) ) {
//			cout << "\nthis book is reserved succesfully\n";
//			return;
//		}
//		u1->addBook(b1);
//		cout << "\nsetting owner completed\n";
//	}
//	else
//		cout << "\nyou are not admin\n";
//}

void User::printList() {
	cout << "\nuser " << this->name << " books:";
	for ( int i = 0; i < this->book_list.size(); i++ )
		this->book_list[i]->book->printBook();
}

int User::get_id() {
	return id;
}

List<element *> User::get_book_list() {
	return this->book_list;
}

bool User::isAdmin() {
	return this->admin;
}

List<User *> User::get_users_list() {
	return users;
}
