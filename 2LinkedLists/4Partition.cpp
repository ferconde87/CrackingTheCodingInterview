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
		
		
		void partition2(int pivot){
			if(this == NULL) return;
			Node * node = this;
			Node * first;
			while(node!=NULL){
				if(node->data < pivot){
					cout << node->data << " ";
				}
				node = node->next;
			}
			node = this;
			while(node!=NULL){
				if(pivot <= node->data){
					cout << node->data << " ";
				}
			}
		}
	
		
		
		Node * partition(int pivot){
			if (this == NULL) return this;
			Node * leftStart = NULL;
			Node * leftEnd = NULL;
			Node * rightStart = NULL;
			Node * rightEnd = NULL;
			Node * node = this;
			while(node != NULL){
				Node * next = node->next;
				node->next = NULL;
				if(node->data < pivot){
					if(leftStart == NULL){
						leftStart = node;
						leftEnd = leftStart;
					}else{
						leftEnd->next = node;
						leftEnd = node;
					}
				}else{
					if(rightStart == NULL){
						rightStart = node;
						rightEnd = rightStart;
					}else{
						rightEnd->next = node;
						rightEnd = node;
					}
				}
				node = next;
			}
			
			if(leftStart == NULL)
				 return rightStart;
			leftEnd->next = rightStart;
			return leftStart;
		}
};



int main(){
	
	Node * head = new Node(5);
	head->appendToTail(4);
	head->appendToTail(3);
	head->appendToTail(2);
	head->appendToTail(1);
	
	head->print();
	Node * solution = head->partition(3);
	solution->print();

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
	Node * solution2 = head2->partition(5);
	head2->print();
	
	return 0;
}
