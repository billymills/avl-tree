//filename:	AVL.cpp
//descrip:	implementation file for avl tree
//author:	Billy Mills
//date:		Fall 2012

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include "AVL.h"

using std::cout;
using std::endl;
using std::max;
using std::vector;

template <typename T>
AVL<T>::AVL(){
	root = 0;	
}	

template <typename T>
AVL<T>::~AVL(){
	postOrderDelete(root);
}

template <typename T>
void AVL<T>::postOrderDelete(Node<T>* n){
	if (n != 0){
		postOrderDelete(n->getLeftChild());
		postOrderDelete(n->getRightChild());
		delete n;
	}
}

template <typename T>
bool AVL<T>::find(T v){

}

template <typename T>
void AVL<T>::insert(T v){
	Node<T>* newNode = new Node<T>(v);
	Node<T>* curr = root;
	Node<T>* prev = root;
	Node<T>* cnode = root;

	//insert root
	if (curr == 0){
		root = newNode;
		//cnode = root;
	}

	//everthing else
	else {
		while (curr != 0){
			//look for critical node on each move
			if (prev != 0 && (prev->checkBalance() == 1 || prev->checkBalance() == -1)){
				cnode = prev;
			}
			if (v < curr->getValue()){
				prev = curr;
				curr = curr->getLeftChild();
			}
			else if (v > curr->getValue()){
				prev = curr;				
				curr = curr->getRightChild();

			}
		}//end while
		
		if(prev->getValue() > v){
			prev->setLeftChild(newNode);
		}
		else {
			prev->setRightChild(newNode);
		}
	
		//check cnode balance
		cnode->setBalance(getBalance(cnode));
		if (cnode->getRightChild() != 0){
			cnode->getRightChild()->setBalance(getBalance(cnode->getRightChild()));
		}
		if (cnode->getLeftChild() != 0){
			cnode->getLeftChild()->setBalance(getBalance(cnode->getLeftChild()));
		}
		
		//check critical node if 2 left rotate
		if (cnode->checkBalance() == 2){
			if (cnode->getRightChild()->checkBalance() < 0){
				cout << "in if for dbl" << endl;
				rightRotate(cnode->getRightChild());
				cout << "back from first rotation" << endl;
			}
			leftRotate(cnode);
		}
		else if (cnode->checkBalance() == -2){
			if (cnode->getLeftChild()->checkBalance() > 0){
				leftRotate(cnode->getLeftChild());
			}
			rightRotate(cnode);
		}
	}//end outer else
}


template <typename T>
void AVL<T>::remove(T v){
	assert (root != 0);
	Node<T>* curr = root;

	//handle root
	if(curr->getValue() == v){
		//case 1 there are no children
		//no need to store anything
		if(curr->getLeftChild() == 0 && curr->getRightChild() == 0){
			root = 0;
		}
		//case 2 there is one child
		if(curr->getLeftChild() !=0 && curr->getRightChild() == 0){
			root = curr->getLeftChild();
		}
		//else there is a right child but no left child
		else{
			root = curr->getRightChild();
		}
	}
}

template <typename T>
void AVL<T>::treePrint(){
	bool isEmptyLevel = false;
	int numLevels = 0;

	vector<vector<Node<T>* > > levelVector;
	vector<Node<T>* > currLevel(1, root);

	if (currLevel[0] == 0){
		isEmptyLevel = true;
	}
	else{
		levelVector.push_back(currLevel);
		numLevels++;
	}

	while (isEmptyLevel == false){
		currLevel.resize(2*levelVector[numLevels-1].size());
		for (unsigned int i = 0;i < levelVector[numLevels-1].size(); ++i){
			if (levelVector[numLevels-1][i] != 0){
				currLevel[2*i] = levelVector[numLevels-1][i]->getLeftChild();
				currLevel[2*i+1] = levelVector[numLevels-1][i]->getRightChild();
			}
			else{
				currLevel[2*i] = 0;
				currLevel[2*i+1] = 0;
			}
		}
		for (unsigned int i = 0;i < currLevel.size(); ++i){
			if (currLevel[i] != 0){
				isEmptyLevel = false;
				break;
			}
		isEmptyLevel = true;
		}
		if (isEmptyLevel == false){
			levelVector.push_back(currLevel);
			numLevels++;
		}
	}
	
	for (unsigned int i = 0;i < levelVector.size();++i){
		for (unsigned int j = 0;j < levelVector[i].size();++j){
			if (levelVector[i][j] != 0){
				cout << levelVector[i][j]->getValue() << " ";
			}
			else{
				cout << "x ";
			}
		}
		cout << endl;
	}
}

