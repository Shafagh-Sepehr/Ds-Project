#include "Controller.h"
#include <conio.h>
User *Controller::logged_in_user = nullptr;

void Controller::add_user(string name, string lname, string username, string pass) {

	User *new_user = new User(name, lname, username, pass);

	logged_in_user = new_user;
}

void Controller::add_book(string genre, string name, string date, string writer) {

	Book *new_book = new Book(genre, name, date, writer);
}

Book *Controller::search_book(string name) {

	AvlTree<string, Book *> book_tree;

	if ( Book::get_books_list().empty() )
		return nullptr;

	for ( auto book_node : Book::get_books_list() ) {
		book_tree.insert(make_pair(book_node->get_data()->get_name(), book_node->get_data()));
	}

	auto book_tree_node = book_tree.find(name);
	Book *book;

	if ( book_tree_node == nullptr ) {
		//book not found
		book = nullptr;
	}
	else {
		//book is the desired item
		book = book_tree_node->get_data().second;
	}
	return book;
}

Book *Controller::search_user_borrowed_book(string name) {
	AvlTree<string, Book *> book_tree;

	if ( (*logged_in_user->get_book_list()).empty())
		return nullptr;

	for ( auto book_node : *logged_in_user->get_book_list() ) {
		book_tree.insert(make_pair(book_node->get_data()->book->get_name(), book_node->get_data()->book));
	}

	auto book_tree_node = book_tree.find(name);
	Book *book;

	if ( book_tree_node == nullptr ) {
		//book not found
		book = nullptr;
	}
	else {
		//book is the desired item
		book = book_tree_node->get_data().second;
	}
	return book;
}


User *Controller::getUser(string username, string pass) {
	for ( int i = 0; i < logged_in_user->get_users_list().size(); i++ )
		if ( logged_in_user->get_users_list()[i]->checkLogin(username, pass) )
			return logged_in_user->get_users_list()[i];
	return nullptr;
}

void Controller::borrow_book(Book *book, User *user) {

	if ( logged_in_user->isAdmin() && book ) {
		if ( book->isThisMyTurn(user->get_id()) ) {
			if ( book->setBookOwner(user->get_id()) ) {
				cout << "\nthis book is reserved succesfully\npress any key to continue...\n";
				_getch();
				return;
			}
			user->addBook(book);
			cout << "\nsetting owner completed\n";
		}
		else
			cout << "\nit is not your turn!\n";
	}
	else
		cout << "\nyou are not admin or the book was not found!\n";
	_getch();


}

void Controller::return_book(Book *book, User *user) {
	string tmp;
	List<element *>* bookList = user->get_book_list();
	for ( int i = 0; i < bookList->size(); i++ )
		if ( (*bookList)[i]->book == book) {
			element *elem = (*bookList)[i];
			elem->book->setOwner(0);
			auto currentTime = std::chrono::system_clock::now();
			std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
			std::tm *currentTime_tm = std::localtime(&currentTime_t);
			int day = currentTime_tm->tm_mday;
			int month = currentTime_tm->tm_mon;
			int year = currentTime_tm->tm_year;
			int years_passed = year - elem->year;
			int monthes_passed = month - elem->month;
			int days_passed = day - elem->day + 30 * monthes_passed + 360 * years_passed;
			days_passed -= 10;
			if ( days_passed > 0 ) {
				cout << "\nyour fine is: " << days_passed * 5 << "t\npress any key to continue...\n";
				cin >> tmp;
			}
			elem->book->setDate(day, month, year);
			bookList->erase(i);
			return;
		}
}

List<pair<string, Book>> Controller::show_user_borrowed_books() {

	List<element *>* elem_list = logged_in_user->get_book_list();
	AvlTree<string, Book> book_tree;
	for ( auto i : *elem_list ) {
		book_tree.insert(make_pair(i->get_data()->book->get_name(), *(i->get_data()->book)));
	}

	List<pair<string, Book>> book_list;
	book_tree.get_sorted_list(book_list);
	return book_list;
}

List<pair<string, Book>> Controller::show_all_books() {

	AvlTree<string, Book> book_tree;
	for ( auto i : Book::get_books_list() ) {
		book_tree.insert(make_pair(i->get_data()->get_name(), *(i->get_data())));
	}

	List<pair<string, Book>> book_list;
	book_tree.get_sorted_list(book_list);
	return book_list;

}

void Controller::extendBorrow(User *user, Book *book) {
	string tmp;
	if ( book->isQueueEmpty() ) {
		user->extend(book);
		cout << "\nextension completed\npress any key to continue...\n";
		cin >> tmp;
		return;
	}
	cout << "\nextension failed\npress any key to continue...\n";
	cin >> tmp;
}

bool Controller::isAdminControl() {
	return logged_in_user->isAdmin();
}



bool Controller::searchUser(string username, string pass) {
	/*for ( int i = 0; i < User::get_users_list().size(); i++ )
		if ( User::get_users_list()[i]->checkLogin(username, pass) ) {
			logged_in_user = logged_in_user->get_users_list()[i];
			return true;
		}*/
	for ( auto i : User::get_users_list() )
		if ( i->get_data()->checkLogin(username, pass) ) {
			logged_in_user = i->get_data();
			return true;
		}
	return false;
}


