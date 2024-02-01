#include "Controller.h"
using namespace std;

int main() {
	string name, pass, lname, username;
	int command;
	bool error = false;
	string err;
	while (1) {
		if (error)
			cout << err;
		error = false;
		cout << "1. sign up\n2. login\n3. exit\n";
		cin >> command;
		system("CLS");
		switch (command)
		{
		case 1:
			cout << "enter your name: ";
			cin >> name;
			cout << "enter your last name: ";
			cin >> lname;
			cout << "enter your username: ";
			cin >> username;
			cout << "enter your password: ";
			cin >> pass;
			Controller::add_user(name, lname, username, pass);
			break;
		case 2:
			cout << "enter your username: ";
			cin >> username;
			cout << "enter your password: ";
			cin >> pass;
			if (!Controller::searchUser(username, pass)) {
				error = true;
				err = "User not found!\n";
				continue;
			}
			break;
		case 3:
			return 0;
		}
		while (1) {
			string book_name, genre, date, writer;
			Book* book;
			User* user;
			if (error)
				cout << err;
			error = false;
			system("CLS");
			cout << "1. add book (admin)\n2. show my books\n3. search my books\n4. show all books\n"
				<< "5. search all books\n6. borrow book (admin)\n7. return book (admin)\n8. extend borrow (admin)";
			cin >> command;
			system("CLS");
			switch (command)
			{
			case 1:
				if (!Controller::isAdminControl()) {
					error = true;
					err = "you are not admin!\n";
					continue;
				}
				cout << "enter the book name: ";
				cin >> book_name;
				cout << "enter book genre: ";
				cin >> genre;
				cout << "enter the print date: ";
				cin >> date;
				cout << "enter writer name: ";
				cin >> writer;
				Controller::add_book(genre, book_name, date, writer);
				break;
			case 2:
				Controller::show_user_borrowed_books();
				break;
			case 3:
				
				break;
			case 4:
				Controller::show_all_books();
				break;
			case 5:
				cout << "enter the book name you want to search: ";
				cin >> book_name;
				book = Controller::search_book(book_name);
				if (book != nullptr) {
					book->printBook();
					cout << "press any keu to continue...";
					cin >> command;
				}
				else {
					error = true;
					err = "book was not found!\n";
					continue;
				}
				break;
			case 6:
				if (!Controller::isAdminControl()) {
					error = true;
					err = "you are not admin!\n";
					continue;
				}
				cout << "enter username: ";
				cin >> username;
				cout << "enter password: ";
				cin >> pass;
				cout << "enter book name: ";
				cin >> book_name;
				book = Controller::search_book(book_name);
				if (book == nullptr) {
					error = true;
					err = "book was not found!\n";
					continue;
				}
				user = Controller::getUser(username, pass);
				if (user == nullptr) {
					error = true;
					err = "no user found!\n";
					continue;
				}
				Controller::borrow_book(book, user);
				break;
			case 7:
				if (!Controller::isAdminControl()) {
					error = true;
					err = "you are not admin!\n";
					continue;
				}
				cout << "enter username: ";
				cin >> username;
				cout << "enter password: ";
				cin >> pass;
				cout << "enter book name: ";
				cin >> book_name;
				book = Controller::search_book(book_name);
				if (book == nullptr) {
					error = true;
					err = "book was not found!\n";
					continue;
				}
				user = Controller::getUser(username, pass);
				if (user == nullptr) {
					error = true;
					err = "no user found!\n";
					continue;
				}
				Controller::return_book(book, user);
				break;
			case 8:
				if (!Controller::isAdminControl()) {
					error = true;
					err = "you are not admin!\n";
					continue;
				}
				cout << "enter username: ";
				cin >> username;
				cout << "enter password: ";
				cin >> pass;
				cout << "enter book name: ";
				cin >> book_name;
				book = Controller::search_book(book_name);
				if (book == nullptr) {
					error = true;
					err = "book was not found!\n";
					continue;
				}
				user = Controller::getUser(username, pass);
				if (user == nullptr) {
					error = true;
					err = "no user found!\n";
					continue;
				}
				Controller::extendBorrow(user, book);
				break;
			}
		}
	}
}