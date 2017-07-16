#include <iostream>
#include <cassert>
#include <string>

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

//// other approach, solución CTCI
template <class T>
bool checkSubtree2(Node<T> * t1, Node<T> * t2){
	string s1, s2;
	preOrder(t1, s1);
	preOrder(t2, s2);
	return s1.find(s2)!=string::npos;
}

//cuidado con el separador X. Si aparece en el árbol, el resultado podría ser incorrecto.
template <class T>
void preOrder(Node<T> * t, string & s){
	if(t==NULL) {s.push_back('X'); return;}
	s.append(to_string(t->data));
	preOrder(t->left, s);
	preOrder(t->right, s);
	return;
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
	cout << checkSubtree2(node6, node7) << endl;//1
	cout << checkSubtree(node6, node7b) << endl;//1
	cout << checkSubtree2(node6, node7b) << endl;//1
	
	node7b->right = node7;//0
	assert(checkSubtree(node6, node7b) == 0);
	assert(checkSubtree2(node6, node7b) == 0);
	node7b->right = node8b;
	
	Node<int> * node7c = new Node<int>(7);
	Node<int> * node5c = new Node<int>(5);
	node7->right = node7c;
	node7c->left = node5c;
	node7c->right = node8;
	
	assert(checkSubtree(node6, node7b) == 1);
	assert(checkSubtree2(node6, node7b) == 1);
	
	node5b->left = node7b;
	node5b->right = node8b;
	node7b->left = NULL;
	node7b->right = NULL;
	
	
	node5->left = node7;
	node7->left = node8;
	node7->right = NULL;
	assert(checkSubtree(node5, node5b) == 0);
	assert(checkSubtree2(node5, node5b) == 0);
	
	return 0;
}
