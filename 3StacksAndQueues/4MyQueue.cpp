#include "Stack.h"

using namespace std;

template <class T>
class MyQueue{
	private:
		Stack<T> * stack;
		Stack<T> * queue;
		int lenght;
	public:
		MyQueue(){
			stack = NULL;
			queue = NULL;
			lenght = 0;
		}
		void add(T item);
		bool isEmpty();
		T peek();
		void print();
		void remove();
		int size();
};

template <class T> bool MyQueue<T>::isEmpty(){
	return queue->isEmpty();
}

//return the top of the queue
template <class T> T MyQueue<T>::peek(){
	return queue->peek();
}

//remove the first item of the queue
template <class T> void MyQueue<T>::remove(){
	queue->pop();
	lenght--;
}

//add an item to the end of the Queue
template <class T> void MyQueue<T>::add(T item){
	if(queue == NULL){
		queue = new Stack<T>(item);
		stack = new Stack<T>();
		return;
	}
	while(!queue->isEmpty()){
		T oldItem = queue->peek();
		stack->push(oldItem);
		queue->pop();
	}
	queue->push(item);
	while(!stack->isEmpty()){
		T oldItem = stack->peek();
		queue->push(oldItem);
		stack->pop();
	}
	lenght++;
}


template <class T> int MyQueue<T>::size(){
	return lenght;
}

template <class T> void MyQueue<T>::print(){
	queue->print();
}

int main(){
	MyQueue<int> * myQueue = new MyQueue<int>();
	myQueue->add(1);
	myQueue->add(2);
	myQueue->add(3);
	myQueue->add(4);
	myQueue->print();
	myQueue->add(5);
	assert(myQueue->peek() == 1);
	myQueue->remove();
	myQueue->print();
	assert(myQueue->peek() == 2);
	myQueue->remove();
	myQueue->remove();
	myQueue->remove();
	assert(myQueue->peek() == 5);
	myQueue->print();
	myQueue->remove();
	myQueue->add(1);
	myQueue->add(2);
	assert(myQueue->peek() == 1);
	myQueue->print();
	assert(!myQueue->isEmpty());
	myQueue->remove();
	assert(myQueue->peek() == 2);
	myQueue->remove();
	assert(myQueue->isEmpty());
	
	return 0;
}
