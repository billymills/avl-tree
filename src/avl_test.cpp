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
	int test [9] = {9,8,7,6,5,4,3,2,1};
	for (int i = 0;i < 9;++i){
		newTree->insert(test[i]);
	}
	cout << "postOrder print" << endl;
	newTree->postOrderTraversal();
	cout << "inOrder print" << endl;
	newTree->inOrderTraversal();
	cout << "tree print" << endl;
	newTree->treePrint();
	delete newTree;	
	
}
