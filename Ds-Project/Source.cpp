using namespace std;
#include "User.h"
#include "Book.h"
int main() {
	Book b1("a", "a", "a", "a");
	Book b2("b", "b", "b", "b");
	Book b3("c", "c", "c", "c");
	User u1("a", "a", "admin", "1234", 1);
	User u2("b", "b", "b", "b", 1);
	User u3("c", "c", "c", "c", 1);
	u1.setOwner(&u3, &b1);
	u1.setOwner(&u2, &b1);
}