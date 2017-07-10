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
		//imprime desde el elemento k hasta el último de la lista
		void returnKthToLastElem(int k){
			if(k == 0 or this == NULL) return;
			Node * node = this;
			int i = 1;
			while(node->next != NULL && i < k){
				node = node->next;
				i++;
			}
			if(i==k){
				while(node != NULL){
					cout << node->data << " ";
					node = node->next;
				}
			}
			cout << endl;
		}
		
		//imprimir el Kth elemento empezando a contar desde el último
		void returnKthToLast(int k){
			if (this == NULL ) return;
			int i = 1;
			Node * node = this;
			while(node->next != NULL){
				node = node->next;
				i++;
			}
			int index = i - k;
			if(index < 0) return;
			node = this;
			for(int i = 0; i < index; i++){
				node = node->next;
			}
			cout << node->data << endl;
		}
};



int main(){
	
	Node * head = new Node(1);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(5);
	
	head->print();
	head->returnKthToLastElem(3);
	head->returnKthToLastElem(1);
	head->returnKthToLastElem(5);
	
	head->returnKthToLast(3);
	head->returnKthToLast(1);
	head->returnKthToLast(5);

	return 0;
}
