//filename:	avl_test.cpp
//descrip:	test file for avl tree
//author:	Billy Mills
//date;		Fall 2012

#include <iostream>
#include "Node.h"
#include "AVL.h"

using std::cout;
using std::endl;

int main(){
	AVL<int>* newTree = new AVL<int>();
	newTree->insert(10);
	newTree->insert(20);
	cout << "inserted 20" << endl;
	newTree->insert(30);
	cout << "inserted 30" << endl;
	newTree->insert(40);
	cout << "inserted 40" << endl;
	newTree->insert(35);
	newTree->postOrderTraversal();
	newTree->inOrderTraversal();
	
}
