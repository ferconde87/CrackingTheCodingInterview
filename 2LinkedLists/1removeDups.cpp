#include <iostream>
#include <unordered_set>

using namespace std;

class Node{
	Node * next = NULL;
	int data;
	public:
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
		
		//O(n) usando hashSet
		void removeDups(){
			if(this == NULL) return;
			Node * node = this;
			unordered_set<int> set;
			set.insert(node->data);
			while(node->next != NULL){
				Node * next = node->next;
				if(set.find(next->data)==set.end()){
					set.insert(next->data);
					node = node->next;
				}else{
					node->next = next->next;
					next = NULL;
				}
				
			}
			
		}
		
		//O(N^2) con O(1) de memoria
		void removeDups2(){
			if(this == NULL) return;
			Node * i = this;
			if(i->next == NULL) return;
			Node * j = i->next;
			while(i != NULL){
				Node * j = i->next;
				if(i->next!=NULL){
				}
				Node * prev = i;
				while(j != NULL){
					if(j->data == i->data){
						prev->next = j->next;
						j = NULL;
						j = prev->next;
					}else{
						prev = j;
						j = j->next;
					}
				}
				i = i->next;
			}
		}
};

int main(){

	//caso general
	Node * head = new Node(2);
	head->appendToTail(1);
	head->appendToTail(5);
	head->appendToTail(7);
	head->appendToTail(2);
	head->appendToTail(5);
	head->appendToTail(7);
	head->appendToTail(8);

	head->print();
	head->removeDups2();
	head->print();
	
	cout << endl;
	//solo un repetido
	Node * head2 = new Node(2);
	head2->appendToTail(2);

	head2->print();
	head2->removeDups2();
	//head2->print();
	
	cout << endl;
	//doble repetido
	Node * head3 = new Node(3);
	head3->appendToTail(3);
	head3->appendToTail(3);

	head3->print();
	head3->removeDups2();
	head3->print();
	
	cout << endl;
	//duplicado al final
	Node * head4 = new Node(1);
	head4->appendToTail(0);
	head4->appendToTail(1);

	head4->print();
	head4->removeDups2();
	head4->print();
	
	cout << "-------------------------------------------------" << endl;
	
	return 0;
}
