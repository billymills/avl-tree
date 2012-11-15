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
	newTree->insert(5);
	newTree->insert(15);
	newTree->insert(4);
	newTree->insert(17);
	newTree->insert(12);
	newTree->insert(11);
	newTree->treePrint();
	newTree->remove(10);
	newTree->treePrint();
	delete newTree;	
}
