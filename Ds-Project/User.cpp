#include "User.h"

User::User(string name, string lname, string username, string pass, int code) {
	this->name = name;
	this->last_name = lname;
	this->username = username;
	this->password = pass;
	this->code = code;
	if (this->username == "admin" && this->password == "1234")
		this->admin = true;
	else
		this->admin = false;

	users.push_back(this);
}

void User::addBook(Book* b1) {
	auto currentTime = std::chrono::system_clock::now();
	std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	std::tm* currentTime_tm = std::localtime(&currentTime_t);
	int day = currentTime_tm->tm_mday;
	int month = currentTime_tm->tm_mon;
	element tmp;
	tmp.book = b1;
	tmp.day = day;
	tmp.month = month;
	this->book_list.push_back(tmp);
}

//void User::returnBook(element b1) {
//	for (int i = 0; i < this->book_list.size(); i++)
//		if (this->book_list[i] == b1) {
//			this->book_list.erase(i);
//			b1->unown();
//			return;
//		}
//}

void User::setOwner(User *u1, Book *b1) {
	if ( this->admin ) {
		if ( b1->setBookOwner(u1->code) ) {
			cout << "\nthis book is reserved succesfully\n";
			return;
		}
		u1->addBook(b1);
		cout << "\nsetting owner completed\n";
	}
	else
		cout << "\nyou are not admin\n";
}

//void User::printList() {
//	cout << "\nUser " << this->name << " books:";
//	for (int i = 0; i < this->book_list.size(); i++)
//		this->book_list[i]->printBook();
//}
