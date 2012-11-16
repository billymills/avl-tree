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
	int test [10] = {186,39,991,336,778,066,564,154,538,645};
	for (int i = 0;i < 10;++i){
		newTree->insert(test[i]);
	}
	//cout << "postOrder print" << endl;
	//newTree->postOrderTraversal();
	//cout << "inOrder print" << endl;
	//newTree->inOrderTraversal();
	cout << "tree print" << endl;
	newTree->treePrint();
	newTree->remove(538);
	newTree->treePrint();
	delete newTree;	
	
}
