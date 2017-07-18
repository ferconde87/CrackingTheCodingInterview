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
		// Node<T> * del2(Node<T> * node);
		// Node<T> * del2(T data);
		// Node<T> * del2(Node<T> * node, T data);
		// Node<T> * del2Aux(T data);
		Node<T> * next();
		Node<T> * previous();
		void inOrder();
		void inOrder(Node<T> * node);
		bool find(T data);
		bool find(Node<T> * node, T data);
		Node<T> * getParent(T data);
		Node<T> * getParent(Node<T> * node, T data);
		Node<T> * getNode(Node<T> * node, T data);
		Node<T> * getNode(T data);
};



template <class T>
Node<T>* Node<T>::getNode(Node<T> * node, T data){
	if(node == NULL) return NULL;
	if(node->data == data) return node;
	Node<T> * result = getNode(node->left, data);
	if(result != NULL) return result;
	return getNode(node->right, data);
}

template <class T>
Node<T>* Node<T>::getNode(T data){
	return getNode(this, data);
}

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
void Node<T>::inOrder(Node<T> * node){
	if(node == NULL) return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

template <class T>
void Node<T>::inOrder(){
	inOrder(this);
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

// del 1

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

		//FALTA DEFINIR EL ALGORITMO.
		//si next tiene algún hijo derecho.. que hay que hacer?
		//una solución es cambiar el algoritmo next() para que 
			//si next tiene hijo derecho... devuelva este hijo, en lugar de como está ahora
		
		if(next == node->right){
			cout << "borrando a ......." << node->data << endl;
			next->left = node->left;//OK
			node->left->parent = next;//OK
		}else{
			next->left = node->left;//OK
			node->left->parent = next;//OK
			next->right = node->right;
			node->right->parent = next;
			next->parent->left = NULL;
		}
		//actualizamos el padre de next y el hijo del padre del nodo a borrar
		Node<T> * parent = node->parent;
		if(parent->left == node){
			parent->left = next;
		}else{
			parent->right = next;
		}
		next->parent = parent;
				
		node = NULL;
	}else if(node->right != NULL){
		Node<T> * parent = node->parent;
		Node<T> * son = node->right;
		if(parent->left == node){
			parent->left = son;
		}else{
			parent->right = son;
		}
		son->parent = parent;
		node = NULL;
	}else{
		Node<T> * parent = node->parent;
		Node<T> * son = node->left;
		if(parent->left == node){
			parent->left = son;
		}else{
			parent->right = son;
		}
		son->parent = parent;
		node = NULL;
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
		}else if(this->left != NULL){
			Node<T> * next = this->previous();
			if(next == NULL) return NULL;
			Node<T> * parent = next->parent;
			if(parent != this){//si parent == this no hay que hacer nada, solo devolver como nueva raíz a next
				next->left = this->left;
				parent->right = NULL;
				next->left = parent;
			}
			return next;
		}else{
			return NULL;
		}
	}
	del(this, data);
	return this;
}

//--- del 2
// template <class T>
// Node<T> * Node<T>::del2(Node<T> * node){
	// if(node->right != NULL){
		// Node<T> * next = node->next();
		// if(next == NULL) return NULL;//hay un solo nodo
		// Node<T> * parent = next->parent;
		// if(parent == node){//hay un solo elemento a la derecho
			// cout << "hasta aqui" << endl;
			// next->left = node->left;
			// cout << "oooo " << endl;
		// }else{
			// parent->parent no puede ser NULL xq sino parent == node
			// Node<T> * grandparent = parent->parent;
			// next->left = grandparent->left;
			// parent->left = NULL;
			// next->right = parent;
		// }
		// return next;//la nueva raíz
	// }else if(node->left != NULL){
		// cout << "hasta aca" << endl;
		// Node<T> * next = node->previous();
		// if(next == NULL) return NULL;
		// Node<T> * parent = next->parent;
		// if(parent != node){//si parent == node no hay que hacer nada, solo devolver como nueva raíz a next
			// next->left = node->left;
			// parent->right = NULL;
			// next->left = parent;
		// }
		// return next;
	// }else{
		// return NULL;
	// }	
