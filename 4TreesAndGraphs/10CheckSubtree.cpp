#include <iostream>
#include <cassert>

using namespace std;


template <class T>
class Node{
	public:
		T data;
		Node<T> * left;
		Node<T> * right;
		Node(T data){
			this->data = data;
			left = right = NULL;
		}
};

template <class T>
bool isSubtree(Node<T> * t1, Node<T> * t2){
	if(t2 == NULL) return true;
	if(t1 == NULL) return false;
	if(t1->data != t2->data) return false;
	return checkSubtree(t1->left, t2->left) and checkSubtree(t1->right, t2->right);
}

template <class T>
bool checkSubtree(Node<T> * t1, Node<T> * t2){
	if(t2 == NULL) return true;
	if(t1 == NULL) return false;
	if(isSubtree(t1, t2)){
		return true;
	}
	return checkSubtree(t1->left, t2) or checkSubtree(t1->right, t2);
}



int main(){
	Node<int> * node6 = new Node<int>(6);
	Node<int> * node2 = new Node<int>(2);
	Node<int> * node3 = new Node<int>(3);
	Node<int> * node4 = new Node<int>(4);
	Node<int> * node5 = new Node<int>(5);
	Node<int> * node7 = new Node<int>(7);
	Node<int> * node8 = new Node<int>(8);
	
	node6->left = node2;
	node6->right = node7;
	node2->left = node4;
	node2->right = node3;
	node7->left = node5;
	node7->right = node8;
	
	Node<int> * node5b = new Node<int>(5);
	Node<int> * node7b = new Node<int>(7);
	Node<int> * node8b = new Node<int>(8);
	node7b->left = node5b;
	node7b->right = node8b;
	
	cout << checkSubtree(node6, node7) << endl;//1
	cout << checkSubtree(node6, node7b) << endl;//1
	
	node7b->right = node7;//0
	assert(checkSubtree(node6, node7b) == 0);
	node7b->right = node8b;
	
	Node<int> * node7c = new Node<int>(7);
	Node<int> * node5c = new Node<int>(5);
	node7->right = node7c;
	node7c->left = node5c;
	node7c->right = node8;
	
	assert(checkSubtree(node6, node7b) == 1);
	
}