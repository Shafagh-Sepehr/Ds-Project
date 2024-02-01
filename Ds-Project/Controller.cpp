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
	Book* book;

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

void Controller::borrow_book(Book *book) {

	if (logged_in_user->isAdmin()) {
		if (book->setBookOwner(logged_in_user->get_id())) {
			cout << "\nthis book is reserved succesfully\n";
			return;
		}
		logged_in_user->addBook(book);
		cout << "\nsetting owner completed\n";
	}
	else
		cout << "\nyou are not admin!\n";


}

void Controller::return_book(element book) {
	List<element> bookList = logged_in_user->get_book_list();
	for (int i = 0; i < bookList.size(); i++)
		if (bookList[i].book == book.book) {
			bookList.erase(i);
			return;
		}
}


