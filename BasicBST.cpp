// BasicBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(4);
	bst.Insert(6);
	bst.Insert(8);
	bst.Insert(10);
	bst.Insert(21);
	bst.Insert(15);
	bst.Insert(18);

	bst.print_inorder();

	cout << endl;

	bst.prettyPrint(0, 4);

}

