#include "User.h"

int User::code = 0;
List<User *> User::users = List<User *>();

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
	element *tmp = new element;
	tmp->book = b1;
	tmp->day = day;
	tmp->month = month;
	tmp->year = year;
	this->book_list.push_back(tmp);
}

int User::get_id() {
	return id;
}

List<element *> *User::get_book_list() {
	return &this->book_list;
}

void User::extend(Book *book) {
	for ( int i = 0; i < this->book_list.size(); i++ )
		if ( this->book_list[i]->book == book ) {
			this->book_list[i]->day += 3;
			if ( this->book_list[i]->day > 30 ) {
				this->book_list[i]->day -= 30;
				this->book_list[i]->month++;
				if ( this->book_list[i]->month > 12 ) {
					this->book_list[i]->month -= 12;
					this->book_list[i]->year++;
				}
			}
		}
}

bool User::isAdmin() {
	return this->admin;
}

List<User *> User::get_users_list() {
	return users;
}

bool User::checkLogin(string username, string pass) {
	return this->username == username && this->password == pass;
}

string User::get_username() {
	return username;
}
