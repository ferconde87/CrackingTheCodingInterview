#include <iostream>
#include <cassert>
#include "BinarySearchTree.h"
#include <vector>


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
void weaveLists(vector<T> first, vector<T> second, vector<vector<T> > result, vector<T> prefix){
	/* One list is empty. Add remainder to [a cloned] prefix and store result. */
	if(first.size()==0 || second.size() == 0){
		result = prefix;
		result.insert(result.end(), first.begin(), first.end());
		result.insert(result.end(), second.begin(), second.end());
	}
	/* Recurse with head of first added to the prefix. Removing the head will damage
	 * first, so we'll need to put it back where we found it afterwards. */
	 
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
	//recurse on left and right subtrees
	vector<vector<T> > leftSeq = allSequences(node->left);
	vector<vector<T> > rightSeq = allSequences(node->right);
	//weave together each vector from the left and right sides
	for(auto left : leftSeq){
		for(auto right : rightSeq){
			vector<vector<T> > weaved;
			weaveLists(left, right, weaved, prefix);
			result.push_back(weaved);
		}
	}
	return result;
}

int main(){
	
	
	
	return 0;
}