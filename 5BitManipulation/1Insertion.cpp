#include <iostream>

#include "BitManipulation.h"


/*Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and
j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You
can assume that the bits j through i have enough space to fit all of M. That is, if
M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for
example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2
*/ 

/*
 * Input:
N = 10000000000, M = 10011, 
Output: N = 10001001100, i = 2, j = 6
*/

using namespace std;

int intersection(int n, int m, int i, int j){
	int maskUp = ~((1 << j+1) -1);
	int maskDown = (1 << i) - 1;
	int maskM = (m << i);
	int mask = maskUp | maskDown;
	return (n & mask) | maskM;
}

int intersection2(int n, int m, int i, int j){
	return n & (~((1 << j+1) - 1) | ((1 << i) - 1)) | (m << i);
}

int main(){
	
	int n = 2048;
	int m = 19;
	int j = 6;
	int i = 2;
	int res = intersection(n, m, i, j);
	cout << "intersection(" << n << ", " << m << ", " << i <<  ", " << j << ") = " << res << endl;
	cout << "n = "; printBits(n);
	cout << "m = "; printBits(m);
	cout << res << endl;
	printBits(n);
	printBits(m);
	printBits(res);
	printBits(intersection2(n, m, i, j));
	
	return 0;
}
