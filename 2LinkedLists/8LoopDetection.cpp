#include <iostream>

#include "LinkList.h"

/* Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
*/


using namespace std;

Node * loopDetection(Node * head){
	if(head == NULL) return NULL;
	
	Node * start = head;
	Node * startEnd = head;
	Node * node = head->next;
	int k = 1;
	while(node!= NULL){
		int i = 0;
		startEnd = start;
		while(startEnd != NULL && i < k){
			if(startEnd == node){
				return node;
			}else{
				startEnd = startEnd->next;
			}
			i++;
		}
		k++;
		node = node->next;
	} 
}

int main(){
	
	Node * a = new Node(1);
	Node * b = new Node(2);
	Node * c = new Node(3);
	Node * d = new Node(4);
	Node * e = new Node(5);
	
	
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = c;
	
	Node * beginLoopNode = loopDetection(a);
	cout << beginLoopNode->data << endl;

	return 0;
}
