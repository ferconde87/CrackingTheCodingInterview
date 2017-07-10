#include <iostream>

#include "LinkList.h"

using namespace std;

Node * intersection(Node * a, Node * b){
	if(a == NULL or b == NULL) return NULL;
	Node * nodeA = a;
	Node * nodeB = b;
	Node * c = NULL;
	Node * cNext = NULL;
	int i = 0;
	while(nodeA != NULL){
		nodeB = b;
		while(nodeB != NULL){
			if(nodeA == nodeB){
				if(c == NULL){
					c = nodeA;
					cNext = c;
				}else{
					cNext->next = nodeA;
					cNext = nodeA;
				}
			}
			nodeB = nodeB->next;
		}
		nodeA = nodeA->next;
	}
	return c;
}

int main(){

	Node * a = new Node(11);
	Node * a2 = new Node(12);
	Node * a3 = new Node(13);
	Node * a4 = new Node(14);
	Node * a5 = new Node(15);
	
	Node * b = new Node(21);
	Node * b2 = new Node(22);
	Node * b3 = new Node(23);
	Node * b4 = new Node(24);
	Node * b5 = new Node(25);
	
	a->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	
	b->next = a2;
	a2->next = b2;
	b2->next = a3;
	a3->next = b3;
	
	a->print();
	b->print();
	
	Node * c = intersection(a, b);
	c->print();
	
	return 0;
}
