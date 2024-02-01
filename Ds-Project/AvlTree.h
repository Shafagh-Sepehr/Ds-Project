#pragma once
#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

template <typename K, typename D>
class TreeNode;

template <typename K, typename D>
class AvlTree {
private:
	TreeNode<K, D> *root;
	int _size;

	int node_height(TreeNode<K, D> *node) const;

	void check_balance(TreeNode<K, D> *node);
	bool is_node_balanced(const TreeNode<K, D> *node) const;
	TreeNode<K, D> *rebalance_node(TreeNode<K, D> *node);

	bool is_right_higher(const TreeNode<K, D> *node) const;

	TreeNode<K, D> *rebalance_rr(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node);
	TreeNode<K, D> *rebalance_ll(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node);
	TreeNode<K, D> *rebalance_rl(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node, TreeNode<K, D> *lower_node);
	TreeNode<K, D> *rebalance_lr(TreeNode<K, D> *upper_node, TreeNode<K, D> *middle_node, TreeNode<K, D> *lower_node);

	void get_sorted_values(TreeNode<K, D> *node, List<pair<K, D>> &list);

	static void erase_tree(TreeNode<K, D> *node);
public:
	AvlTree();
	~AvlTree();

	int size() const;
	bool empty() const;
	void erase();
	TreeNode<K, D> *insert(pair<K, D> data);
	D &operator[](K key);
	TreeNode<K, D> *find(K key);
	void get_sorted_list(List<pair<K, D>> &list);
	//void remove(K key);








};

template <typename K, typename D>
class TreeNode {
	friend AvlTree<K, D>;


private:
	pair<K, D> data;
	TreeNode<K, D> *parent;
	TreeNode<K, D> *left;
	TreeNode<K, D> *right;


public:
	TreeNode();
	TreeNode(pair<K, D> data);
	TreeNode(const TreeNode &that);
	~TreeNode();
	bool is_root() const;
	bool is_external() const;
	int height() const;
	TreeNode<K, D> *extend(pair<K, D> data);
	static TreeNode<K, D> *search(TreeNode<K, D> *node, K key);
	pair<K, D> &get_data();

	//void add_to_right(TreeNode *new_node);
	//void add_to_left(TreeNode *new_node);

};