/* Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algo­
rithm to create a binary search tree with minimal height. */

#include "BinarySearchTree.h"
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

template <class T>
Node<T> * minimalTree(vector<T> & v, int start, int end){
	if(start > end) return NULL;
	int mid = (start + end) / 2;
	Node<T>* node = new Node<T>(v[mid]);
	node->left = minimalTree(v, start, mid-1);
	node->right = minimalTree(v, mid+1, end);
	return node;
} 

template <class T>
Node<T> * minimalTree(vector<T> & v){
	Node<T> * root = minimalTree(v, 0, v.size()-1);
	return root;
}

int main(){
	
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	vector<int> v(a, a+sizeof(a) / sizeof(int) );
	
	Node<int> * root = minimalTree(v);
	root->levelOrder();
	
	return 0;
}


