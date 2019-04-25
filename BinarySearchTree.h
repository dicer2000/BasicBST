#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "tree_node.h"

using namespace std;

class BinarySearchTree
{
private:
	int ItemCount;
	vector<tree_node> tn;
	void inorder(int indexItem);
public:
	BinarySearchTree() { ItemCount = 0; }
	~BinarySearchTree() { tn.clear(); }
	BinarySearchTree(const BinarySearchTree&);

	bool isEmpty() { return (this->ItemCount > 0); }
	void Insert(int);
	void print_inorder();
	void prettyPrint(int indexItem, int indent);
	int getItemCount() { return ItemCount; }

	/*
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void remove(int);
	*/
};