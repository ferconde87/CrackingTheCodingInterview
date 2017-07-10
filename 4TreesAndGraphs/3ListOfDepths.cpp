#include "BinarySearchTree.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

/*List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you'll have D linked lists)*/

//devuelve por cada nodo, su profundidad... sirve esto.. pero hay que agregar un map o algo para tener el nodo asociado
template <class T>
vector<int> depths(Node<T> * node, vector<int> & v, int level){
	if(node == NULL) return v;
	v.push_back(level);
	depths(node->left, v, level+1);
	depths(node->right, v, level+1);
	return v;	
}

template <class T>
vector<int> depths(Node<T> * root){
	vector<int> v;
	depths(root, v, 0);
	return v;	
}

///////////////// 1er solución DFS //////////////////////////////////
//primero creo un map < node, level> y después llevo a lista de listas de profundidades 
template <class T>
void listOfDepths(Node<T> * node, unordered_map<T, int> & map, int level){
	if(node == NULL) return;
	map[node->data] = level;
	listOfDepths(node->left, map, level+1);
	listOfDepths(node->right, map, level+1);
}

template <class T>
vector< vector<T> > listOfDepths(Node<T>* root){
	unordered_map< T, int> map;
	listOfDepths(root, map, 0);
	
	int maxDepth = 0;
	for(auto it = map.begin(); it != map.end(); it++)
		if(it->second > maxDepth)
			maxDepth = it->second;
	
	vector< vector<T> > result(maxDepth+1);
	for(auto it = map.begin(); it != map.end(); it++){
	cout << "it->second = " << it->second << " | " << "it->first = " << it->first << endl;
		result[it->second].push_back(it->first);
	}
	
	return result;	
}

/////////////////versión mejorada DFS ///////////////////////////////////////////
//voy creando la lista de listas de profundidades a medida que recorro el árbol
template <class T>
void listOfDepths2(Node<T> * root, vector< vector<T> > & lists, int level){
	if(root == NULL) return;
	if(lists.size() <= level){
		vector<T> list;
		lists.push_back(list);
	}
	lists[level].push_back(root->data);
	listOfDepths2(root->left, lists, level+1);
	listOfDepths2(root->right, lists, level+1);
}

template <class T>
vector< vector< T> > listOfDepths2(Node<T> * root){
	vector< vector<T> > lists;
	listOfDepths2(root, lists, 0);
	return lists;
}

////////////////////usando BFS ///////////////////////////////////////////////////
template <class T>
vector < vector < Node<T> * > > listOfDepths3(Node<T> * root){
	vector< vector < Node<T> * > > v;
	if(root == NULL) return v;
	vector<Node<T> *> children;
	vector<Node<T> *> parents;
	children.push_back(root);
	v.push_back(children);
	while(children.size()>0){
		parents = children;
		children.clear();
		for(int i = 0; i < parents.size(); i++){
			Node<T> * p = parents[i];
			if(p->left != NULL){
				children.push_back(p->left);
			}
			if(p->right != NULL){
				children.push_back(p->right);
			}
		}
		v.push_back(children);
	}
	return v;
}

// prints
template <class T>
void print(vector< vector< Node<T> *> > lists){
	for(int i = 0; i < lists.size(); i++){
		for(int j = 0; j < lists[i].size(); j++){
			cout << lists[i][j]->data << " ";
		}
		cout << endl;
	}	
}

template <class T>
void print(vector< vector< T> > lists){
	for(int i = 0; i < lists.size(); i++){
		for(int j = 0; j < lists[i].size(); j++){
			cout << lists[i][j] << " ";
		}
		cout << endl;
	}	
}

void print(vector<int> v){
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
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
	
	Node<int> * root2 = new Node<int>(6);
	root2->insert(3);
	root2->insert(9);
	root2->insert(1);
	root2->insert(4);
	root2->insert(5);
	root2->insert(2);
	root2->insert(7);
	root2->insert(8);
	root2->insert(11);
	root2->insert(10);
	root2->insert(12);
	
	cout << "árbol recorrido por nivel : ";
	root2->levelOrder();
	
	cout << "profundidades de los nodos: ";
	vector<int> v2 = depths(root2);
	print(v2);
	cout << "profundidad <-> nodo:" << endl;
	vector< vector< int > > result = listOfDepths(root2);
	cout << endl;
	cout << "1er solución -----------------------" << endl;
	print(result);
	
	cout << "------------------------------------" << endl;
	result = listOfDepths2(root2);
	print(result);
	
	cout << "BFS----------------------------------" << endl;
	print(listOfDepths3(root2));
	
	return 0;
}



