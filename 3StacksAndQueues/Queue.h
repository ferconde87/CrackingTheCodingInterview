#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <cassert>

using namespace std;

class EmptyException : public exception
{
  virtual const char* what() const throw()
  {
    return "Invalidate operation! The queue is Empty";
  }
} emptyException;

template <class T>
class Queue{
	public:
		template <class S>
		class QueueNode{
			public:
				S data;
				QueueNode * next;
				QueueNode(S data){
					this->data = data;
				}
		};
		
		QueueNode<T> * last;
		QueueNode<T> * first;
		int lenght;
		Queue(){
			last = NULL;
			first = NULL;
			lenght = 0;
		}
		Queue(T item){
			first = new QueueNode<T>(item);
			last = first;
			lenght = 1;
		}
		bool isEmpty();
		T peek();
		void remove();
		void add(T item);
		int size();
		void print();
	
};


template <class T> bool Queue<T>::isEmpty(){
	return this->first == NULL;
}

//return the top of the queue
template <class T> T Queue<T>::peek(){
	if(this->isEmpty()){
		throw emptyException;
	}
	return this->first->data;
}

//remove the first item of the queue
template <class T> void Queue<T>::remove(){
	if(this->isEmpty()){
		throw emptyException;
	}
	QueueNode<T> * nodeToDelete = first;
	first = first->next;
	if(nodeToDelete == last){
		last = NULL;
	}
	nodeToDelete = NULL;
	lenght--;
}

//add an item to the end of the Queue
template <class T> void Queue<T>::add(T item){
	QueueNode<T> * newLast = new QueueNode<T>(item);
	QueueNode<T> * oldLast = last;
	last = newLast;
	oldLast->next = last;
	lenght++;
}


template <class T> int Queue<T>::size(){
	return lenght;
}

template <class T> void Queue<T>::print(){
	QueueNode<T> * node = this->first;
	while(node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}
