#include "AvlTree.h"

TreeNode::TreeNode():data(long()), parent(nullptr), left(nullptr), right(nullptr) {

}

bool TreeNode::is_root() const {
	return this->parent == nullptr;
}

bool TreeNode::is_external() const {
	return this->left == nullptr && this->right == nullptr;
}

int TreeNode::height() const {
	if ( this->is_external() )
		return 0;
	else {
		int lh, rh;

		if ( this->left != nullptr )
			lh = left->height() + 1;

		if ( this->right != nullptr )
			rh = right->height() + 1;

		return max(lh, rh);
	}

}

void TreeNode::add_to_right(TreeNode *new_node) {
	if ( this->right != nullptr )
		throw exception("right node already created");
	else {
		this->right = new_node;
	}
}

void TreeNode::add_to_left(TreeNode *new_node) {
	if ( this->left != nullptr )
		throw exception("right node already created");
	else {
		this->left = new_node;
	}
}




