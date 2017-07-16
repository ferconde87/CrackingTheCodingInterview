#include <iostream>
#include <unordered_map>
#include <queue>
#include <cassert>

using namespace std;

template <class T>
class Node{
	public: 
		T data;
		Node<T> * left;
		Node<T> * right;
		int index;
		Node<T> * parent;
		Node(T data, int index, Node<T> * parent){
			this->data = data;
			left = right = NULL;
			this->index = index;
			this->parent = parent;
		}
		Node<T> * insert(T data, int index);
		Node<T> * insert(Node<T> * node, T data, int index, Node<T> * parent);
		Node<T> * del(T data);//TODO
		void del(Node<T> * root, T data);//TODO
		Node<T> * next();
		void inOrder();
		bool find(T data);
		bool find(Node<T> * node, T data);
		Node<T> * getParent(T data);
		Node<T> * getParent(Node<T> * node, T data);
};


template <class T>
bool Node<T>::find(Node<T> * node, T data){
	if(node == NULL) return false;
	if(node->data == data) return true;
	return find(node->left, data) or find(node->right, data);
}


template <class T>
Node<T> * Node<T>::getParent(Node<T> * node, T data){
	if(node == NULL) return NULL;
	if(node->data == data) return NULL; //el nodo raíz no tiene padre
	if(node->left != NULL){
		if(node->left->data == data)
			return node;
		else
			getParent(node->left, data);
	}
	if(node->right != NULL){
		if(node->right->data == data)
			return node;
		else
			getParent(node->right, data);
	} 
}


template <class T>
Node<T> * Node<T>::getParent(T data){
	return getParent(this, data);
}

template <class T>
bool Node<T>::find(T data){
	return find(this, data);
}	

template <class T>
void Node<T>::inOrder(){
	if(this == NULL) return;
	this->left->inOrder();
	cout << this->data << " ";
	this->right->inOrder();
}

template <class T>
Node<T> * Node<T>::insert(Node<T> * node, T data, int index, Node<T> * parent){
	if(node == NULL){
		node = new Node(data, index, parent);
		return node;
	}
	if(data < node->data){
		node->left = insert(node->left, data, index, node);
	}else{
		node->right = insert(node->right, data, index, node);
	}
	return node;
}

template <class T>
Node<T> * Node<T>::insert(T data, int index){
	return insert(this, data, index, NULL);
}

//~ template <class T>
//~ Node<T> * Node<T>::del(Node<T> * node, T data){
	//~ if(node == NULL) return NULL;
	//~ if(node->data != data) {
		//~ del(node->left, data);
		//~ del(node->right, data);
	//~ }else if(node->left == NULL && node->right == NULL){
		//~ node = NULL;
	//~ }else if(node->left != NULL && node->right != NULL){
		//~ Node<T> * next = node->next();
		//~ if(next->parent == node){//si tiene 2 hijos, el padre de next no puede ser NULL
			//~ next->parent = NULL;
			//~ 
		//~ }
		//~ next->left = node->left;
		//~ next->right = (node->right != next) ? node->right : NULL;
		//~ node = next;
	//~ }else if(node->left != NULL){
		//~ node = node->left;
	//~ }else{
		//~ node = node->right;
	//~ }
	//~ return node;
//~ }

template <class T>
void Node<T>::del(Node<T> * node, T data){
	if(node == NULL) return;
	if(node->data != data) {
		del(node->left, data);
		del(node->right, data);
	}else if(node->left == NULL && node->right == NULL){
		node = NULL;
	}else if(node->left != NULL && node->right != NULL){
		Node<T> * next = node->next();
		if(next == node->right){
			next->left = node->left;
		}else{
			Node<T> * parent = node->parent;
			Node<T> * grandparent = parent->parent;
			next->left = grandparent->left;
			if(grandparent != NULL){
				next->left = grandparent->left;
			}
			next->right = parent;
			parent->left = NULL;
		}
	}else if(node->left != NULL){
		node = node->left;
	}else{
		node = node->right;
	}
}

template <class T>
Node<T> * Node<T>::del(T data){
	if(this == NULL) return NULL;
	if(this->data == data){
		if(this->right != NULL){
			Node<T> * next = this->next();
			if(next == NULL) return NULL;//hay un solo nodo
			Node<T> * parent = next->parent;
			if(parent == this){//hay un solo elemento a la derecho
				next->left = this->left;
			}else{
				//grandparent->parent no puede ser NULL xq sino parent == this
				Node<T> * grandparent = parent->parent;
				next->left = grandparent->left;
				parent->left = NULL;
				next->right = parent;
			}
			return next;//la nueva raíz
		}
	}
	del(this, data);
	return this;
}

template <class T>
Node<T> * mostLeft(Node<T> * node){
	Node<T> * result = node;
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}


template <class T>
Node<T> * Node<T>::next(){
	if(this == NULL) return NULL;
	if(this->right == NULL) return NULL;
	return mostLeft(this->right);
}


template <class T>
class Tree{
	Node<T> * root;
	int size;
	queue<int> q;
	unordered_map<int, Node<T>*> m;
	Tree(T data){
		root = new Node<T>(data);
		m[0] = root;
		size = 1;
	}
	void insert(T data);
	void del(T data);
};

template <class T>
void Tree<T>::insert(T data){
	int index;
	if(q.empty){
		index = size;
	}else{
		index = q.front();
		q.pop();
	}
	Node<T> * node = root->insert(data, index);
	m[index] = node;
}

template <class T>
void Tree<T>::del(T data){
	int index;
	Node<T> * nodeToDelete = root->del(data);
	int indexToDelete = nodeToDelete->index;
	q.push(indexToDelete);
	m.erase(indexToDelete);
}


int main(){
	//testeo node
	Node<int> * root = new Node<int>(5, 0, NULL);
	//~ Node<int> * root = new Node<int>(3, 1);
	//~ Node<int> * root = new Node<int>(2, 2);
	//~ Node<int> * root = new Node<int>(4, 3);
	//~ Node<int> * root = new Node<int>(8, 4);
	//~ Node<int> * root = new Node<int>(6, 5);
	//~ Node<int> * root = new Node<int>(10, 6);
	//~ auto node3 = root->insert(3,1,root);
	//~ auto node2 = root->insert(2,2,node3);
	//~ auto node4 = root->insert(4,3,node3);
	//~ auto node8 = root->insert(8,4,root);
	//~ auto node6 = root->insert(6,5,node8);
	//~ auto node10 = root->insert(10,6,node8);
	auto node3 = root->insert(3,1);
	auto node2 = root->insert(2,2);
	auto node4 = root->insert(4,3);
	auto node8 = root->insert(8,4);
	auto node6 = root->insert(6,5);
	auto node10 = root->insert(10,6);
	
	assert(root->find(5) == true);
	assert(root->find(3) == true);
	assert(root->find(2) == true);
	assert(root->find(4) == true);
	assert(root->find(8) == true);
	assert(root->find(6) == true);
	assert(root->find(10) == true);
	assert(root->find(-1) == false);
	
	root->inOrder();cout << endl;
	
	assert(root->next()->data == 6);
	root = root->del(5);
	cout << "root->data = " << root->data << endl;
	cout << "root->left->data = " << root->left->data << endl;
	cout << "root->right->data = " << root->right->data << endl;
	root->inOrder(); cout << endl;
	//~ root->del(2);
	//~ assert(root->find(2) == true);
	
	//~ root->del(5);
	//~ root->inOrder();cout << endl;
	//~ assert(root->find(5); 
	
	//~ root->inOrder();cout << endl;
	
	
}
