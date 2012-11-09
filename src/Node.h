//filename:	Node.h
//descrip:	header file for node
//author:	Billy Mills
//date:		Fall 2012

#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {

	private:
		T value;				//stored val
		int balance;			//right tree height - left tree height
		Node<T>* rightChild;
		Node<T>* leftChild;

	public:
		Node<T>(T val);
		T getValue();
		Node<T>* getRightChild();
		Node<T>* getLeftChild();
		void setRightChild(Node<T>* t);
		void setLeftChild(Node<T>* t);
		void setBalance(int b);
};

#endif
