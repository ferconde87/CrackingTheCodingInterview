#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

using namespace std;

// Implement a function to check if a binary tree is a binary search tree.


// 1er intento:
// no alcanza con esto, no chequea todos los padres con todos los hijos
//puede pasar  3
//			 2    5
//		   1  4* <- mal y no lo va a detectar 
//
template <class T>
bool validateBST(Node<T>* root){
	if(root == NULL) return true;
	bool res = validateBST(root->left);
	res &= validateBST(root->right);
	if(root->left != NULL){
		cout << "node = " << root->data << " >=  left = " << root->left->data << endl;
		res &= root->data >= root->left->data;
	}
	if(root->right != NULL){
		res &= root->data < root->right->data;
		cout << "node = " <<  root->data << " < right = " << root->right->data << endl;
	}
	return res;
}


//2do intento:
// OK! pero si hay repetidos.. 
//hacer inorder y comparar que cada uno sea menor (o igual quizá) al anterior
template <class T>
vector<int> inOrder(Node<T> * root, vector<int> & v){
	if(root == NULL) return v;
	inOrder(root->left, v);
	v.push_back(root->data);
	inOrder(root->right, v);
	return v;
}

template <class T>
vector<int> inOrder(Node<T> * root){
	vector<int> v;
	return inOrder(root, v);
}

template <class T>
bool validateBST2(Node<T>* root){
	vector<int> res = inOrder(root);
	
	for(int i = 0; i < res.size()-1; i++)
			if(res[i] > res[i+1])
				return false;
	
	return true;
}

//////////////////////////////////////////// OK
template <class T>
bool validateBST3(Node<T>* root, int min, int max){
	if(root == NULL) return true;
	bool valid = validateBST3(root->left, min, root->data);
	valid &= validateBST3(root->right, root->data, max);
	if(root->left != NULL){
		int left = root->left->data;
		valid &= left <= root->data && min <= left && left <= max;
	 }
	if(root->right != NULL){
		int right = root->right->data;
		valid &= root->data <= right && min <= right && right <= max;
	}
	return valid; 
}

template <class T>
bool validateBST3(Node<T>* root){
	return validateBST3(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

////// OK Compacto
template <class T>
bool validateBST4(Node<T>* root, int min, int max){
	if(root == NULL) return true;
	if(root->data < min || root->data > max) return false;
	return validateBST4(root->left, min, root->data) && validateBST4(root->right, root->data, max);
}

template <class T>
bool validateBST4(Node<T>* root){
	return validateBST4(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main(){
	
	Node<int> * root = new Node<int>(6);
	root->insert(3);
	root->insert(9);
	root->insert(1);
	root->insert(4);
	root->insert(5);
	root->insert(2);
	root->insert(7);
	root->insert(8);
	root->insert(11);
	root->insert(10);
	root->insert(12);
	
	//cout << validateBST(root) << endl;
	
	Node<int> * root2 = new Node<int>(6);
	root2->insert(3);
	root2->insert(root2, 2);
	root2->insert(1);
	root2->insert(7);
	root2->insert(8);
	root2->insert(9);
	
	cout << validateBST(root2) << endl;
	
	//////////////////////////////////////////
	cout << "2do intento" << endl;
	
	cout << validateBST2(root) << endl;
	
	cout << validateBST2(root2) << endl;
	
	//////////////////////////////////////////
	cout << "3er intento" << endl;
	
	cout << validateBST3(root) << endl;
	
	cout << validateBST3(root2) << endl;
	
	//////////////////////////////////
	cout << "testeo chido" << endl;
	Node<int> * node6 = new Node<int>(6);
	Node<int> * node3 = new Node<int>(3);
	Node<int> * node2 = new Node<int>(2);
	Node<int> * node1 = new Node<int>(1);
	Node<int> * node4 = new Node<int>(4);
	node6->left = node3;
	node3->left = node2;
	node2->left = node1;
	node2->right = node4;
	
	cout << validateBST(node6) << endl;//tendría que dar 0 pero da 1 xq está mal
	cout << validateBST2(node6) << endl;//0 ... funciona bien, pero con repetidos se rompería
	cout << validateBST3(node6) << endl;//OK, 0
	cout << validateBST4(node6) << endl;//OK, 0
	
	assert(validateBST3(root));
	assert(validateBST3(root2));
	assert(validateBST4(root));
	assert(validateBST4(root2));
	
	return 0;
}
