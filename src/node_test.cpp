//filename: node_test.cpp
//descrip:	test node implementation
//author:	Billy Mills
//date:		Fall 2012

#include "Node.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){

	Node<int>* testNode = new Node<int>(10);

	cout << "node value is: " << testNode->getValue() << endl;	

}
