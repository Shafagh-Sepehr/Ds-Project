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

Book* User::returnBook() {
	if(!this->book_list.empty())
		return book_list.pop_back();
	cout << "\nno book in list\n";
	return nullptr;
}

void User::setOwner(User* u1,Book* b1) {
	try {
		if (this->admin) {
			b1->setBookOwner(u1->code);
			u1->addBook(b1);
			cout << "\nsetting owner completed\n";
		}
		else
			cout << "\nyou are not admin\n";
	}
	catch (string cmd) {
		cout << endl << cmd << endl;
	}
}

List<Book*> User::getList() {
	return this->book_list;
}

void User::printList() {
	
}
