#include <iostream>
#include <unordered_map>

#include "BinaryTree.h"

using namespace std;

int result = 0;

int pathsWithSum(Node<int> * node, int target, int sum){
	if(node == NULL) return 0;
	sum += node->data;
	int result = sum == target ? 1 : 0;
	result += pathsWithSum(node->left, target, sum);
	result += pathsWithSum(node->right, target, sum);
	return result;
}


int pathsWithSum(Node<int> * root, int target){
	// unordered_map<int, int> map;
	int rootSum = pathsWithSum(root, target, 0);
	int leftSum = pathsWithSum(root->left, target, 0);
	int rightSum = pathsWithSum(root->right, target, 0);
	return rootSum + leftSum + rightSum;
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

	cout << pathsWithSum(root, 5) << endl;//2
	
	auto node12 = new Node<int>(1);
	
	node11->right = node12;
	
	cout << pathsWithSum(root, 5) << endl;//3
	
	auto node13 = new Node<int>(0);
	
	node12->right = node13;
	
	cout << pathsWithSum(root, 5) << endl;//4
	
	auto node14 = new Node<int>(3);
	
	node6->right = node14;

	cout << pathsWithSum(root, 5) << endl;//5
	
	auto node15 = new Node<int>(2);
	
	cout << pathsWithSum(root, 5) << endl;//5
	
	
	
	return 0;
}
