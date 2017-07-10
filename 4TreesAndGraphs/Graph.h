#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template <class T>
class Node{
	public:
		T name;
		vector<Node*> children;
		Node(T name){
			this->name = name;
		}
};

template <class T>
class Graph{
	public:
		vector<Node<T>*> nodes;
};

template <class T> 
void BFS(Graph<T> * graph){
	if(graph == NULL or graph->nodes.size() == 0) return;
	Node<T> * root = graph->nodes[0];
	queue<Node<T>*> queue;
	queue.push(root);
	while(!queue.empty()){
		Node<T>* node = queue.front();
		cout << node->name << " ";
		queue.pop();
		for(auto n : node->children)
			queue.push(n);
	}
	cout << endl;
}

template <class T>
void DFS(Graph<T> * graph){
	if(graph == NULL or graph->nodes.size() == 0) return;
	Node<T>* root = graph->nodes[0];
	stack<Node<T>*> stack;
	stack.push(root);
	while(!stack.empty()){
		Node<T> * node = stack.top();
		cout << node->name << " ";
		stack.pop();
		for(int i = node->children.size()-1; i >= 0; i--){
			stack.push(node->children[i]);
		}
	}
	cout << endl;
}

template <class T>
void DFSRec(Node<T> * node){
	cout << node->name << " ";
	for(auto n : node->children)
		DFSRec(n);
}

template <class T>
void DFSRec(Graph<T> * graph){
	if(graph == NULL or graph->nodes.size() == 0) return;
	DFSRec(graph->nodes[0]);
	cout << endl;
}
