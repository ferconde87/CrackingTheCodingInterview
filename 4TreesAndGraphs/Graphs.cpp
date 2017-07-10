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

int main(){
	
	Graph<string> * graph = new Graph<string>();
	
	Node<string> * node1 = new Node<string>("1");
	Node<string> * node2 = new Node<string>("2");
	Node<string> * node3 = new Node<string>("3");
	Node<string> * node4 = new Node<string>("4");
	Node<string> * node5 = new Node<string>("5");
	Node<string> * node6 = new Node<string>("6");
	Node<string> * node7 = new Node<string>("7");
	Node<string> * node8 = new Node<string>("8");
	Node<string> * node9 = new Node<string>("9");
	Node<string> * node10 = new Node<string>("10");
	Node<string> * node11 = new Node<string>("11");
	Node<string> * node12 = new Node<string>("12");
	
	vector<Node<string>*> nodes;
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	nodes.push_back(node6);
	nodes.push_back(node7);
	nodes.push_back(node8);
	nodes.push_back(node9);
	nodes.push_back(node10);
	nodes.push_back(node11);
	nodes.push_back(node12);
	
	graph->nodes = nodes;
	
	vector<Node<string> *> children1;
	children1.push_back(node2);
	children1.push_back(node3);
	children1.push_back(node4);
	
	vector<Node<string> *> children2;
	children2.push_back(node5);
	children2.push_back(node6);
	
	vector<Node<string> *> children3;
	children3.push_back(node7);
	children3.push_back(node8);
	
	vector<Node<string> *> children4;
	children4.push_back(node9);
	children4.push_back(node10);
	
	vector<Node<string> *> children5;
	children5.push_back(node11);
	
	vector<Node<string> *> children7;
	children7.push_back(node12);
	
	node1->children = children1;
	node2->children = children2;
	node3->children = children3;
	node4->children = children4;
	node5->children = children5;
	node7->children = children7;
	
	DFS(graph);
	DFSRec(graph);
	BFS(graph);
	
	return 0;
}
