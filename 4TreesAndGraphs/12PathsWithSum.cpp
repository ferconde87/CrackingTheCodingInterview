#include <iostream>
#include <unordered_map>
#include <vector>

//#include "BinaryTree.h"

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

void printMap(unordered_map<int, int> map){
	cout << "---------------------" << endl;
	for(auto it = map.begin(); it != map.end(); it++)
		cout << it->first << " " << it->second << endl;	
	cout << "---------------------" << endl;
}

//int result = 0;

// 1 Recursive method. O(n log n) in a balanced tree
// 					   O (node ^ 2) in a non-balanodeced tree   
int pathsWithSum(Node<int> * node, int target, int sum){
	if(node == NULL) return 0;
	sum += node->data;
	int result = sum == target ? 1 : 0;
	result += pathsWithSum(node->left, target, sum);
	result += pathsWithSum(node->right, target, sum);
	return result;
}


int pathsWithSum(Node<int> * root, int target){
	if(root == NULL) return 0;
	int rootSum = pathsWithSum(root, target, 0);
	int leftSum = pathsWithSum(root->left, target);
	int rightSum = pathsWithSum(root->right, target);
	return rootSum + leftSum + rightSum;
}


// 2 Using memoization O(n)
int pathsWithSum2(Node<int> * n, int target, int sum, unordered_map<int, int> map){
	if(n == NULL) return 0;
	int result = 0;
	sum += n->data;
	int needed = sum - target;
	auto it = map.find(needed); 
	if(it != map.end()){
		result += it->second;
	}
	auto itSum = map.find(sum);
	if(itSum!=map.end()){
		itSum->second++;
	}else{
		map[sum] = 1;
	}
	result += pathsWithSum2(n->left, target, sum, map) + pathsWithSum2(n->right, target, sum, map);
	return result;
}


int pathsWithSum2(Node<int> * root, int target){
	unordered_map<int, int> map;
	if(root == NULL) return 0;
	map[0] = 1;	
	return pathsWithSum2(root, target, 0, map);
}


int pathsWithSumV(vector<int> v, int target){
	unordered_map<int, int> map;
	int sum = 0;
	int result = 0;
	for(int i = 0; i < v.size(); i++){
		sum += v[i];
		int needed = sum - target;
		auto itSum = map.find(needed);
		if(itSum!=map.end())
			result+= itSum->second;
		auto it = map.find(sum);
		if(it != map.end()){
			it->second++;
		}else{
			map[sum] = 1;
		}
	}
	return result;
}


int main(){

	Node<int> * root = new Node<int>(2);
	Node<int> * node2 = new Node<int>(1);
	Node<int> * node3 = new Node<int>(2);
	Node<int> * node4 = new Node<int>(-1);
	Node<int> * node5 = new Node<int>(2);
	Node<int> * node6 = new Node<int>(0);
	Node<int> * node7 = new Node<int>(1);
	Node<int> * node8 = new Node<int>(2);
	Node<int> * node9 = new Node<int>(-1);
	Node<int> * node10 = new Node<int>(1);
	Node<int> * node11 = new Node<int>(1);
	
	root->left = node2;
	root->right = node3;
	node2->left = node4;
	node2->right = node5;
	node4->left = node7;
	node4->right = node8;
	node7->left = node11;
	node5->right = node9;
	node3->right = node6;
	node6->left = node10;

	cout << "result\tresult 2" << endl;
	cout << pathsWithSum(root, 5); cout << "\t";//2
	cout << pathsWithSum2(root, 5) << endl;//2
	
	auto node12 = new Node<int>(1);
	
	node11->right = node12;
	
	cout << pathsWithSum(root, 5); cout << "\t";//3
	cout << pathsWithSum2(root, 5) << endl;//3
	
	auto node13 = new Node<int>(0);
	
	node12->right = node13;
	
	cout << pathsWithSum(root, 5); cout << "\t";//4
	cout << pathsWithSum2(root, 5) << endl;//4
	
	auto node14 = new Node<int>(3);
	
	node6->right = node14;

	cout << pathsWithSum(root, 5); cout << "\t";//5
	cout << pathsWithSum2(root, 5) << endl;//5
	
	//~ auto node15 = new Node<int>(2);
	
	//~ cout << pathsWithSum(root, 5) << endl;//5
	//~ cout << pathsWithSum2(root, 5) << endl;//5
	
	Node<int> * r2 = new Node<int>(10);
	Node<int> * n2 = new Node<int>(5);
	Node<int> * n3 = new Node<int>(1);
	Node<int> * n4 = new Node<int>(2);
	Node<int> * n5 = new Node<int>(-1);
	Node<int> * n5b = new Node<int>(-1);
	Node<int> * n6 = new Node<int>(7);
	Node<int> * n7 = new Node<int>(1);
	Node<int> * n8 = new Node<int>(2);
	r2->left = n2;	
	n2->left = n3;	
	n3->left = n4;	
	n4->left = n5;
	n5->left = n5b;	
	n5b->left = n6;	
	n6->left = n7;	
	n7->left = n8;	
	cout << pathsWithSum(root, 5); cout << "\t";//5	
	cout << pathsWithSum2(r2, 8) << endl;//5	
	
	//~ cout << "Prueba con un vector" << endl;
	//~ vector<int> v = {10, 5, 1, 2, -1, -1, 7, 1, 2};
	//~ cout << pathsWithSumV(v, 8) << endl;
	
	return 0;
}
