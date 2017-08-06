#include <iostream>
#include "BitManipulation.h"

using namespace std;

#define cbit(x) cout << #x << "\t = " << convertToBinaryString(x) << endl;

int pairwiseSwap(int n){
	int ans = n;
	for(int i = 0; i < 32; i+=2){
		int mask1 = (1 << i);
		int mask = mask1 + (1 << (i+1));
		int m = (n & mask);
		if(m == 0 || m == mask) continue;
		if((n & mask1) != 0) 
			ans += mask1;
		else
			ans -= mask1;
	}
	return ans;
}

int pairwiseSwap2(int n){
	int ans = 0;
	int evenMask = 0;
	int oddMask = 0;
	for(int i = 0; i < 32; i+=2){
		oddMask += (1 << i);
		evenMask += (1 << (i+1));
	}
	ans = ((n & evenMask) >> 1);// >> arithmetic shift
	ans &= ~(1 << 31);//correction cuz arithmetic shift
	ans += ((n & oddMask) << 1);
	return ans;

}

int pairwiseSwap3(int n){
	int evenMask = 0xaaaaaaaa;
	int oddMask = 0x55555555;
	int ans = ((n & evenMask) >> 1);
	ans &= ~(1 << 31);
	ans += ((n & oddMask) << 1);
	return ans;
}

int pairwiseSwap4(int n){
	return (n & 0xaaaaaaaa) >> 1 & ~(1 << 31) | (n & 0x55555555) << 1;
}

int main(){
	
	cout << pairwiseSwap(5) << endl;
	cout << pairwiseSwap2(5) << endl;
	cout << pairwiseSwap3(5) << endl;
	cout << pairwiseSwap4(5) << endl;
	cout << pairwiseSwap(-5) << endl;
	cout << pairwiseSwap2(-5) << endl;
	cout << pairwiseSwap3(-5) << endl;
	cout << pairwiseSwap4(-5) << endl;
	
	return 0;
}
