#include "Controller.h"

void Controller::add_user(string name, string lname, string username, string pass) {

	User *new_user = new User(name, lname, username, pass);

	logged_in_user = new_user;
}

void Controller::add_book(string genre, string name, string date, string writer) {

	Book *new_book = new Book(genre, name, date, writer);
}

Book *Controller::search_book(string name) {

	AvlTree<string, Book *> book_tree;

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

void Controller::borrow_book(Book *book, User *user) {

	if ( logged_in_user->isAdmin() && book ) {
		if ( book->isThisMyTurn(user->get_id()) ) {
			if ( book->setBookOwner(user->get_id()) ) {
				cout << "\nthis book is reserved succesfully\n";
				return;
			}
			logged_in_user->addBook(book);
			cout << "\nsetting owner completed\n";
		}
		else
			cout << "\nit is not your turn!\n";
	}
	else
		cout << "\nyou are not admin or the book was not found!\n";


}

void Controller::return_book(element book) {
	List<element> bookList = logged_in_user->get_book_list();
	for ( int i = 0; i < bookList.size(); i++ )
		if ( bookList[i].book == book.book ) {
			book.book->setOwner(0);
			auto currentTime = std::chrono::system_clock::now();
			std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
			std::tm *currentTime_tm = std::localtime(&currentTime_t);
			int day = currentTime_tm->tm_mday;
			int month = currentTime_tm->tm_mon;
			int year = currentTime_tm->tm_year;
			int years_passed = year - book.year;
			int monthes_passed = month - book.month;
			int days_passed = day - book.day + 30 * monthes_passed + 360 * years_passed;
			days_passed -= 10;
			if ( days_passed > 0 )
				cout << "\nyour fine is: " << days_passed * 5 << "t\n";
			book.book->setDate(day, month, year);
			bookList.erase(i);
			return;
		}
}

void Controller::show_user_borrowed_books() {

	List<element *> elem_list = logged_in_user->get_book_list();




}


