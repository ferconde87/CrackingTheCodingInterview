#include "Stack.h"

using namespace std;

template <class T>
class StackMin : Stack<T>{
	private:
		Stack<T> * stack;
		Stack<T> * mins;
	public:
		StackMin(T item){
			stack = new Stack<T>(item);
			mins = new Stack<T>(item);
		}
		bool isEmpty();
		T peek();
		void pop();
		void push(T item);
		int size();
		void print();
		T min();
};

template <class T> bool StackMin<T>::isEmpty(){
	return stack->isEmpty();
}

template <class T> T StackMin<T>::min(){
	return mins->peek();
}

template <class T> T StackMin<T>::peek(){
	return stack->peek();
}

template <class T> void StackMin<T>::pop(){
	stack->pop();
	mins->pop();
}

template <class T> void StackMin<T>::push(T item){
	if(isEmpty()){
		stack = new Stack<T>(item);
		mins = new Stack<T>(item);
	}else{
		stack->push(item);
		T min = mins->peek();
		if(item < min){
			mins->push(item);
		}else{
			mins->push(min);
		}
	}
}




template <class T> int StackMin<T>::size(){
	return stack->size();
}

template <class T> void StackMin<T>::print(){
	stack->print();
}

int main(){
	StackMin<int> * stack = new StackMin<int>(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);
	
	stack->print();
	
	assert(stack->min()==1);
	stack->pop();
	assert(stack->min()==1);
	stack->pop();
	assert(stack->min()==1);
	stack->pop();
	assert(stack->min()==1);
	stack->pop();
	assert(stack->min()==1);
	stack->pop();
	assert(stack->isEmpty());
	stack->push(4);
	stack->push(3);
	stack->push(2);
	stack->push(1);
	assert(stack->min()==1);
	stack->pop();
	assert(stack->min()==2);
	stack->pop();
	assert(stack->min()==3);
	stack->pop();
	assert(stack->min()==4);
	stack->pop();
	assert(stack->isEmpty());
	return 0;
}
