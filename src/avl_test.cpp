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
	int test [5] = {10,20,10,5,25};
	for (int i = 0;i < 5;++i){
		newTree->insert(test[i]);
	}
	//cout << "postOrder print" << endl;
	//newTree->postOrderTraversal();
	//cout << "inOrder print" << endl;
	//newTree->inOrderTraversal();
	cout << "tree print" << endl;
	//newTree->treePrint();
	//newTree->remove(538);
	newTree->treePrint();
	delete newTree;	
	
}
