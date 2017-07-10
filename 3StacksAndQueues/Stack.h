#include <iostream>
#include <vector>
#include <exception>
#include <cassert>

using namespace std;

class EmptyException : public exception
{
  virtual const char* what() const throw()
  {
    return "Invalidate operation! The stack is Empty";
  }
} emptyException;

template <class T>
class Stack{
	public:
		template <class S>
		class StackNode{
			public:
				S data;
				StackNode * next;
				StackNode(S data){
					this->data = data;
				}
		};
		
		StackNode<T> * top;
		int lenght;
		Stack(){
			top = NULL;
			lenght = 0;
		}
		Stack(T item){
			StackNode<T> * first = new StackNode<T>(item);
			top = first;
			lenght = 1;
		}
		bool isEmpty();
		T peek();
		void pop();
		void push(T item);
		int size();
		void print();
	
};

template <class T> bool Stack<T>::isEmpty(){
	return this->top == NULL;
}

template <class T> T Stack<T>::peek(){
	if(this->isEmpty()){
		throw emptyException;
	}
	T top = this->top->data;
	return top;
}

template <class T> void Stack<T>::pop(){
	if(this->isEmpty()){
		throw emptyException;
	}
	StackNode<T> * nodeToDelete = top;
	top = top->next;
	nodeToDelete = NULL;
	lenght--;
}

template <class T> void Stack<T>::push(T item){
	StackNode<T> * newTop = new StackNode<T>(item);
	StackNode<T> * oldTop = top;
	top = newTop;
	top->next = oldTop;
	lenght++;
}


template <class T> int Stack<T>::size(){
	return lenght;
}

template <class T> void Stack<T>::print(){
	StackNode<T> * node = this->top;
	while(node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}
