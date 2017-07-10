#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

template <class T>
class Node{
	private:
		Node * left;
		Node * right;
		T data;
		Node * insert(Node * root, T data);
		void inOrder(Node * root);
		void preOrder(Node * root);
		void preOrderIterative(Node * root);
		void postOrder(Node * root);
		void levelOrder(Node * root);
		
	public: 
		Node(T data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
	
		void insert(T data);
		void inOrder();
		void preOrder();
		void preOrderIterative();
		void postOrder();
		void levelOrder();
		
};

template <class T>
void  Node<T>::insert(T data){
	insert(this, data);
}

template <class T>
Node<T> *  Node<T>::insert(Node * root, T data){
	if(root == NULL){
		root = new Node(data);
	}else if(data < root->data){
			root->left = insert(root->left, data);
		}else
			root->right = insert(root->right, data);
	return root;
}

template <class T>
void Node<T>::inOrder(){
	inOrder(this);
	cout << endl;
}

template <class T>
void Node<T>::inOrder(Node * root){
	if(root == NULL) return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

template <class T>
void Node<T>::preOrder(){
	preOrder(this);
	cout << endl;
}

template <class T>
void Node<T>::preOrder(Node * root){
	if(root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

template <class T>
void Node<T>::preOrderIterative(){
	preOrderIterative(this);
	cout << endl;
}

template <class T>
void Node<T>::preOrderIterative(Node * root){
	if(root == NULL) return;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()){
		Node* top = s.top();
		cout << top->data << " ";
		s.pop();
		if(top->right != NULL) s.push(top->right);
		if(top->left != NULL) s.push(top->left);
	}
}

template <class T>
void Node<T>::postOrder(){
	postOrder(this);
	cout << endl;
}

template <class T>
void Node<T>::postOrder(Node * root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

template <class T>
void Node<T>::levelOrder(){
	levelOrder(this);
	cout << endl;
}

template <class T>
void Node<T>::levelOrder(Node * root){
	if(root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* elem = q.front();
		cout << elem->data << " ";
		q.pop();
		if(elem->left != NULL) q.push(elem->left);
		if(elem->right != NULL) q.push(elem->right);
	}
}

int main(){
	
	Node<int> * root = new Node<int>(4);
	root->insert(2);
	root->insert(3);
	root->insert(1);
	root->insert(6);
	root->insert(5);
	root->insert(7);
	root->insert(8);
	
	cout << "inOrder = ";root->inOrder();
	
	cout << "preOrder = ";root->preOrder();
	
	cout << "postOrder = ";root->postOrder();
	
	cout << "levlOrder = ";root->levelOrder();

	cout << "preOrderIterative = ";root->preOrderIterative();
	
	return 0;
}
