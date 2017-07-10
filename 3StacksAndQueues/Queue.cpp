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


int main(){
	
	Queue<int> * queue = new Queue<int>(1);
	queue->add(2);
	queue->add(3);
	queue->add(4);
	queue->add(5);
	
	queue->print();
	
	assert(!queue->isEmpty());
	assert(queue->peek() == 1);
	queue->remove();
	
	queue->print();
	
	assert(queue->peek() == 2);
	queue->remove();
	assert(queue->size() == 3);
	queue->add(6);
	
	queue->print();
	
	assert(queue->peek() == 3);
	queue->remove();
	queue->remove();
	queue->remove();
	
	queue->print();
	
	queue->remove();
	assert(queue->isEmpty());
	
	queue->print();
	
	return 0;
}
