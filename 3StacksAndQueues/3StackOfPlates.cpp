#include "Stack.h"
#include <vector>

using namespace std;

template <class T>
class SetOfStacks : Stack<T>{
	private:
		vector<Stack<T> * > stacks;
		T threshold;
		int lenght;
	public:
		SetOfStacks(T threshold){
			this->threshold = threshold;
			lenght = 0;
		}
		bool isEmpty();
		T peek();
		void pop();
		void push(T item);
		int size();
		void print();
		T peekAt(int index);
		void popAt(int index);
};

template <class T> bool SetOfStacks<T>::isEmpty(){
	return stacks.size()==0;
}

template <class T> T SetOfStacks<T>::peek(){
	if(this->isEmpty()){
		throw emptyException;
	}
	T top = stacks.back()->peek();
	return top;
}

template <class T> void SetOfStacks<T>::pop(){
	if(this->isEmpty()){
		throw emptyException;
	}
	Stack<T> * back = stacks.back();
	back->pop();
	if(back->size() == 0){
		stacks.pop_back();
	}
}

template <class T> void SetOfStacks<T>::popAt(int index){
	stacks[index]->pop();
}

template <class T> T SetOfStacks<T>::peekAt(int index){
	return stacks[index]->peek();
}

template <class T> void SetOfStacks<T>::push(T item){
	if(isEmpty() or stacks.back()->size()==threshold){
		Stack<T> * newStack = new Stack<T>(item);
		stacks.push_back(newStack); 
	}else{
		stacks.back()->push(item);
	}
	lenght++;
}


template <class T> int SetOfStacks<T>::size(){
	return lenght;
}

template <class T> void SetOfStacks<T>::print(){
	for(int i = 0; i < stacks.size(); i++){
		stacks[i]->print();
	}
}


int main(){
	
	SetOfStacks<int> * stacks = new SetOfStacks<int>(4);
	stacks->push(1);
	stacks->push(2);
	stacks->push(3);
	stacks->push(4);
	assert(stacks->size() == 4);
	stacks->push(5);
	stacks->push(6);
	stacks->push(7);
	stacks->push(8);
	assert(stacks->size() == 8);
	stacks->print();
	stacks->pop();
	stacks->pop();
	stacks->pop();
	assert(stacks->peek() == 5);
	stacks->pop();
	stacks->print();
	stacks->push(5);
	stacks->push(6);
	stacks->push(7);
	stacks->push(8);
	stacks->push(9);
	assert(stacks->peek() == 9);
	stacks->popAt(0);
	stacks->print();
	assert(stacks->peekAt(0) == 3);
	stacks->print();
	
	return 0;	
}
