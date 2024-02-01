#pragma once
#include "AvlTree.h"


template <typename K, typename D>
TreeNode<K, D>::TreeNode():data(pair<K, D>()), parent(nullptr), left(nullptr), right(nullptr) {}

template<typename K, typename D>
TreeNode<K, D>::TreeNode(pair<K, D> data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}

template<typename K, typename D>
TreeNode<K, D>::TreeNode(const TreeNode &that) : data(that.data), parent(that.parent), left(that.left), right(that.right) {}

template<typename K, typename D>
TreeNode<K, D>::~TreeNode() = default;

template <typename K, typename D>
bool TreeNode<K, D>::is_root() const {
	return this->parent == nullptr;
}

template <typename K, typename D>
bool TreeNode<K, D>::is_external() const {
	return this->left == nullptr && this->right == nullptr;
}

template <typename K, typename D>
int TreeNode<K, D>::height() const {
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

template<typename K, typename D>
TreeNode<K, D> *TreeNode<K, D>::extend(pair<K, D> data) {
	TreeNode<K, D> *return_val = nullptr;
	if ( data.first > this->data.first ) {
		if ( this->right == nullptr ) {
			this->right = new TreeNode<K, D>(data);
			this->right->parent = this;
			return this->right;
		}
		else
			return this->right->extend(data);
	}
	else {
		if ( this->left == nullptr ) {
			this->left = new TreeNode<K, D>(data);
			this->left->parent = this;
			return this->left;
		}
		else
			return this->left->extend(data);
	}
}

template<typename K, typename D>
TreeNode<K, D> *TreeNode<K, D>::search(TreeNode<K, D> *node, K key) {
	if ( node == nullptr )
		return nullptr;
	else if ( node->data.first == key )
		return node;
	else if ( node->data.first < key )
		return search(node->right, key);
	else
		return search(node->left, key);
}

template<typename K, typename D>
pair<K, D> &TreeNode<K, D>::get_data() {
	return data;
}


//template <typename K, typename D>
//void TreeNode<K, D>::add_to_right(TreeNode *new_node) {
//	if ( this->right != nullptr )
//		throw exception("right node already created");
//	else {
//		this->right = new_node;
//	}
//}
//
//template <typename K, typename D>
//void TreeNode<K, D>::add_to_left(TreeNode *new_node) {
//	if ( this->left != nullptr )
//		throw exception("right node already created");
//	else {
//		this->left = new_node;
//	}
//}


template<typename K, typename D>
AvlTree<K, D>::AvlTree(): root(nullptr), _size(0) {}

template<typename K, typename D>
AvlTree<K, D>::~AvlTree() {
	erase();
}

template<typename K, typename D>
void AvlTree<K, D>::erase() {
	erase_tree(root);
	root = nullptr;
}

template<typename K, typename D>
int AvlTree<K, D>::size() const {
	return _size;
}

template<typename K, typename D>
bool AvlTree<K, D>::empty() const {
	return _size == 0;
}

template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::insert(pair<K, D> data) {
	this->_size++;
	TreeNode<K, D> *new_node = nullptr;
	if ( root == nullptr ) {
		root = new TreeNode<K, D>(data);
		return root;
	}
	else {
		new_node = root->extend(data);
		check_balance(new_node);
		return new_node;
	}

}

template<typename K, typename D>
D &AvlTree<K, D>::operator[](K key) {
	TreeNode<K, D> *node = this->find(key);

	if ( node == nullptr )
		node = this->insert(make_pair(key, D()));

	return node->get_data().second;

}

template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::find(K key) {
	return TreeNode<K, D>::search(root, key);
}

template<typename K, typename D>
void AvlTree<K, D>::check_balance(TreeNode<K, D> *node) {
	while ( node != nullptr ) {
		if ( !is_node_balanced(node) )
			node = rebalance_node(node);
		node = node->parent;
	}
}

template<typename K, typename D>
bool AvlTree<K, D>::is_node_balanced(const TreeNode<K, D> *node) const {
	return abs(node_height(node->left) - node_height(node->right)) < 2;
}

template<typename K, typename D>
int AvlTree<K, D>::node_height(TreeNode<K, D> *node) const {
	return (node == nullptr) ? (-1) : (node->height());
}


template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::rebalance_node(TreeNode<K, D> *node) {

	if ( is_right_higher(node) && is_right_higher(node->right) )
		return rebalance_rr(node,
			node->right);

	else if ( is_right_higher(node) && !is_right_higher(node->right) )
		return rebalance_rl(node,
			node->right,
			node->right->left);

	else if ( !is_right_higher(node) && is_right_higher(node->left) )
		return rebalance_lr(node,
			node->left,
			node->left->right);

	else if ( !is_right_higher(node) && !is_right_higher(node->left) )
		return rebalance_ll(node,
			node->left);
}

template<typename K, typename D>
bool AvlTree<K, D>::is_right_higher(const TreeNode<K, D> *node) const {
	return node_height(node->right) > node_height(node->left);
}

template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::rebalance_rr(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node) {
	if ( !upper_node->is_root() ) {

		bool upper_is_right = (upper_node->parent->right == upper_node) ? (true) : (false);

		if ( upper_is_right )
			upper_node->parent->right = middle_node;
		else
			upper_node->parent->left = middle_node;
	}
	else {
		root = middle_node;
	}
	middle_node->parent = upper_node->parent;

	upper_node->right = middle_node->left;
	if ( middle_node->left != nullptr )
		middle_node->left->parent = upper_node;

	middle_node->left = upper_node;
	upper_node->parent = middle_node;

	return middle_node;
}

template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::rebalance_ll(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node) {
	if ( !upper_node->is_root() ) {

		bool upper_is_right = (upper_node->parent->right == upper_node) ? (true) : (false);

		if ( upper_is_right )
			upper_node->parent->right = middle_node;
		else
			upper_node->parent->left = middle_node;
	}
	else {
		root = middle_node;
	}
	middle_node->parent = upper_node->parent;

	upper_node->left = middle_node->right;
	if ( middle_node->right != nullptr )
		middle_node->right->parent = upper_node;

	middle_node->right = upper_node;
	upper_node->parent = middle_node;

	return middle_node;
}

template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::rebalance_rl(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node, TreeNode<K, D> *lower_node) {
	if ( !upper_node->is_root() ) {

		bool upper_is_right = (upper_node->parent->right == upper_node) ? (true) : (false);

		if ( upper_is_right )
			upper_node->parent->right = lower_node;
		else
			upper_node->parent->left = lower_node;
	}
	else {
		root = lower_node;
	}
	lower_node->parent = upper_node->parent;

	upper_node->right = lower_node->left;
	if ( lower_node->left != nullptr )
		lower_node->left->parent = upper_node;

	middle_node->left = lower_node->right;
	if ( lower_node->right != nullptr )
		lower_node->right->parent = middle_node;

	lower_node->right = middle_node;
	middle_node->parent = lower_node;

	lower_node->left = upper_node;
	upper_node->parent = lower_node;

	return lower_node;
}

template<typename K, typename D>
TreeNode<K, D> *AvlTree<K, D>::rebalance_lr(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node, TreeNode<K, D> *lower_node) {
	if ( !upper_node->is_root() ) {
		bool upper_is_right = (upper_node->parent->right == upper_node) ? (true) : (false);

		if ( upper_is_right )
			upper_node->parent->right = lower_node;
		else
			upper_node->parent->left = lower_node;
	}
	else {
		root = lower_node;
	}

	lower_node->parent = upper_node->parent;

	upper_node->left = lower_node->right;
	if ( lower_node->right != nullptr )
		lower_node->right->parent = upper_node;

	middle_node->right = lower_node->left;
	if ( lower_node->left != nullptr )
		lower_node->left->parent = middle_node;

	lower_node->left = middle_node;
	middle_node->parent = lower_node;

	lower_node->right = upper_node;
	upper_node->parent = lower_node;

	return lower_node;
}

template<typename K, typename D>
void AvlTree<K, D>::erase_tree(TreeNode<K, D> *node) {
	if ( node != nullptr ) {
		TreeNode<K, D> *left = node->left;
		TreeNode<K, D> *right = node->right;

		delete node;

		erase_tree(left);
		erase_tree(right);
	}
}


