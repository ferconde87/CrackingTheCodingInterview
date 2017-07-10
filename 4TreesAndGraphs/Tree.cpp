#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Tree{
	template <class S>
	class Node{
		S data;
		vector<S> children;
	};
	Node<T> * root;
};

int main(){
	
	
	return 0;
}
