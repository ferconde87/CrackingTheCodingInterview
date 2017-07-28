#include <iostream>
#include "BitManipulation.h"

using namespace std;

/* Conversion: Write a function to determine the number of bits you would need to flip to convert
integer A to integer B. */


int bitsToFlip2(int a, int b){
	int out = 0;
	for(int i = 0; i < 32; i++)
		if(((a & (1 << i)) != 0) != ((b & (1 << i)) != 0))
			out ++;
	return out;
}

int bitsToFlip(int a, int b){
	int c = a ^ b;
	int out = 0;
	for(int i = 0; i < 32; i++)
		if((c & (1 << i)) != 0) out++;
	return out;
}

//CTCI // (!) loopea infinito con números negativos por el shift aritmético
int bitSwapRequired(int a, int b){
	int count = 0;
	for(int c = a ^ b; c != 0; c = c >> 1){
		// if((c & 1) != 0)
			// count++;
		count += c & 1;
	}
	return count;
}

//CTCI best
int bitSwapRequired2(int a, int b){
	int count = 0;
	for(int c = a ^ b; c != 0; c = c & (c-1))
		count++;
	return count;
}

int main(){
	//para contar la cantidad de 1s en c
	int c = 15;
	int count = 0;
	while(c!= 0){
		c = c & (c-1);
		count++;
	}
	cout << count << endl;
	cout << getAmountOfOnes(15) << endl;
	
	cout << bitsToFlip(29, 15) << endl;
	cout << bitsToFlip((1 << 31), ((1 << 30) - 1)) << endl;
	cout << bitsToFlip2(29, 15) << endl;
	cout << bitsToFlip2((1 << 31), ((1 << 30) - 1)) << endl;
	cout << bitSwapRequired2(29, 15) << endl;
	cout << bitSwapRequired2((1 << 31), ((1 << 30) - 1)) << endl;	
	// cout << convertToBinaryString(400) << endl;
	// cout << convertToBinaryString(400 & 399) << endl;
	
	return 0;
}

