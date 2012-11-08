//filename:	AVL.cpp
//descrip:	implementation file for avl tree
//author:	Billy Mills
//date:		Fall 2012

#include "AVL.h"

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
	if (root == 0){
		root = newNode;
	}
}

template <typename T>
void AVL<T>::remove(T v){

}

template <typename T>
void AVL<T>::print(){

}

template class AVL<int>;
