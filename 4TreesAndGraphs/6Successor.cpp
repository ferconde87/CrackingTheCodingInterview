//#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

using namespace std;

template <class T>
class Node{
	Node<T> * left;
	Node<T> * right;
	Node<T> * parent;
	T data;
	Node(T data){
		left = NULL;
		right = NULL;
		parent = NULL;
		this->data = data;
	}
	void insert(T data);
	void insert(Node * node, T data);
	
};



template <class T>
void Node<T>::insert(Node<T> * node, T data){
	if(node == NULL){
		this->left = NULL;
		this->left = NULL;
		this->left = NULL;
		thiss->data = data;
	}else{
		if(data < node->data)
			insert(node->left, data);
		else
			insert(node->right, data);
	}
}


template <class T>
void Node<T>::insert(T data){
	insert(this, data);
}



int main(){
	
	Node<int> * node = new Node(6);
	node->insert(3);
	node->insert(1);
	node->insert(2);
	node->insert(4);
	node->insert(5);
	node->insert(9);
	node->insert(7);
	node->insert(8);
	node->insert(11);
	node->insert(10);
	node->insert(12);
	
	
	return 0;
}
