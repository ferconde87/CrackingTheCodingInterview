#include <iostream>
#include <algorithm>

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

int logicalShift(int x, int n){
	int res = (x >> n) & ~(1 << 31);
	return res;
}

int updateBit(int x, int i, bool value){
	int y = value ? 1 : 0;
	int mask = ~(1 << i);
	return (x & mask) | (y << i);
}

int updateBit2(int x, int i, bool value){
	return value ? setBit(x, i) : clearBit(x, i);
}

int updateBit3(int x, int i, bool value){
	int res = x & ~(1 << i);
	return value ? res | (1 << i) : res;
}


int main(){
	
	printBits(1);
	printBits(1 << 31);
	printBits(~(1 << 31));
	int x = -75;//10..0110101
	cout << x << " in bits is = ";printBits(x);
	int a = repeatedArithmeticShift(x, 1);
	cout << x << " shifted in aritmeticShift = " << a << endl;
	cout << x << " shifted in bits in aritmeticShift = "; printBits(a);
	int b = logicalShift(x, 1);
	cout << x << " shifted in logicalShift = " << b << endl;
	cout << x << " shifted in bits in logicalShift = "; printBits(b);
	cout << ".............................." << endl;
	printBits(x);
	printBits(a);
	printBits(b);
	cout << ".............................." << endl;
	cout << x; cout << "\t";printBits(x);//-75
	int y = clearBitsMSBthroughtI(x, 6);
	cout << y; cout << "\t";printBits(y);//53
	y = clearBitsIThrought0(y, 3);
	cout << y; cout << "\t";printBits(y);//48
	
	printBits(1 << 0);
	
	cout << updateBit(y, 0, 1) << endl;
	cout << updateBit2(y, 0, 1) << endl;
	cout << updateBit3(y, 0, 1) << endl;
	cout << updateBit(y, 3, 1) << endl;
	cout << updateBit2(y, 3, 1) << endl;
	cout << updateBit3(y, 3, 1) << endl;
	cout << updateBit(y, 4, 0) << endl;
	cout << updateBit2(y, 4, 0) << endl;
	cout << updateBit3(y, 4, 0) << endl;
	
	return 0;
}
