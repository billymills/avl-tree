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
	int test [5] = {10,10,10,10,5};
	for (int i = 0;i < 5;++i){
		newTree->insert(test[i]);
	}
	cout << "inserting 10,10,10,10,5" << endl;
	cout << "testing duplicate entries" << endl;
	cout << "tree print" << endl;
	newTree->treePrint();
	cout << "removing 10 from tree" << endl;
	newTree->remove(10);
	newTree->treePrint();
	cout << "removing 20 from tree to test non-existant value" << endl;
	newTree->remove(20);
	newTree->treePrint();
	delete newTree;	
	
	AVL<int>* newTree2 = new AVL<int>();
	int test2 [9] = {9,8,7,6,5,4,3,2,1};
	for (int i = 0;i < 9;++i){
		newTree2->insert(test2[i]);
	}
	cout << " " << endl;
	cout << "inserting 9,8,7,5,4,3,2,1 from quiz" << endl;
	cout << "tree print" << endl;
	newTree2->treePrint();
	delete newTree2;	
	
	AVL<int>* newTree3 = new AVL<int>();
	int test3 [5] = {5,10,15,12,11};
	for (int i = 0;i < 5;++i){
		newTree3->insert(test3[i]);
	}
	cout << " " << endl;
	cout << "inserting 5,10,15,12,11 from quiz" << endl;
	cout << "tree print" << endl;
	newTree3->treePrint();
	delete newTree3;	
	
	AVL<int>* newTree4 = new AVL<int>();
	int test4 [5] = {5,3,10,15,13};
	for (int i = 0;i < 5;++i){
		newTree4->insert(test4[i]);
	}
	cout << " " << endl;
	cout << "inserting 5,3,10,15,13 from class example" << endl;
	cout << "tree print" << endl;
	newTree4->treePrint();
	delete newTree4;	
	
	AVL<int>* newTree5 = new AVL<int>();
	int test5 [10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0;i < 10;++i){
		newTree5->insert(test5[i]);
	}
	cout << " " << endl;
	cout << "inserting 1,2,3,4,5,6,7,8,9,10 from class example" << endl;
	cout << "tree print" << endl;
	newTree5->treePrint();
	delete newTree5;	
	
	AVL<int>* newTree6 = new AVL<int>();
	int test6 [10] = {3,2,1,4,5,6,7,16,15,14};
	for (int i = 0;i < 10;++i){
		newTree6->insert(test6[i]);
	}
	cout << " " << endl;
	cout << "inserting 3,2,1,4,5,6,7,16,15,14 from class example" << endl;
	cout << "tree print" << endl;
	newTree6->treePrint();
	delete newTree6;	
	
	AVL<int>* newTree7 = new AVL<int>();
	int test7 [10] = {186,39,991,336,778,66,564,154,538,645};
	for (int i = 0;i < 10;++i){
		newTree7->insert(test7[i]);
	}
	cout << " " << endl;
	cout << "inserting 186,39,991,336,778,66,564,154,538,645 from book example" << endl;
	cout << "tree print" << endl;
	newTree7->treePrint();
	cout << "remove 186 as in book example" << endl;
	newTree7->remove(186);
	newTree7->treePrint();
	delete newTree7;	
}
