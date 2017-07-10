#include <iostream>
#include <exception>

//#include "../2LinkedLists/LinkList.h"

using namespace std;

class EmptyException : public exception
{
  virtual const char* what() const throw()
  {
    return "Invalidate operation! The queue is Empty";
  }
} emptyException;


template <class T>
class Node{
	public:
		Node * next;
		T data;
		int order;
		Node(T data, int order){
			this->data = data;
			next = NULL;
			this->order = order;
		}
		void appendToTail(T data);
		
};

template <class T>
void Node<T>::appendToTail(T data){
	Node<T> * node = this;
	while(node!=NULL){
		node = node->next;
	}
	node = new Node<T>(data);
}

enum pet {cat, dog};


class LinkedListCatDog{
	friend class Node<pet>;
	public:
		Node<pet> * firstCat;
		Node<pet> * lastCat;
		Node<pet> * firstDog;
		Node<pet> * lastDog;
		Node<pet> * firstAny;
		Node<pet> * lastAny;
		int order;
		LinkedListCatDog(){
		 firstCat = NULL;
		 lastCat = NULL;
		 firstDog = NULL;
		 lastDog = NULL;
		 order = 0;
		}
		void enqueue(pet p);
		void dequeueAny(Node<pet> * head);
		void dequeueAny();
		void dequeueDog();
		void dequeueCat();
		void dequeue(Node<pet> * head);
		void insert(Node<pet> * first, Node<pet> * last, pet p, int order);
};


void LinkedListCatDog::insert(Node<pet> * first, Node<pet> * last, pet p, int order){
	if(first == NULL){
		first = new Node<pet>(p, order);
		last = first;
	}else{
		Node<pet> * old = last;
		last = new Node<pet>(p, order);
		old->next = last;
	}
}

void LinkedListCatDog::enqueue(pet p){
	order++;
	if(p == cat)
		insert(firstCat, lastCat, p, order);
	else
		insert(firstDog, lastDog, p, order);
}

void LinkedListCatDog::dequeueAny(){
	if(firstAny == NULL){
		throw emptyException;
	}
	if(firstCat->order < firstDog->order)
		dequeueCat();
	else
		dequeueDog();
}

void LinkedListCatDog::dequeue(Node<pet> * first){
	if(first == NULL){
		throw emptyException;
	}
	Node<pet> * oldFirst = first;
	first = oldFirst->next;
	oldFirst = NULL;
}

void LinkedListCatDog::dequeueCat(){
	dequeue(firstCat);
}

void LinkedListCatDog::dequeueDog(){
	dequeue(firstDog);
}

int main(){
	
	return 0;
}

