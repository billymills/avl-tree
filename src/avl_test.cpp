//filename:	avl_test.cpp
//descrip:	test file for avl tree
//author:	Billy Mills
//date;		Fall 2012

#include <iostream>
#include "Node.h"
#include "AVL.h"


int main(){
	AVL<int>* newTree = new AVL<int>();
	newTree->insert(10);
	newTree->insert(15);
	newTree->insert(20);
	newTree->insert(30);
	newTree->insert(5);
	newTree->insert(4);
	newTree->insert(3);
	newTree->print();

	AVL<int>* newerTree = new AVL<int>();
	newerTree->insert(10);
	newerTree->print();
}
