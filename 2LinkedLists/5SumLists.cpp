#include <iostream>
#include "LinkList.h"

using namespace std;
 
/* 2.5
SumLists: You have two number represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list. */

int i = 0;

//soporta distintos tamaños de a y b
Node * sumListsRec(Node * a, Node * b, int offset, Node * start, Node * end){
	if(a==NULL && b==NULL){
		if(offset) end->next = new Node(offset);//va a ser 1 como mucho pasa 1(offset)+9(a)+9(b) = 19 con 1 de offset
		return start;
	}
	int numA = (a==NULL) ? 0 : a->data;
	int numB = (b==NULL) ? 0 : b->data;
	int sum = offset + numA + numB;
	if(start == NULL){
		start = new Node(sum%10);
		end = start;
	}else{
		end->next = new Node((sum)%10);
		end = end->next;
	}
	offset = (sum > 9) ? 1 : 0;
	if(a != NULL) a = a->next;
	if(b != NULL) b = b->next;
	return sumListsRec(a, b, offset, start, end);
}

Node * sumListsRec(Node * a, Node * b){
	int offset = 0;
	Node * resultEnd = NULL;
	Node * resultStart = NULL;
	return sumListsRec(a, b, 0, resultStart, resultEnd);
}


//requiere a->size() == b->size()
Node * Node::sumLists(Node * a, Node * b){
	Node * numStart = NULL;
	Node * numEnd = NULL;
	int offset = 0;
	while(a != NULL && b != NULL){
		int sum = a->data + b->data;
		if(numStart == NULL){
			numStart = new Node(sum%10);
			numEnd = numStart;
		}else{
			numEnd->next = new Node((sum+offset)%10);
			numEnd = numEnd->next;
		}
		offset = ((sum+offset) > 9) ? 1 : 0;
		a = a->next;
		b = b->next; 
	}
	
	return numStart;
}


Node * addZeros(Node * a, int total){
	if(total <= 0) return a;
	Node * zero = new Node(0);
	zero->next = a;
	total--;
	addZeros(zero, total);
}

//suma lista como en la realidad
Node * sumListsOK(Node * a, Node * b){
	Node * aReverse = a->reverse();
	Node * bReverse = b->reverse();
	Node * sum = sumListsRec(aReverse, bReverse);
	return sum->reverse();
}

//al revés del anterior.. como se lee en realidad ;)
//~ Node * sumLists2(Node * a, Node * b){
	//~ Node * numStart = NULL;
	//~ Node * numEnd = NULL;
	//~ int sizeA = a->size();
	//~ int sizeB = b->size();
	//~ if(sizeA < sizeB){
		//~ addZeros(a, sizeB-sizeA);
	//~ }else if(sizeB < sizeA){
		//~ addZeros(b, sizeA-sizeB);
	//~ }
//~ 
	//~ int offset = 0;
	//~ while(a != NULL && b != NULL){
		//~ int sum = a->data + b->data;
		//~ if(numStart == NULL){
			//~ numStart = new Node(sum%10);
			//~ numEnd = numStart;
		//~ }else{
			//~ numEnd->next = new Node((sum+offset)%10);
			//~ numEnd = numEnd->next;
		//~ }
		//~ offset = (sum+offset > 9) ? 1 : 0;
		//~ a = a->next;
		//~ b = b->next; 
	//~ }
	//~ 
	//~ return numStart;
//~ }




int main(){
	
	//1er ejemplo a = 7->1->6->1	b = 5->9->2		result = 2->1->9->1
	//el primer node es "la unidad" 
	Node * a = new Node(7);
	a->appendToTail(1);
	a->appendToTail(6);
	a->appendToTail(1);
	Node * b = new Node(5);
	b->appendToTail(9);
	b->appendToTail(2);
	
	Node * result = sumListsRec(a, b);
	result->print();
	
	Node * a2 = new Node(9);
	a2->appendToTail(9);
	a2->appendToTail(9);
	Node * b2 = new Node(1);
	b2->appendToTail(0);
	b2->appendToTail(0);
	
	Node * result2 = sumListsRec(a2, b2);
	result2->print();
	
	
	cout << "----------- sumListOK -------------- " << endl;
	//2do ejemplo al reves del anterior.. como se lee en realidad	a = 7->1->6		b = 5->9->2		result = 1->3->0->8 
	Node * c = new Node(7);
	c->appendToTail(1);
	c->appendToTail(6);
	Node * d = new Node(5);
	d->appendToTail(9);
	d->appendToTail(2);	
	cout << "  "; c->print();
	cout << "+ "; d->print();
	cout << "-------" << endl;
	Node * result3 = sumListsOK(c,d);
	result3->print();
	
	//adding 0
	//~ Node * testZeros = addZeros(NULL, 4);
	//~ testZeros->print();
	//~ testZeros = addZeros(a, 1);
	//~ testZeros->print();
	
	cout << "----------- REVERSE -------------- " << endl;
	cout << "original = ";a->print();
	cout << "reserve  = ";Node * aRev = a->reverse();
	aRev->print();
	
	return 0;
}

