#include <iostream>

#include "LinkList.h"

using namespace std;

bool isPalindrome(Node * head){
	if(head == NULL) return true;
	Node * node = head->copy();
	Node * reverse = head->reverse();
	while(node != NULL && reverse != NULL){
		if(node->data != reverse->data)
			return false;
		node = node->next;
		reverse = reverse->next;
	}
	return node == NULL && reverse == NULL;
}

int main(){
	Node * head = new Node(1);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(2);
	head->appendToTail(1);

	cout << isPalindrome(head) << endl;
	
	Node * head2 = new Node(1);
	head2->appendToTail(2);
	head2->appendToTail(2);
	head2->appendToTail(1);
	head2->appendToTail(0);
	
	cout << isPalindrome(head2) << endl;
	
	return 0;
}
