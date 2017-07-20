#include <iostream>

#include <random>

//complejidad de insert, find, delete, getRandomNode igual a la del BST sin rebalanceo de nodos (log n) caso promedio, O(n) peor caso

using namespace std;


template <class T>
class TreeNode{
	private:
		T data;
		TreeNode<T> * left = NULL; 
		TreeNode<T> * right = NULL;
		int size = 0;
		
	public:
		TreeNode(T data){
			this->data = data;
			left = right = NULL;
			size = 1;
		}
		void insertInOrder(int d);
		TreeNode * getIthNode(int i);
		int get_size() const { return size; }
		T get_data() const { return data; }
		TreeNode<T> * find(int d);
};

template <class T>
void TreeNode<T>::insertInOrder(int d){
	if ( d <= data){
		if(left == NULL){
			left = new TreeNode(d);
		}else{
			left->insertInOrder(d);
		}
	}else{
		if(right == NULL){
			right = new TreeNode(d);
		}else{
			right->insertInOrder(d);
		}
	}
	size++;
}

template <class T>
TreeNode<T> * TreeNode<T>::find(int d){
	if( d == data){
		return this;
	}else if (d <= data){
		return left != NULL ? left->find(d) : NULL;
	}else{
		return right != NULL ? right->find(d) : NULL;
	}
	return NULL;
}


template <class T>
TreeNode<T> * TreeNode<T>::getIthNode(int i){
	int leftSize = left == NULL ? 0 : left->size;
	if( i < leftSize){
		return left->getIthNode(i);
	}else if(i == leftSize){ 
		return this; 
	}else{
		// Skipping over leftSize + 1 nodes, so substract them.
		return right->getIthNode(i - (leftSize +1 ));
	}
}


template <class T>
class Tree{
	public:
		TreeNode<T> * root = NULL;
		
		Tree(T data){
			root = new TreeNode<T>(data);
		}
		
		int size() const { return root == NULL ? 0 : root->get_size(); }
		
		TreeNode<T> * getRandomNode(){
			if(root == NULL) return NULL;
			std::random_device rd;     // only used once to initialise (seed) engine
			std::mt19937 rng(rd());	   // random-number engine used (Mersenne-Twister in this case)
			std::uniform_int_distribution<int> uni(0,size()); // guaranteed unbiased			
			int random_integer = uni(rng);
			return root->getIthNode(random_integer);
		}
		
		void insertInOrder(T value){
			if(root == NULL){
				root = new TreeNode<T>(value);
			}else{
				root->insertInOrder(value);
			}
		}
};





int main(){
	
	// std::random_device rd;     // only used once to initialise (seed) engine
	// std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	// std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
	// auto random_integer = uni(rng);	
	
	Tree<int> * tree = new Tree<int>(5);
	tree->insertInOrder(2);
	tree->insertInOrder(7);
	tree->insertInOrder(1);
	tree->insertInOrder(4);
	tree->insertInOrder(6);
	tree->insertInOrder(8);
	
	cout << tree->getRandomNode()->get_data() << endl;
	
	return 0;
}