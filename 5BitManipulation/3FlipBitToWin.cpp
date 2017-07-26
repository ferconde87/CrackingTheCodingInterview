#include <iostream>
#include <cassert>
using namespace std;

/* Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of ls you could create. */

/* EXAMPLE Input: 1775 (or: 11011101111)  
		   Output: 8 */

		   
int getBit(int x, int i){
	return (x & (1 << i)) != 0;
}
		   
string convertToBinaryString(int x){
	string s;
	for(int i = 31; i >= 0; i--){
		s.push_back('0'+getBit(x, i));
	}
	return s;
}

int flipBitToWin(string s){
	int left = 0;
	int right = 0;
	bool fliped = false;
	int res = 0;
	for(char c : s){
		if(c == '0'){
			if(!fliped){
				fliped = true;
			}else{
				if(right != 0){
					res = max(left + right + 1, res);
					left = right;
					right = 0;
				}else{//implica que hay 2 o + ceros seguidos
					left = 0;
					fliped = true;
				}
			}
		}else{
			if(fliped){
				right++;
			}else{
				left++;
			}
		}
	}
	
	if(fliped)
		return max(res, left + right + 1);
	else
		return max(res, left + right);
}
		   
int flipBitToWin(int x){
	string s = convertToBinaryString(x);	
	return flipBitToWin(s);
}

//2da versión mejorada mix 1er versión + CTCI
int flipBit(int x){
	if(~x == 0) return 32;
	int curLen = 0;
	int prevLen = 0;
	int maxLen = 0;
	bool twoZeros = false;
	for(int i = 0; i < 31; i++){
		if(getBit(x, i) == 1){
			twoZeros = false;
			curLen++;
		}else{
			prevLen = twoZeros ? 0 : curLen;
			curLen = 0;
			twoZeros = true;
		}
		maxLen = max(prevLen + curLen + 1, maxLen);
	}
	return maxLen;
}
		   
int main(){
	
	int x = 1775;
	cout << convertToBinaryString(x) << endl;
	cout << flipBitToWin(x) << endl;
	cout << flipBit(x) << endl;
	cout << "----------------------" << endl;
	string s;
	s = "1111";
	assert(flipBitToWin(s)==4);
	s = "111011100";
	assert(flipBitToWin(s)==7);
	s = "1110111001111111";
	assert(flipBitToWin(s)==8);
	s = "11101110011111110";
	assert(flipBitToWin(s)==8);
	s = "111011100111111101";
	assert(flipBitToWin(s)==9);

	cout << convertToBinaryString(-1) << endl;
	
	return 0;
}