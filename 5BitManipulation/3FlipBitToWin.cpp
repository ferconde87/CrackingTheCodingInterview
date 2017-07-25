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
	int cur = 0;
	int res = 0;
	for(char c : s){
		if(c == '0'){
			if(!fliped){
				fliped = true;
			}else{
				if(right != 0){
					cur = left + right + 1;
					res = max(cur, res);
					left = right;
					right = 0;
				}else{
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
		   
int main(){
	
	int x = 1775;
	cout << convertToBinaryString(x) << endl;
	cout << flipBitToWin(x) << endl;
	
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

	return 0;
}