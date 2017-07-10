#include <iostream>

using namespace std;

class Node{
	public:
		Node * next = NULL;
		int data;
		Node(int d){
			data = d;
		}
		void appendToTail(int d){
			Node * end = new Node(d);	
			Node * node = this;
			while(node->next != NULL){
				node = node->next;
			}
			node->next = end;
		}
		void print(){
			if(this==NULL) return;
			Node * node = this;
			while(node != NULL){
				cout << node->data << " ";
				node = node->next;
			}
			cout << endl;
		}
		void del(int d){
			if(this==NULL) return;
			Node * node = this;
			if(node->data == d){
				node = node->next;
				return;
			}
			while(node->next != NULL){
				Node * next = node->next;
				if(node->next->data == d){
					node->next = node->next->next;
					next = NULL;
					return;
				}
				node = next;
			}
		}
		//practicar pasar de a 1 - >a 2 -> ••• ->an - >b 1 ->b 2 -> ••• ->bn
		// a 1 ->b 1 ->a 2 - >b 2 -> ••• - >an - >bn.
		void theRunnerTechnique(Node * head){
			if(head == NULL) return;
			Node * mid = head;
			Node * first = head;
			int i = 1;
			while(first->next != NULL){
				first = first->next;
				i++;
			}
			
			if(i<=1)return;
			first = head;	
			int middle = i/2;
			middle += i%2;
			for(int k = 0; k < middle; k++){
				mid = mid->next;
			}
			while(mid!=NULL){
				cout << first->data << " " << mid->data << " ";
				first = first->next;
				mid = mid->next;
			}
			if(i%2)
				cout << first->data;
			cout << endl;
		}
		
		Node * sumLists(Node * a, Node * b);
		
		int size(){
			if(this == NULL) return 0;
			return 1 + this->next->size();
		}
		
		Node * copy(){
			if(this == NULL) return NULL;
			Node * node = this;
			Node * newStart = new Node(this->data);
			Node * newEnd = newStart;
			node = node->next;
			while(node != NULL){
				Node * newNode = new Node(node->data);
				newEnd->next = newNode;
				newEnd = newNode;
				node = node->next;
			}
			return newStart;
		}
		
		Node * reverse(){
			if(this == NULL) return this;
			Node * prev = NULL;
			Node * node = this;
			Node * next = NULL;
			while(node != NULL){
				next = node->next;
				node->next = prev;
				prev = node;
				node = next;
			}
			return prev;
		}
		
};

