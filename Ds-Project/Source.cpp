//#include "User.h"
//#include "Book.h"
#include "AvlTree.h"
#include "AvlTree.cpp"
using namespace std;
// Add kardan queue va handle kardanesh






int main() {
	/*Book b1("a", "a", "a", "a");
	Book b2("b", "b", "b", "b");
	Book b3("c", "c", "c", "c");
	User u1("a", "a", "admin", "1234", 1);
	User u2("b", "b", "b", "b", 2);
	User u3("c", "c", "c", "c", 3);
	u1.setOwner(&u3, &b1);
	u1.setOwner(&u3, &b2);
	u1.setOwner(&u3, &b3);
	u1.setOwner(&u2, &b3);
	u1.setOwner(&u1, &b3);
	u3.printList();
	u3.returnBook(&b1);
	u3.printList();
	b1.printBook();*/

	//this checks rr,ll,rl,lr rebalance
	AvlTree<int, string> tree;
	tree.insert(make_pair(100, "book1"));
	tree.insert(make_pair(200, "book1"));
	tree.insert(make_pair(300, "book1"));
	tree.insert(make_pair(50, "book1"));
	tree.insert(make_pair(25, "book1"));
	tree.insert(make_pair(250, "book1"));
	tree.insert(make_pair(350, "book1"));
	tree.insert(make_pair(101, "book1"));
	tree.insert(make_pair(99, "book1"));
	tree.insert(make_pair(98, "book1"));
	tree.insert(make_pair(275, "book1"));
	tree.insert(make_pair(225, "book1"));
	tree.insert(make_pair(280, "book1"));


}