// }


// template <class T>
// Node<T> * Node<T>::del2(T data){
	// cout << this->data << endl;
	// if(this == NULL) return NULL;
	// Node<T> * newRoot = NULL;
	// if(this->data == data){
		// newRoot = this->del2(this); 
	// }else{
		// if(this->left != NULL) newRoot = this->left->del2(data);
		// if(this->right != NULL) newRoot = this->right->del2(data);
	// }
	// if(newRoot == NULL) return this;
	// return newRoot;
// }


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
Node<T> * mostRight(Node<T> * node){
	Node<T> * result = node;
	while(node->right != NULL){
		node = node->right;
	}
	return node;
}

template <class T>
Node<T> * Node<T>::previous(){
	if(this == NULL) return NULL;
	if(this->left == NULL) return NULL;
	return mostLeft(this->left);
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

	cout << "--- Casos en donde se borra la raíz ---" << endl;
	
	cout << "caso 1" << endl;
	Node<int> * root2 = new Node<int>(4, 0, NULL);
	root2->insert(1,1);
	root2->insert(2,2);
	root2->insert(3,3);
	root2->inOrder();cout << endl;
	root2 = root2->del(4);
	root2->inOrder();cout << endl;

	cout << "caso 2" << endl;
	Node<int> * root3 = new Node<int>(4, 0, NULL);
	root3->insert(5,1);
	root3->inOrder();cout << endl;
	root3 = root3->del(4);cout << "delete 4" << endl;
	root3->inOrder();cout << endl;

	cout << "caso 3" << endl;
	auto root4 = new Node<int>(4, 0, NULL);
	root4->insert(3,1);
	root4->inOrder();cout << endl;
	root4 = root4->del(4);cout << "delete 4" << endl;
	root4->inOrder();cout << endl;
	
	cout << "caso 4" << endl;
	Node<int> * root5 = new Node<int>(4, 0, NULL);
	root5->insert(2,1);
	root5->insert(6,2);
	root5->insert(5,3);
	root5->inOrder();cout << endl;
	root5 = root5->del(4);
	root5->inOrder();cout << endl;
	assert(root5->data == 5);
	
	cout << "--- caso general --- " << endl;
	Node<int> * root6 = new Node<int>(5, 0, NULL);
	root6->insert(2,1);
	root6->insert(1,2);
	root6->insert(3,3);
	root6->insert(7,4);
	root6->insert(8,6);
	root6->insert(6,6);
	root6->inOrder(); cout << endl;
	root6 = root6->del(7);
	root6->inOrder();cout << endl;
	assert(root6->data == 5);

	
	cout << "--- caso general 2 --- " << endl;
	auto root7 = new Node<int>(5, 0, NULL);
	root7->insert(2,1);
	root7->insert(1,2);
	root7->insert(3,3);
	root7->insert(8,4);
	root7->insert(7,6);
	root7->insert(11,7);
	root7->insert(6,8);
	root7->insert(10,9);
	root7->insert(9,10);
	
	assert((root7->getNode(8))->data == 8);
	
	root7->inOrder(); cout << endl;
	cout << "borrar 8" << endl;
	root7 = root7->del(8);
	root7->inOrder();cout << endl;
	
	// Node<int> * n11 = root7->getNode(11);
	// cout << n11->data << endl;
	// Node<int> * n5 = root7->getNode(5);
	// assert(n5->data == 5);
	// cout << "n5->right->data " << n5->right->data << endl; 
	// assert(root7->data == 5);
	// Node<int> * n9 = root7->getNode(9);
	// assert(n9->left->data == 7);
	// assert(n9->right->data == 11);

	// cout << "borrar 11" << endl;
	// assert(n11->right == NULL);
	// root7 = root7->del(11);
	// root7->inOrder();cout << endl;
	// assert(n9->right->data == 10);
	
	// cout << "borrar 9" << endl; 
	// root7 = root7->del(9);
	// assert(root7->data == 5);
	// root7->inOrder();cout << endl;
	
}
