#include <iostream>
#include <cassert>
#include <unordered_map>
#include <utility>

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

// primera versión
template <class T>
bool isHere(Node<T> * root, Node<T> * a){
	if(root == NULL) return false;
	if(root->data == a->data) return true;
	return isHere(root->left, a) or isHere(root->right, a);
}

template <class T> 
Node<T> * firstCommonAncestor(Node<T> * root, Node<T> * a, Node<T> * b){
	if(root == NULL) return NULL;
	if(isHere(root->left, a) and isHere(root->left, b))
		return root->left;
	if(isHere(root->right, a) and isHere(root->right, b))
		return root->right;
	if((isHere(root->left, a) or isHere(root->left, b)) and (isHere(root->right, a) or isHere(root->right, b)))
		return root;
	else
		return NULL;
	
}

// segunda versión con memoización
template <class T>
bool find(Node<T> * key, Node<T> * x, unordered_map<T, bool> & map){
	bool result;
	if(map.find(key->data)==map.end()){
		result = isHere(key, x);
		map.insert(make_pair(key->data, result));
	}else{
		result = map[key->data];
	}
	return result;
}

template <class T> 
Node<T> * firstCommonAncestor2(Node<T> * root, Node<T> * a, Node<T> * b){
	if(root == NULL) return NULL;
	unordered_map<T, bool> mapA;
	unordered_map<T, bool> mapB;
	bool isAinLeft = find(root->left, a, mapA);
	bool isBinLeft = find(root->left, b, mapB);
	if(isAinLeft and isBinLeft)
		return root->left;
	bool isAinRight = find(root->right, a, mapA);
	bool isBinRight = find(root->right, b, mapB);
	if(isAinRight and isBinRight)
		return root->right;	
	
	if((isAinLeft or isBinLeft) and (isAinRight or isBinRight))
		return root;
	else
		return NULL;
	
}


int main(){
	
	Node<int> * node1 = new Node<int>(1);
	Node<int> * node2 = new Node<int>(2);
	Node<int> * node3 = new Node<int>(3);
	node1->left = node2;
	node1->right = node3;
	Node<int> * ancestor = firstCommonAncestor(node1, node2, node3);
	cout << ancestor->data << endl;//1
	assert(firstCommonAncestor2(node1, node2, node3)->data==1);
	
	Node<int> * node4 = new Node<int>(4);
	Node<int> * node5 = new Node<int>(5);
	node2->right = node4;
	node3->left = node5;
	ancestor = firstCommonAncestor(node1, node4, node5);
	cout << ancestor->data << endl;//1
	assert(firstCommonAncestor2(node1, node4, node5)->data==1);	

	Node<int> * n1 = new Node<int>(1);
	Node<int> * n2 = new Node<int>(2);
	Node<int> * n3 = new Node<int>(3);	
	Node<int> * n4 = new Node<int>(4);
	Node<int> * n5 = new Node<int>(5);
	Node<int> * n6 = new Node<int>(6);
	n1->left = n2;
	n1->right = n6;
	n2->left = n3;
	n2->right = n5;
	n3->left = n4;
	ancestor = firstCommonAncestor(n1, n4, n5);
	cout << ancestor->data << endl;//2
	assert(firstCommonAncestor2(n1, n4, n5)->data==2);
	
	ancestor = firstCommonAncestor(n1, n6, n5);
	cout << ancestor->data << endl;//1
	assert(firstCommonAncestor2(n1, n6, n5)->data==1);
	
	assert(firstCommonAncestor2(n1, n6, node1)==NULL);
	assert(firstCommonAncestor2(n1, node5, node1)==NULL);
	
	return 0;
}