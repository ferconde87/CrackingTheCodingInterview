#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/*Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order
of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following
constraints:
(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto another tower.
(3) A disk cannot be placed on top of a smaller disk.
Write a program to move the disks from the first tower to the last using stacks.*/

class Tower{
	public:
		stack<int> disks;
		int index;
		Tower(int i ){
			index = i;
		}
		void add(int d){
			if(!disks.empty() && disks.top() <= d){
				cout << "Error placing disk " << d << endl;
			}else{
				disks.push(d);
			}
		}
		
		void moveTopTo(Tower * t){
			int top = disks.top();
			
			//print(t->index, top);
			
			disks.pop();
			t->add(top);
		}
		void moveDisks(int n, Tower * destination, Tower * buffer){
			if(n > 0){
				moveDisks(n-1, buffer, destination);//from 'this' to buffer using destination as a buffer
				moveTopTo(destination);
				printTowers(destination, buffer);//SALIDA
				buffer->moveDisks(n-1, destination, this);//from buffer to destination using 'this' as a buffer
			}
		}
		
		void print(int i, int value){
			if(i==0) cout << value << endl;
			if(i==1) cout << "\t" << value << endl;
			if(i==2) cout << "\t\t" << value << endl;
		}
		
		
		void printTowers(Tower * destination, Tower * buffer){
			Tower * ta = this->getTower(0, destination, buffer);
			Tower * tb = this->getTower(1, destination, buffer);
			Tower * tc = this->getTower(2, destination, buffer);
			queue<int> a = copy(ta->disks);
			queue<int> b = copy(tb->disks);
			queue<int> c = copy(tc->disks);
			//~ while(!a.empty() || !b.empty() || !c.empty()){
				//~ printElement(a);cout << "\t";
				//~ printElement(b);cout << "\t\t";
				//~ printElement(c);cout << endl;
			//~ }
			//~ cout << "----------------------------------" << endl;
			int k = a.size() + b.size() + c.size();
			while(!a.empty() || !b.empty() || !c.empty()){
				if(a.size()==k) printElement(a);cout << "\t";
				if(b.size()==k) printElement(b);cout << "\t";
				if(c.size()==k) printElement(c);cout << endl;
				k--;
			}
			cout << "-----------------" << endl;
		}
		
		void printElement(queue<int> & q){
			if(!q.empty()){
				cout << q.front();
				q.pop();
			}
		}
		
		//copia los elementos de s a una queue (s queda igual)
		queue<int> copy(stack<int> & s){
			stack<int> temp;
			queue<int> ans;
			while(!s.empty()){
				int top = s.top();
				s.pop();
				temp.push(top);
				ans.push(top);
			}
			while(!temp.empty()){
				int top = temp.top();
				temp.pop();
				s.push(top);
			}
			return ans;
		}
		
		Tower * getTower(int i, Tower * that, Tower * other){
			if(this->index == i) return this;
			if(that->index == i) return that;
			return other;
		}
};


void towersOfHanoi(int n){
	vector<Tower*> towers(n);
	for(int i = 0; i < 3; i++){
		towers[i] = new Tower(i);
	}
	for(int i  = n-1; i >= 0; i--){
		towers[0]->add(i);
		cout << n-1-i << endl;
	}
	cout << "-----------------" << endl;
	towers[0]->moveDisks(n, towers[2], towers[1]);//from 0 to 2 using 1 as a buffer
}

int main(){	
	int n;
	cout << "Towers of Hanoi" << endl;
	cout << "Insert initial size: ";
	cin >> n; cout << endl;
	towersOfHanoi(n);
	return 0;
}

