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
	vector<Node<T>* > nodeHolder;
	
	//insert root
	if (curr == 0){
		root = newNode;
		return;
	}

	//insert everthing else
	else {

		//find place in tree
		while (curr != 0){
			//check if value is already in tree
			if (curr->getValue() == v){
				return;
			}
			nodeHolder.push_back(curr);
			//look for critical node on each move
			if (prev != 0 && (prev->checkBalance() > 0 || prev->checkBalance() < 0)){
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
		
		//insert node
		if(prev->getValue() > v){
			prev->setLeftChild(newNode);
		}
		else {
			prev->setRightChild(newNode);
		}

		for(int i = 0;i<nodeHolder.size();++i){
			nodeHolder[i]->setBalance(getBalance(nodeHolder[i]));
		}
		if (cnode->getRightChild() != 0){
			cnode->getRightChild()->setBalance(getBalance(cnode->getRightChild()));
		}
		
		//check critical node if 2 left rotate
		if (cnode->checkBalance() == 2){
			if (cnode->getRightChild()->checkBalance() < 0){
				rightRotate(cnode->getRightChild());
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
	vector<Node<T>* > nodes;

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

		//case 3 there are two children
		//now need to store nodes along iop path
		if(curr->getLeftChild() != 0 && curr->getRightChild() != 0){
			Node<T>* iop = curr->getLeftChild();
			nodes.push_back(iop);
			while(iop->getRightChild() != 0){
				iop = iop->getRightChild();
				nodes.push_back(iop);
			}
			Node<T>* curr2 = iop;
			while (curr2->getLeftChild() !=0){
				curr2 = curr2->getLeftChild();
			}
			iop->setRightChild(curr->getRightChild());
			if (curr->getLeftChild() != iop){
				curr2->setLeftChild(curr->getLeftChild());
				curr->getLeftChild()->setRightChild(0);
			}
			root = iop;
		}
		delete curr;
	}//end handle root if

	//when node to be removed is not root
	else {
		//find node
		while (curr->getValue() != v && curr !=0){
			nodes.push_back(curr);
			if (curr->getValue() < v){
				curr = curr->getRightChild();
			}
			else {
				curr = curr->getLeftChild();
			}
			if (curr == 0){
				cout << "value: " << v << " not in tree" << endl;
				return;
			}
		}

		Node<T>* parent = findParent(v, root);
		//now look at three cases
		
		//case 1 there are no children
		if (curr->getLeftChild() == 0 && curr->getRightChild() == 0){
			if(parent->getRightChild() == curr){
				parent->setRightChild(0);
			}
			else {
				parent->setLeftChild(0);
			}
		}
		
		//case 2 ther is one child
		else if (curr->getLeftChild() != 0 && curr->getRightChild() == 0){
			if(parent->getRightChild() == curr){
				parent->setRightChild(curr->getLeftChild());
			}
			else {
				parent->setLeftChild(curr->getLeftChild());
			}
		}
		else if (curr->getLeftChild() == 0 && curr->getRightChild() != 0){
			if (parent->getRightChild() == curr){
				parent->setRightChild(curr->getRightChild());
			}
			else {
				parent->setLeftChild(curr->getRightChild());
			}
		}

		//case 3 two children
		else {
			Node<T>* iop = curr->getLeftChild();
			nodes.push_back(iop);
			while(iop->getRightChild() != 0){
				iop = iop->getRightChild();
				nodes.push_back(iop);
			}
			iop->setRightChild(curr->getRightChild());
			Node<T>* curr2 = iop;
			while (curr2->getLeftChild() != 0){
				curr2 = curr2->getLeftChild();
			}
			if (curr->getLeftChild() != iop){
				curr2->setLeftChild(curr->getLeftChild());
				curr->getLeftChild()->setRightChild(0);
			}
			if (parent->getLeftChild() == curr){
				parent->setLeftChild(iop);
			}
			else {
				parent->setRightChild(iop);
			}			
		}
		delete curr;
	}//end else when removed node is not root
		
		//node is deleted now update and check balance of stored nodes
		for (int i = nodes.size()-1;i >= 0; --i){
			nodes.back()->setBalance(getBalance(nodes.back()));
			int currBal = nodes.back()->checkBalance();
			if (currBal == 2){
				if (nodes.back()->getRightChild()->checkBalance() < 0){
					rightRotate(nodes.back()->getRightChild());
				}
				leftRotate(nodes.back());
			}
			else if (currBal == -2){
				if (nodes.back()->getLeftChild()->checkBalance() > 0){
					leftRotate(nodes.back()->getLeftChild());
				}
				rightRotate(nodes.back());
			}
			nodes.pop_back(); //pop last item
		}
}

template <typename T>
void AVL<T>::treePrint(){
	assert(root != 0);
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
	return rh-lh;	
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
	if (tempRC->getRightChild() != 0){
		tempRC->getRightChild()->setBalance(getBalance(tempRC->getRightChild()));
	}
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
	if (tempLC->getLeftChild() != 0){
		tempLC->getLeftChild()->setBalance(getBalance(tempLC->getLeftChild()));
	}
}


template class AVL<int>;
