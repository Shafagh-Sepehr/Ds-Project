using namespace std;
#include "User.h"
#include "Book.h"
// Add kardan queue va handle kardanesh
int main() {
	Book b1("a", "a", "a", "a");
	Book b2("b", "b", "b", "b");
	Book b3("c", "c", "c", "c");
	User u1("a", "a", "admin", "1234", 1);
	User u2("b", "b", "b", "b", 1);
	User u3("c", "c", "c", "c", 1);
	u1.setOwner(&u3, &b1);
	u1.setOwner(&u3, &b2);
	u1.setOwner(&u3, &b3);
	u3.printList();
	u3.returnBook(&b1);
	u3.printList();
	b1.printBook();
}