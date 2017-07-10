/* Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.*/

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
		//borrar algún elemento después del primer y antes del último
		//(no necesariamente el del medio)
		//imaginando que tenemos la referencia al node 
		//(acá comparamos con node->data == d ... pero si tuvieramos la refe
		//seroa buscar por node == d (lo hago así xq es + fácil de testear))
		void deleteMiddleNode(int d){
			if(this == NULL) return;
			Node * node = this;
			while(node->next != NULL){
				if(node->next->data == d)
					break;
				node = node->next;
			}
			Node * temp = node->next;
			node->next = temp->next;
			temp = NULL;
			
		}
};



int main(){
	
	Node * head = new Node(1);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(5);
	
	head->deleteMiddleNode(3);
	head->print();
	head->deleteMiddleNode(4);
	head->print();
	


	return 0;
}
