#pragma once
#include <iostream>
using namespace std;

class TreeNode {
private:
	long data;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;

public:
	TreeNode();
	bool is_root() const;
	bool is_external() const;
	int height() const;
	void add_to_right(TreeNode *new_node);
	void add_to_left(TreeNode *new_node);

};


class AvlTree {










};

