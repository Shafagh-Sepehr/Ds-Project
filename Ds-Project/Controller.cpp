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

	if ( book_tree_node == nullptr ) {
		//book not found
		Book *book = nullptr;
	}
	else {
		//book is the desired item
		Book *book = book_tree_node->get_data().second;
	}

}

void Controller::borrow_book(Book *book) {

	book->setBookOwner(logged_in_user->get_id());
	//logged_in_user->addBook();???


}

void Controller::return_book() {


}