template <typename T>
void AVL<T>::postOrderTraversal(){	
	postOrderHelper(root);
}

template <typename T>
void AVL<T>::inOrderTraversal(){
	inOrderHelper(root);
}

template <typename T>
void AVL<T>::postOrderHelper(Node<T>* rt){
	if(rt != 0){
		postOrderHelper(rt->getLeftChild());
		postOrderHelper(rt->getRightChild());
		cout << rt->getValue() << endl;
	}
}

template <typename T>
void AVL<T>::inOrderHelper(Node<T>* rt){
	if(rt != 0){
		inOrderHelper(rt->getLeftChild());
		cout << rt->getValue() << endl;
		inOrderHelper(rt->getRightChild());
	}
}

template <typename T>
Node<T>* AVL<T>::findParent(T v, Node<T>* n){
	Node<T>* temp = n;
	while (temp != 0){
		//cout << "in while loop" << endl;
		if ((temp->getRightChild() != 0 && temp->getRightChild()->getValue() == v) 
			|| (temp->getLeftChild() != 0 && temp->getLeftChild()->getValue() == v)){
			return temp;
		}
		if (v < temp->getValue()){
			temp = temp->getLeftChild();
		}
		else {
			temp = temp->getRightChild();
		}
	}
	return temp;
}

template <typename T>
int AVL<T>::getBalance(Node<T>* n){
	int lh = getHeight(n->getLeftChild());
	int rh = getHeight(n->getRightChild());
	return rh - lh;
}	

template <typename T>
int AVL<T>::getHeight(Node<T>* n){
	if (n == 0){
		return 0;
	}
	else {
		return max(getHeight(n->getLeftChild()), getHeight(n->getRightChild())) +1;
	}
}

template <typename T>
//Node<T>* AVL<T>::leftRotate(Node<T>* n){
void AVL<T>::leftRotate(Node<T>* n){
	Node<T>* tempRC = n->getRightChild();
	Node<T>* tempLC = tempRC->getLeftChild();
	tempRC->setLeftChild(n);
	if (root == n){
		root = tempRC;
	}
	else {	
		Node<T>* parent = findParent(n->getValue(), root);
		if (parent->getValue() < n->getValue()){
			parent->setRightChild(tempRC);
		}
		else {
			parent->setLeftChild(tempRC);
		}
	}
	
	n->setRightChild(tempLC);
	//update balances
	n->setBalance(getBalance(n));
	tempRC->setBalance(getBalance(tempRC));
	tempRC->getRightChild()->setBalance(getBalance(tempRC->getRightChild()));
}

template <typename T>
void AVL<T>::rightRotate(Node<T>* n){	
	Node<T>* tempLC = n->getLeftChild();
	Node<T>* tempRC = tempLC->getRightChild();
	tempLC->setRightChild(n);
	if (root == n){
		root = tempLC;
	}
	else {
		Node<T>* parent = findParent(n->getValue(), root);
		if (parent->getValue() > n->getValue()){
			parent->setLeftChild(tempLC);
		}
		else {
			parent->setRightChild(tempLC);
		}
	}
	
	n->setLeftChild(tempRC);
	//update balances
	n->setBalance(getBalance(n));
	tempLC->setBalance(getBalance(tempLC));
	tempLC->getLeftChild()->setBalance(getBalance(tempLC->getLeftChild()));
}

template <typename T>
void AVL<T>::testRotate(){
	leftRotate(root->getRightChild());
	cout << "returned from rotate" << endl;
}

template class AVL<int>;
