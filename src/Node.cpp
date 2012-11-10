//filename:	Node.cpp
//descrip:	implementation file for node
//author:	Billy Mills
//date:		Fall 2012

#include "Node.h"

template <typename T>
Node<T>::Node(T v){
	value = v;
	balance = 0;
	rightChild = 0;
	leftChild = 0;
}

template <typename T>
T Node<T>::getValue(){
	return value;
}

template <typename T>
Node<T>* Node<T>::getRightChild(){
	return rightChild;
}

template <typename T>
Node<T>* Node<T>::getLeftChild(){
	return leftChild;
}

template <typename T>
void Node<T>::setRightChild(Node<T>* t){
	rightChild = t;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>* t){
	leftChild = t;
}

template <typename T>
void Node<T>::setBalance(int b){
	balance = b;
}

template <typename T>
int Node<T>::checkBalance(){
	return balance;
}


template class Node<int>;




