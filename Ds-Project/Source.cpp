#include "Controller.h"
using namespace std;

int main() {
	string name, pass, lname, username;
	int command;
	bool error = false;
	string err;
	cout << "1. sign up\n2. login\n3. exit";
	cin >> command;
	while (1) {
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
			if (Controller::searchUser(username, pass)) {
				
			}
			break;
		case 3:
			return;
		}
	}
}