#include "BinarySearchTree.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one. */

//cuarto intento: sin usar un struct que devuelva 2 resultados

template <class T>
int isBalancedRec(Node<T> * node){
	int res;
	if (node == NULL){
		res = 0;
		return res;
	}
	int leftRes = isBalancedRec(node->left);
	int rightRes = isBalancedRec(node->right);
	if(abs(leftRes-rightRes) <= 1 && leftRes >= 0 && rightRes >= 0){
		res = 1 + max(leftRes, rightRes);
	}else{
		res = -1;
	}
	return res;
}

template <class T>
bool isBalanced3(Node<T> * root){
	return -1 != isBalancedRec(root);
}


//tercer intento: sin modificar la clase Node. Calculando al mismo tiempo la altura y si está balanceada o no
template <typename T>
struct result{
	bool balance;
	int height;
};

template <class T>
result<T> heightAndBalance(Node<T> * node){
	result<T> res;
	if (node == NULL){
		res.balance = true;
		res.height = 0;
		return res;
	}
	result<T> leftRes = heightAndBalance(node->left);
	result<T> rightRes = heightAndBalance(node->right);
	res.height = 1 + max(leftRes.height, rightRes.height);
	res.balance = abs(leftRes.height-rightRes.height) <= 1 && leftRes.balance && rightRes.balance;  
	return res;
}

template <class T>
bool isBalanced2(Node<T> * root){
	result<T> res = heightAndBalance(root);
	return res.balance;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//segundo intento: más eficiente. Modificando Node* para que guarde la altura del cada nodo (ver función insert) 
template <class T>
class Node2{
	public:
		Node2 * left;
		Node2 * right;
		int height;
		T data;
		Node2 * insert(Node2 * root, T data);
		Node2(T data){
			this->data = data;
			left = NULL;
			right = NULL;
			height = 1;
		}
		void insert(T data);
		void print();
		void print(Node2* root);
		void printHeights();
		void printHeights(Node2* root);
		bool isBalanced();
		bool isBalanced(Node2* root);
};

template <class T>
int getHeight(Node2<T> * node){
	if(node == NULL) return 0;
	return node->height;
}

template <class T> 
bool Node2<T>::isBalanced(Node2<T> * node){
	if(node == NULL) return true;
	bool balanced = abs(getHeight(node->left)-getHeight(node->right)) <= 1;
	balanced &= isBalanced(node->left);
	balanced &= isBalanced(node->right);
	return balanced;
}

template <class T>
bool Node2<T>::isBalanced(){
	isBalanced(this);
}

template <class T> 
void Node2<T>::printHeights(Node2<T> * node){
	if(node == NULL) return;
	printHeights(node->left);
	cout << "(" << node->data << ", " << node->height << ") ";
	printHeights(node->right);
}

template <class T>
void Node2<T>::printHeights(){
	printHeights(this);
	cout << endl;
}

template <class T> 
void Node2<T>::print(Node2<T> * node){
	if(node == NULL) return;
	print(node->left);
	cout << node->data << " ";
	print(node->right);
}

template <class T>
void Node2<T>::print(){
	print(this);
	cout << endl;
}

template <class T>
Node2<T>* Node2<T>::insert(Node2* node, T data){
	if(node == NULL){ return new Node2(data); }
	if(data < node->data){
		node->left = insert(node->left, data);
	}else{
		node->right = insert(node->right, data);
	}
	int leftHeight = (node->left == NULL) ? 0 : node->left->height;
	int rightHeight = (node->right == NULL) ? 0 : node->right->height;
	node->height = 1 + max(leftHeight, rightHeight); 
	return node;
}

template <class T>
void Node2<T>::insert(T data){
	insert(this, data);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//primer intento: funciona pero es muy ineficiente. Estamos calculando las alturas de cada nodo
//varias veces. Por cada nodo estamos recorriendo todo el arbol restante veces
template <class T>
int height(Node<T> * node){
	if (node == NULL) return 0;
	return 1 + max(height(node->left), height(node->right));
}

template <class T>
bool isBalanced(Node<T> * root){
	if(root == NULL) return true;
	bool isBalance = abs(height(root->left)-height(root->right)) <= 1;
	isBalance &= isBalanced(root->left);
	isBalance &= isBalanced(root->right);
	return isBalance;
}

////////////////////////////////////////////////////////////////////////////

int main(){
	
	//1er intento: ineficiente
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
	
	cout << height(root) << endl;
	cout << isBalanced(root) << endl;
	
	Node<int> * root2 = new Node<int>(6);
	root2->insert(3);
	root2->insert(2);
	root2->insert(1);
	root2->insert(7);
	root2->insert(8);
	root2->insert(9);

	Node<int> * root5 = new Node<int>(3);
	root5->insert(2);
	root5->insert(1);
	root5->insert(4);
	root5->insert(5);

	cout << height(root2) << endl;
	cout << isBalanced(root2) << endl;
	cout << height(root5) << endl;
	cout << isBalanced(root5) << endl;
	
	//2do intento creando Node2 (Node + height)
	Node2<int> * root3 = new Node2<int>(6);
	root3->insert(3);
	root3->insert(2);
	root3->insert(1);
	root3->insert(7);
	root3->insert(8);
	root3->insert(9);

	root3->print();
	root3->printHeights();
	cout << root3->isBalanced() << endl;
	
	Node2<int> * root4 = new Node2<int>(6);
	root4->insert(3);
	root4->insert(9);
	root4->insert(1);
	root4->insert(4);
	root4->insert(5);
	root4->insert(2);
	root4->insert(7);
	root4->insert(8);
	root4->insert(11);
	root4->insert(10);
	root4->insert(12);	
	root4->printHeights();
	cout << root4->isBalanced() << endl;
	
	cout << "3era y 4ta versión" << endl;
	//3er intento con un struct <height,isBalance>
	cout << isBalanced2(root) << endl;
	cout << isBalanced2(root2) << endl;
	cout << isBalanced2(root5) << endl;
	
	//4to intento
	cout << isBalanced3(root) << endl;
	cout << isBalanced3(root2) << endl;
	cout << isBalanced3(root5) << endl;
	
	return 0;
}
