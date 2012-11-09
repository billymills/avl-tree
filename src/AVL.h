//filename:	AVL.h
//descrip:	header file for AVL implementation
//author:	Billy Mills
//date:		Fall 2012

#ifndef __AVL_H__
#define __AVL_H__

#include "Node.h"

template <typename T>
class AVL {

	private:
		Node<T>* root;
		Node<T>* findNode(T v, Node<T>* t);
		Node<T>* findParent(T v, Node<T>* t);
		void postOrderDelete(Node<T>* t);
		void traversalPrint(Node<T>* rt);
		int getBalance(Node<T>* n);
		int getHeight(Node<T>* n);

	public:
		AVL<T>();
		~AVL<T>();
		bool find(T v);
		void insert(T v);
		void remove(T v);
		void print();

};

#endif
