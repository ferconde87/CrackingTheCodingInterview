/* Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
route between two nodes. */

#include "Graph.h"
#include <iostream>
#include <cassert>
#include <unordered_set>

using namespace std;

template <class T>
bool isRouteBetweenNodes(Graph<T> * graph, Node<T> * a, Node<T> * b){
	if(graph == NULL or graph->nodes.size() == 0) return false;
	queue<Node<T>* > queue;
	queue.push(a);
	while(!queue.empty()){
		auto node = queue.front();
		queue.pop();
		if(node->name == b->name)
			return true;
		for(auto n : node->children)
			queue.push(n);
	}
	return false;
}	

//falto usar un hashSet para saber que nodos se visitaron
template <class T>
bool isRouteBetweenNodes2(Graph<T> * graph, Node<T> * a, Node<T> * b){
	if(graph == NULL or graph->nodes.size() == 0) return false;
	unordered_set<Node<T>*> set;
	queue<Node<T>* > queue;
	queue.push(a);
	set.insert(a);
	while(!queue.empty()){
		auto node = queue.front();
		queue.pop();
		if(node->name == b->name){
			return true;
		}
		for(auto n : node->children){
			if(set.find(n)==set.end()){
				queue.push(n);
				set.insert(n);
			}
		}
	}
	return false;
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
	
	assert(isRouteBetweenNodes2(graph, node2, node11));
	assert(isRouteBetweenNodes2(graph, node1, node11));
	assert(isRouteBetweenNodes2(graph, node3, node8));
	assert(isRouteBetweenNodes2(graph, node3, node7));
	assert(!isRouteBetweenNodes2(graph, node7, node8));
	assert(isRouteBetweenNodes2(graph, node4, node10));
	assert(!isRouteBetweenNodes2(graph, node4, node5));
	assert(!isRouteBetweenNodes2(graph, node4, node1));
	
	vector<Node<string> *> children12;
	children12.push_back(node3);
	node12->children = children12;
	isRouteBetweenNodes2(graph, node12, node1);
	
	
	
	return 0;
}
