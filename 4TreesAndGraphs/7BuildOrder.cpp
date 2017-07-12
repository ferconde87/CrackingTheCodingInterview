#include "Graph.h"
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;


class noPossible : public exception
{
  virtual const char* what() const throw()
  {
    return "Not Possible!";
  }
} noPossible;

template <class T>
vector<Node<T> *> buildOrder(Graph<T> * graph){
	vector<Node<T> *> result;
	if(graph == NULL) return result;
	unordered_set<Node<T> *> visited;
	int n = graph->nodes.size();
	int i = 0;
	vector<Node<T> *> & nodes = graph->nodes;
	
	stack<Node<T> *> stack;
	for(auto it = nodes.begin(); it != nodes.end(); it++){
		if((*it)->children.size() == 0){
			result.push_back(*it);
			stack.push(*it);
			visited.insert(*it);
		}
	}
	while(!stack.empty() or i < n){
		while(!stack.empty()){
			Node<T> * node = stack.top();
			stack.pop();
			for(auto it = nodes.begin(); it != nodes.end(); it++){
				vector<Node<T>*> & children = (*it)->children;
				for(auto itChild = children.begin(); itChild != children.end(); itChild++){
					if(*itChild == node){
						children.erase(itChild);
						break;
					}	
				}
				
			}
		}
		for(auto it = nodes.begin(); it != nodes.end(); it++){
			if(visited.find(*it)!=visited.end()) continue;
			if((*it)->children.size() == 0){
				result.push_back(*it);
				stack.push(*it);
				visited.insert(*it);
			}
		}
		//si en alguna pasada no encontramos ningún nodo del que podamos continuar (sin hijos)
		//el stack queda vacío y nos vamos
		i++;
	}
	
	if(result.size()==n)
		return result;
	
	throw noPossible;

}

template <class T>
struct edge{
	T src;
	T dst;
};

template <class T>
Graph<T> * makeGraph(vector<T> & projects, vector<edge<T> > & dependencies){
	Graph<T> * graph = new Graph<T>();
	vector<Node<T> *> nodes;
	unordered_map<T, Node<T> *> map;
	for(int i = 0; i < projects.size(); i++){
		Node<T> * node = new Node<T>(projects[i]);
		nodes.push_back(node);
		map[projects[i]] = node;
	}
	graph->nodes = nodes;
	for(int i = 0; i < dependencies.size(); i++){
		Node<T>* src = map[dependencies[i].src];
		Node<T>* dst = map[dependencies[i].dst];
		src->children.push_back(dst);
	}
	
	return graph;
}


template <class T>
vector<Node<T>*> buildOrder(vector<T> & projects, vector<edge<T> > & dependencies){
	Graph<T> * graph = makeGraph(projects, dependencies);
	vector<Node<T>*> result = buildOrder2(graph);
	return result;
}

template <class T>
void print(Graph<T> * graph){
	cout << "print graph: " << endl;
	vector<Node<T>*> nodes = graph->nodes;
	for(int i = 0; i < nodes.size(); i++){
		cout << nodes[i]->name << " ";
		vector<Node<T>*> children = nodes[i]->children;
		cout << "| children: ";
		for(int j = 0; j < children.size(); j++){
			cout << children[j]->name << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <class T>
void print(vector<Node<T>*> & v){
	for(int i = 0; i < v.size(); i++)
		cout << v[i]->name << " ";
	cout << endl;
}

template <class T>
void printReverse(vector<Node<T>*> & v){
	for(int i = v.size()-1; i >= 0; i--)
		cout << v[i]->name << " ";
	cout << endl;
}

template <class T>
vector<Node<T> *> buildOrder2(Graph<T> * graph){
	vector<Node<T> *> result;
	if(graph == NULL) return result;
	unordered_set<Node<T> *> visited;
	stack<Node<T>*> stack;
	int n = graph->nodes.size();
	int i = 0;
	vector<Node<T> *> & nodes = graph->nodes;
	
	while(i < n){
		while(!stack.empty()){
			Node<T> * node = stack.top();
			stack.pop();
			for(auto it = nodes.begin(); it != nodes.end(); it++){
				vector<Node<T>*> & children = (*it)->children;
				for(auto itChild = children.begin(); itChild != children.end(); itChild++){
					if(*itChild == node){
						children.erase(itChild);
						break;
					}	
				}
				
			}
		}
		for(auto it = nodes.begin(); it != nodes.end(); it++){
			if(visited.find(*it)!=visited.end()) continue;
			if((*it)->children.size() == 0){
				result.push_back(*it);
				stack.push(*it);
				visited.insert(*it);
			}
		}
		
		if(stack.empty()) break;
		i++;
	}
	
	if(result.size() < n)
		throw noPossible;
	
	return result;
}

int main(){
	
	int n, m;
	cin >> n >> m;
	vector<string> p(n);
	vector<edge<string> > d(m);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < m; i++){
		cin >> d[i].src;
		cin >> d[i].dst;
	}
	
	vector<Node<string> *> result = buildOrder(p, d);
	printReverse(result);
	return 0;
}