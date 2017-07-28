#include <iostream>

using namespace std;

int repeatedArithmeticShift(int x, int count){
	for(int i = 0; i < count; i++){
		x >>= 1; // Arithmetic shift by 1
	}
	return x;
}

bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

int setBit(int num, int i){
	return num | (1 << i);
}

int clearBit(int num, int i){
	return num & ~(1 << i);
}

int clearBitsMSBthroughtI(int num, int i){
	int mask = (1 << i) - 1;
	return num & mask;
}

int clearBitsIThrought0(int num, int i){
	int mask = -1 << (i + 1);
	return num &  mask;
}

//32-bits
void printBits(int num){
	for(int i = 31; i >= 0; i--){
		cout << getBit(num, i);
	}
	cout << endl;	
}

string convertToBinaryString(int x){
	string s;
	for(int i = 31; i >= 0; i--){
		s.push_back('0' + getBit(x, i));
	}
	return s;
}

int getAmountOfOnes(int x){
	int count = 0;
	for(; x != 0; x = x & (x-1))
		count++;
	return count;
}