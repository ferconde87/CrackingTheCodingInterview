#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
	Node * left;
	Node * right;
	string name;
	Node(string name){
		this->name = name;
	}
};

Node * copy_recursive(Node * node, unordered_map<Node *, Node *> & map){
	if(node == NULL) return NULL;
	auto it = map.find(node);
	if(it != map.end()){
		return it->second;//return the copy created before
	}
	Node * copy = new Node(node->name);
	map[node] = copy;
	copy->left = copy_recursive(node->left, map);
	copy->right = copy_recursive(node->right, map);
	
	Node * prueba = map[node];
	cout << "parent = " << node->name << endl;
	cout << "\t left = " << ((node->left != NULL) ? node->left->name : "NULL") << endl;
	cout << "\t right = " << ((node->right != NULL) ? node->right->name : "NULL") << endl;
	
	return copy;
}

Node * copy_recursive(Node * root){
	unordered_map<Node *, Node *> nodeMap;
	return copy_recursive(root, nodeMap);
}

int main(){
	Node * root = new Node("root");
	Node * a = new Node("a");
	Node * b = new Node("b");
	Node * c = new Node("c");
	Node * d = new Node("d");
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = b;
	b->left = d;
	b->right = c;
	d->left = a;
	Node * copy = copy_recursive(root);
}
