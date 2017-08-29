#include <iostream>

using namespace std;


#define cn(x) cout << #x << " = " << x << endl;

void pointers(){
	int * p = new int;
	*p = 7;
	int * q = p;
	*p = 8;
	cn(*q);
	*q = 9;
	cn(*p); 
}

void references(){
	int a = 5;
	int & b = a;
	b = 7;
	cn(a);
	a = 8;
	cn(b);
}

void pointerArithmetic(){
	int * p = new int[2];
	p[0] = 0;
	p[1] = 1;
	cn(*p);
	p++;
	cn(*p);
}

int main(){
	pointers();
	references();
	pointerArithmetic();
}
