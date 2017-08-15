#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <set>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/*Recursive Multiply: Write a recursive function to multiply two positive integers without using the
*operator.You can use addition, subtraction, and bit shifting, but you should minimize the number
of those operations.*/


int recursiveMultiplyAux(unsigned int x, unsigned int y){
	if(y == 1) return x;
	return x + recursiveMultiplyAux(x, y-1);
}

int recursiveMultiply(unsigned int a, unsigned int b){
	if(a == 1) return b;
	if(b == 1) return a;
	unsigned int max, min;
	if(a < b){
		min = a;
		max = b;
	}else{
		max = a;
		min = b;
	}
	return recursiveMultiplyAux(max, min);
}

//dividir por 2 ó shiftear (b >> 1)
//preguntar b%2==1 ó ver si el bit menos significativo es 1... ie, (b & 0x1 != 0)

//faster
int recursiveMultiplyFaster(unsigned int a, unsigned int b){
	if(b == 1) return a;
	int ans = recursiveMultiplyFast(a, b/2);
	ans += ans;
	if(b%2==1) ans += a;
	return ans; 
}

int main(){	
	cout << recursiveMultiply(7, 5) << endl;
	cout << recursiveMultiply(5, 7) << endl;
	cout << recursiveMultiply(3, 3) << endl;
	cout << recursiveMultiply(2, 512) << endl;
	cout << recursiveMultiplyFast(7, 5) << endl;
	cout << recursiveMultiplyFast(5, 7) << endl;
	cout << recursiveMultiplyFast(3, 3) << endl;
	cout << recursiveMultiplyFast(2, 512) << endl;
	
	return 0;
}
