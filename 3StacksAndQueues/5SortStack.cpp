#include "Stack.h"

using namespace std;

void sort(Stack<int> * stack){
	if (stack->isEmpty()) return;
	Stack<int> * temp = new Stack<int>();
	int n = stack->size();
	for(int i = 0; i < n-1; i++){
		int max = stack->peek();
		for(int j = i; j < n; j++){
			int num = stack->peek();
			if(num > max)
				max = num;
			temp->push(num);
			stack->pop();
		}
		stack->push(max);
		for(int j = i; j < n; j++){
			int num = temp->peek();
			if(num != max){
				stack->push(num);
			}
			temp->pop();
		} 
	}
}


int main(){
	
	Stack<int> * stack = new Stack<int>();
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(1);
	stack->push(5);
	
	stack->print();
	
	sort(stack);
	
	stack->print();
	
	return 0;
}
