#include "pch.h"
#include <iomanip>
#include "BinarySearchTree.h"
#include <exception>

BinarySearchTree::BinarySearchTree(const BinarySearchTree&)
{

}

// Insert a new Item into the Tree
// Smaller elements go left
// larger elements go right
void BinarySearchTree::Insert(int d)
{
	tree_node t;
	t.data = d;
	t.leftIndex  = -1;
	t.rightIndex = -1;

	// is this a new tree?
	if (ItemCount < 1)
	{
		tn.push_back(t);
		ItemCount++;
	}
	else
	{
		// Find the Node's parent by traversing the tree
		int curr = 0;
		int parent = 0;
		while (curr > -1)
		{
			parent = curr;
			if (t.data > tn[curr].data) 
				curr = tn[curr].rightIndex;
			else 
				curr = tn[curr].leftIndex;
		}

		// Push back the new item
		tn.push_back(t);
		int nIndex = tn.size() - 1;
		ItemCount++;

		// Point the parents pointer correctly
		// to the new data
		if (t.data < tn[parent].data)
			tn[parent].leftIndex = nIndex;
		else
			tn[parent].rightIndex = nIndex;
	}
}

void BinarySearchTree::print_inorder()
{
	inorder(0);
}

void BinarySearchTree::inorder(int indexItem)
{
	if (tn[indexItem].data)
	{
		// Drill Left
		if (tn[indexItem].leftIndex > -1)
			inorder(tn[indexItem].leftIndex);
		// Print value
		cout << " " << tn[indexItem].data << " ";
		// Drill Right
		if (tn[indexItem].rightIndex > -1)
			inorder(tn[indexItem].rightIndex);
	}
	else return;
}

void BinarySearchTree::prettyPrint(int indexItem, int indent)
{
	if (indexItem > ItemCount - 1)
		throw std::invalid_argument("indexItem");

	if (tn[indexItem].data)
	{
		if (tn[indexItem].rightIndex > -1) {
			prettyPrint(tn[indexItem].rightIndex, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (tn[indexItem].rightIndex) 
			std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << tn[indexItem].data << "\n ";
		if (tn[indexItem].leftIndex > -1)
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			prettyPrint(tn[indexItem].leftIndex, indent + 4);
		}
	}
}