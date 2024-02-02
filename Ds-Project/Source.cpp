#include "Controller.h"
#include <conio.h>
using namespace std;

int main() {
	string name, pass, lname, username;
	int command;

	bool logout = false;

	while ( 1 ) {
		cout << "1. sign up\n2. login\n3. exit\n";
		cin >> command;
		system("CLS");
		switch ( command ) {
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
				if ( !Controller::searchUser(username, pass) ) {
					cout << "User not found!\n";
					continue;
				}
				break;
			case 3:
				return 0;
		}
		while ( 1 ) {
			string book_name, genre, date, writer;
			Book *book;
			User *user;
			List<pair<string, Book>> list;

			system("CLS");
			cout << "1. add book (admin)\n2. show my books\n3. search my books\n4. show all books\n"
				<< "5. search all books\n6. borrow book (admin)\n7. return book (admin)\n8. extend borrow (admin)\n9. logout\n";
			cin >> command;
			system("CLS");
			switch ( command ) {
				case 1:
					if ( !Controller::isAdminControl() ) {
						cout << "you are not admin!\n";
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
					list = Controller::show_user_borrowed_books();
					if ( !list.empty() ) {
						for ( int i = 0; i < list.size(); i++ )
							list[i].second.printBook();
						cout << "press any key to continue...\n";
						cin >> command;
					}
					break;
				case 3:
					cout << "enter the book name you want to search: ";
					cin >> book_name;
					book = Controller::search_user_borrowed_book(book_name);
					if ( book != nullptr ) {
						book->printBook();
					}
					else {
						cout << "book was not found!\n";
					}
					cout << "press any keu to continue...";
					_getch();
					break;
				case 4:
					list = Controller::show_all_books();
					if ( !list.empty() ) {
						for ( int i = 0; i < list.size(); i++ )
							list[i].second.printBook();
					}
					else {
						cout << "there's no books";
					}
					cout << "press any key to continue...\n";
					_getch();
					break;
				case 5:
					cout << "enter the book name you want to search: ";
					cin >> book_name;
					book = Controller::search_book(book_name);
					if ( book != nullptr ) {
						book->printBook();

					}
					else {
						cout << "book was not found!\n";
					}
					cout << "press any keu to continue...";
					_getch();
					break;
				case 6:
					if ( !Controller::isAdminControl() ) {
						cout << "you are not admin!\n";
						continue;
					}
					cout << "enter username: ";
					cin >> username;
					cout << "enter password: ";
					cin >> pass;
					cout << "enter book name: ";
					cin >> book_name;
					book = Controller::search_book(book_name);
					user = Controller::getUser(username, pass);
					if ( book == nullptr ) {
						cout << "book was not found!\n";

					}
					else if ( user == nullptr ) {
						cout << "no user found!\n";
					}
					else
						Controller::borrow_book(book, user);

					cout << "press any keu to continue...";
					_getch();

					break;

				case 7:
					if ( !Controller::isAdminControl() ) {
						cout << "you are not admin!\n";
						cout << "press any keu to continue...";
						_getch();
						continue;
					}
					cout << "enter username: ";
					cin >> username;
					cout << "enter password: ";
					cin >> pass;
					cout << "enter book name: ";
					cin >> book_name;
					book = Controller::search_book(book_name);
					if ( book == nullptr ) {
						cout << "book was not found!\n";
						cout << "press any keu to continue...";
						_getch();
						continue;

					}
					user = Controller::getUser(username, pass);
					if ( user == nullptr ) {
						cout << "no user found!\n";
						cout << "press any keu to continue...";
						_getch();
						continue;

					}
					Controller::return_book(book, user);
					break;
				case 8:
					if ( !Controller::isAdminControl() ) {
						cout << "you are not admin!\n";
						continue;
					}
					cout << "enter username: ";
					cin >> username;
					cout << "enter password: ";
					cin >> pass;
					cout << "enter book name: ";
					cin >> book_name;
					book = Controller::search_book(book_name);
					if ( book == nullptr ) {

						cout << "book was not found!\n";
						cout << "press any keu to continue...";
						_getch();
						continue;
					}
					user = Controller::getUser(username, pass);
					if ( user == nullptr ) {
						cout << "no user found!\n";
						cout << "press any keu to continue...";
						_getch();
						continue;
					}
					Controller::extendBorrow(user, book);
					break;
				case 9:
					logout = true;
					break;
			}
			if ( logout ) {
				logout = false;
				break;
			}
			//_getch();
		}

	}
}