#include <iostream>

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
};



int main(){
	
	Node * head = new Node(1);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(5);
	
	head->print();
	head->del(4);
	head->print();

	cout << endl;
	Node * head2 = new Node(1);
	head2->appendToTail(3);
	head2->appendToTail(5);
	head2->appendToTail(7);
	head2->appendToTail(9);
	head2->appendToTail(2);
	head2->appendToTail(4);
	head2->appendToTail(6);
	head2->appendToTail(8);
	head2->appendToTail(10);
	
	head2->print();
	head2->theRunnerTechnique(head2);
	
	cout << endl;
	Node * head3 = new Node(1);
	head3->appendToTail(3);
	head3->appendToTail(5);
	head3->appendToTail(7);
	head3->appendToTail(2);
	head3->appendToTail(4);
	head3->appendToTail(6);
	
	head3->print();
	head3->theRunnerTechnique(head3);	
	return 0;
}
