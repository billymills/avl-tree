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
		}
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
	cout << "balance of cnode right child: " << cnode->getRightChild()->checkBalance() << endl;
	cout << "cnode is: " << cnode->getValue() << endl;
	}
}


template <typename T>
void AVL<T>::remove(T v){

}

template <typename T>
void AVL<T>::print(){
	traversalPrint(root);
}

template <typename T>
void AVL<T>::traversalPrint(Node<T>* rt){
	if(rt != 0){
		traversalPrint(rt->getLeftChild());
		traversalPrint(rt->getRightChild());
		cout << rt->getValue() << endl;
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
Node<T>* AVL<T>::leftRotate(Node<T>* n){
	Node<T>* tempRC = n->getRightChild();
	cout << "tempRC is: " << tempRC->getValue() << endl;
	Node<T>* parent = findParent(n->getValue(), root);
	cout << "parent is: " << parent->getValue() << endl;
	tempRC->setLeftChild(n);
	cout << "tempRCs left child is: " << tempRC->getLeftChild()->getValue() << endl;
	cout << "n value is: " << n->getValue() << endl;
	if (parent->getValue() < n->getValue()){
		parent->setRightChild(tempRC);
	}
	else {
		parent->setLeftChild(tempRC);
	}
	n->setRightChild(0);
	
}

template <typename T>
void AVL<T>::testRotate(){
	leftRotate(root->getRightChild());
	cout << "returned from rotate" << endl;
}

template class AVL<int>;
