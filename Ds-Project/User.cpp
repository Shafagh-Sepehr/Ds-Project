#include "User.h"

User::User(string name, string lname, string username, string pass, int code) {
	this->name = name;
	this->last_name = lname;
	this->username = username;
	this->password = pass;
	this->code = code;
	if (this->username == "admin")
		this->admin = true;
	else
		this->admin = false;
}

void User::addBook(Book* book) {
	this->book_list.push_back(book);
}

void User::returnBook(Book* b1) {
	for (int i = 0; i < this->book_list.size(); i++)
		if (this->book_list[i] == b1) {
			this->book_list.erase(i);
			b1->unown();
			return;
		}
}

void User::setOwner(User* u1,Book* b1) {
	if (this->admin) {
		if (b1->setBookOwner(u1->code)) {
			cout << "\nthis book is reserved succesfully\n";
			return;
		}
		u1->addBook(b1);
		cout << "\nsetting owner completed\n";
	}
	else
		cout << "\nyou are not admin\n";
}

void User::printList() {
	cout << "\nUser " << this->name << " books:";
	for (int i = 0; i < this->book_list.size(); i++)
		this->book_list[i]->printBook();
}
