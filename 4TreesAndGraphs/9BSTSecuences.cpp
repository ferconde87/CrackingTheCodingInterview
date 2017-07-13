#include <iostream>
#include <cassert>
#include "BinarySearchTree.h"
#include <vector>
#include <queue>


using namespace std;



// template <class T>
// vector<vector<T> > BSTSecuences0(Node<T> * root, vector<vector<T> > & result){
	
	// if(root == NULL) return result;
	
	
	// BSTSecuences0(root->left, result.push_back(root->data));
	// BSTSecuences0(root->right, result.push_back(root->data));
	
	// return result;
// }

// template <class T>
// vector<vector<T> > BSTSecuences0(Node<T> * root){
	// vector<vector<T> > result;
	// BSTSecuences0(root, result);
	// return result;
// }


// // -------------------------------------------

// template <class T>
// vector<T> secuence(Node<T> * node, vector<T> & v){
	// if(node == NULL) return v;
	// v.push_back(node->data);
	// secuence(node->left, v);
	// secuence(node->right, v);
// }

// template <class T>
// vector<vector<T> > BSTSecuences(Node<T> * root, vector<vector<T> > & result){
	
	// if(root == NULL) return result;
	
	// result.push_back()
	
	// BSTSecuences0(root->left, result.push_back(root->data));
	// BSTSecuences0(root->right, result.push_back(root->data));
	
	// return result;
// }

// template <class T>
// vector<vector<T> > BSTSecuences(Node<T> * root){
	// vector<vector<T> > result;
	// BSTSecuences(root, result);
	// return result;
// }

// from CTCI
/* Weave lists together in all possible ways. This algorithm works by removing the
 * head from one list, recursing, and then doing the same thing with the other
 * list. */

 
template <class T>
void weaveLists(vector<T> & first, vector<T> & second, vector<vector<T> > & results, vector<T> & prefix){
	/* One list is empty. Add remainder to [a cloned] prefix and store result. */
	if(first.size()==0 || second.size() == 0){
		vector<T> result = prefix;
		result.insert(result.end(), first.begin(), first.end());
		result.insert(result.end(), second.begin(), second.end());
		results.push_back(result);
		return;
	}
	/* Recurse with head of first added to the prefix. Removing the head will damage
	 * first, so we'll need to put it back where we found it afterwards. */
	 T headFirst = first[0];
	 first.erase(first.begin());
	 prefix.push_back(headFirst);
	 weaveLists(first, second, results, prefix);
	 prefix.pop_back();
	 first.insert(first.begin(), headFirst);
	 
	 /* Do the same thing with second, damaging and then restoring the list.*/
	 T headSecond = second[0];
	 second.erase(second.begin());
	 prefix.push_back(headSecond);
	 weaveLists(first, second, results, prefix);
	 prefix.pop_back();
	 second.insert(second.begin(), headSecond);	 
}

template <class T>
void print(vector<T> & v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
vector<vector<T> > allSequences(Node<T>* node){
	vector<vector<T> > result;
	if(node == NULL){
		vector<T> v;
		result.push_back(v);
		return result;
	}
	vector<T> prefix;
	prefix.push_back(node->data);
	
	// print(prefix);
	//recurse on left and right subtrees
	vector<vector<T> > leftSeq = allSequences(node->left);
	vector<vector<T> > rightSeq = allSequences(node->right);
	//weave together each vector from the left and right sides
	
	int i = 0;
	for(auto left : leftSeq){
		for(auto right : rightSeq){
			// cout << "left = " << *left.begin() << " | " << "right = " << *right.begin() << endl;
			// cout << i << endl; i++;
			// cout << "size left = " << left.size() << endl;
			// cout << "size right = " << right.size() << endl;
			vector<vector<T> > weaved;
			weaveLists(left, right, weaved, prefix);
			cout << weaved.size() << endl;
			result.insert(result.begin(), weaved.begin(), weaved.end());
		}
	}
	cout << endl;
	return result;
}

template <class T>
void print(vector<vector<T> > & v){
	for(int i = 0; i < v.size(); i++){
		vector<T> w = v[i];
		for(int j = 0; j < w.size(); j++){
			cout << w[j] << " ";
		}
		cout << endl;;
	}
	cout << endl;
}



int main(){
	
	Node<int> * root = new Node<int>(2);
	root->insert(1);
	root->insert(3);
	
	auto res = allSequences(root);
	cout << "--------------------" << endl;
	print(res);
	
	return 0;
}