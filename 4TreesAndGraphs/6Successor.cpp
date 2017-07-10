//#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

using namespace std;

template <class T>
class Node{
	public: 
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
		Node(T data, Node<T> * parent){
			left = NULL;
			right = NULL;
			this->parent = parent;
			this->data = data;
		}
		void insert(T data);
		Node<T> * insert(Node * node, T data, Node * parent);
		Node<T> * getNode(T data);
		Node<T> * getNode(Node<T> * node, T data);
		Node<T> * getParent(Node<T> * node);
	
};


template <class T>
Node<T> * Node<T>::insert(Node<T> * node, T data, Node<T> * parent){
	if(node == NULL){
		node = new Node(data, parent);
	}else{
		if(data < node->data)
			node->left = insert(node->left, data, node);
		else
			node->right = insert(node->right, data, node);
	}
	return node;
}


template <class T>
void Node<T>::insert(T data){
	insert(this, data, NULL);
}


template <class T>
Node<T> * successor(Node<T> * node){
	if(node == NULL) return NULL;
	Node <T> * result;
	if(node->right == NULL){
		result = node->parent;
		while(result != NULL && result->data < node->data){
			result = result->parent;
		}
	}else{
		result = node->right;
		while(result->left != NULL){
			result = result->left;
		}
	}
	if(result == node)
		return NULL;
	return result;
}

template <class T>
Node<T> * Node<T>::getParent(Node<T> * node){
	if(node == NULL) return NULL;
	return node->parent;
}


template <class T>
Node<T> * Node<T>::getNode(Node<T> * node, T data){
	if(node == NULL) return NULL;
	if(node->data == data){
		return node;
	}else if(data < node->data){
		return getNode(node->left, data);
	}else{
		return getNode(node->right, data);
	}
}

template <class T>
Node<T> * Node<T>::getNode(T data){
	return getNode(this, data);
}

int main(){
	
	Node<int> * node = new Node<int>(6);
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
	
	assert(successor(node->getNode(4))->data == 5);
	assert(successor(node->getNode(9))->data == 10);
	assert(successor(node->getNode(8))->data == 9);
	assert(node->getParent(node->getNode(8))->data == 7);
	
	return 0;
}
