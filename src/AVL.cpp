//filename:	AVL.cpp
//descrip:	implementation file for avl tree
//author:	Billy Mills
//date:		Fall 2012

#include <iostream>
#include <algorithm>
#include "AVL.h"

using std::cout;
using std::endl;
using std::max;

template <typename T>
AVL<T>::AVL(){
	root = 0;	
}	

template <typename T>
AVL<T>::~AVL(){

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
				cout << "in cnode assignment" << endl;
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
	
		//update all balances
		cnode->setBalance(getBalance(cnode));
		if (cnode->getRightChild() != 0){
			cnode->getRightChild()->setBalance(getBalance(cnode->getRightChild()));
		}
		
		cout << "balance of cnode is: " << cnode->checkBalance() << endl;
		cout << "balance of cnode left child: " << cnode->getLeftChild()->checkBalance() << endl;
		cout << "cnode is: " << cnode->getValue() << endl; 
		cout << "prev node is: " << prev->getValue() << endl;	
		//check critical node if 2 left rotate
		if (cnode->checkBalance() == 2){
			cout << "we need to left rotate on critical node: " << cnode->getValue() << endl;
			leftRotate(cnode);
			cout << "back from leftRotate" << endl;
		}
		else if (cnode->checkBalance() == -2){
			cout << "we need to right rotate on critical node" << endl;
			rightRotate(cnode);
			cout << "back from rightRotate" << endl;
		}
	}//end outer else
}


template <typename T>
void AVL<T>::remove(T v){

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
	Node<T>* temp = 0;
	while ((n != 0) && (n->getValue() != 0)){
		temp = n;
		if (v < n->getValue()){
			n = n->getLeftChild();
		}
		else {
			n = n->getRightChild();
		}
		return temp;
	}
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
	cout << "tempRC is: " << tempRC->getValue() << endl;
	
	Node<T>* parent = findParent(n->getValue(), root);
	cout << "parent is: " << parent->getValue() << endl;
	tempRC->setLeftChild(n);
	cout << "tempRCs left child is: " << tempRC->getLeftChild()->getValue() << endl;
	cout << "n value is: " << n->getValue() << endl;
	if (parent == n){
		root = tempRC;
		cout << "past root pntr" << endl;
	}
	else {
		if (parent->getValue() < n->getValue()){
			parent->setRightChild(tempRC);
		}
		else {
			parent->setLeftChild(tempRC);
		}
	}
	
	n->setRightChild(tempLC);
}

template <typename T>
//Node<T>* AVL<T>::leftRotate(Node<T>* n){
void AVL<T>::rightRotate(Node<T>* n){
	
	Node<T>* tempLC = n->getLeftChild();
	Node<T>* tempRC = tempLC->getRightChild();
	cout << "tempLC is: " << tempLC->getValue() << endl;
	
	Node<T>* parent = findParent(n->getValue(), root);
	cout << "parent is: " << parent->getValue() << endl;
	tempLC->setRightChild(n);
	cout << "tempLCs right child is: " << tempLC->getRightChild()->getValue() << endl;
	cout << "n value is: " << n->getValue() << endl;
	if (parent == n){
		root = tempLC;
		cout << "past root pntr" << endl;
	}
	else {
		if (parent->getValue() < n->getValue()){
			parent->setLeftChild(tempLC);
		}
		else {
			parent->setRightChild(tempLC);
		}
	}
	
	n->setLeftChild(tempRC);
	
}

template <typename T>
void AVL<T>::testRotate(){
	leftRotate(root->getRightChild());
	cout << "returned from rotate" << endl;
}

template class AVL<int>;
