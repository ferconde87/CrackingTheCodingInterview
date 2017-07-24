/* Binary to String: Given a real number between O and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:' */

#include <iostream>
#include <string>
#include <math.h>	
#include <algorithm>

using namespace std;

string to_binary(int value){
	string s;
	while(value > 0){
		int rem = value % 2;
		value = value / 2;
		s.push_back('0' + rem);
	}
	reverse(s.begin(), s.end());
	return s;	
}


string printBinary(double num){
	if(num >= 1 || num <= 0){
		return "ERROR";
	}
	string s;
	s.push_back('.');
	while(num > 0){
		if(s.size() >= 32) { return "ERROR"; }
		
		double r = num * 2;
		if(r >= 1){
			s.push_back('1');
			num = r - 1;
		}else{
			s.push_back('0');
			num = r;
		}
	}
	
	return s;
}

string printBinary2(double num){
	if(num >= 1 || num <= 0){
		return "ERROR";
	}
	string s;
	s.push_back('.');
	double frac = 0.5;
	while(num > 0){
		if(s.size() >= 32) { return "ERROR"; }
		if(num >= frac){
			s.push_back('1');
			num -= frac;
		}else{
			s.push_back('0');
		}
		frac /= 2;
	}
	return s;
}

//convert int to string and print it
string toBinary(int value){
	string s;
	while(value > 0){
		int rem = value % 2;
		value = value / 2;
		s.push_back('0' + rem);
	}
	
	for(int i = s.size()-1; i >= 0; i--){
		cout << s[i];
	}
	
	cout << endl;
	return s;
}


int main(){
	
	//double pi = 3.141592653589793;
	// binaryToString(pi);
	
	toBinary(13);
	toBinary(127);
	toBinary(2);

	cout << printBinary(0.5) << endl;
	cout << printBinary2(0.5) << endl;
	cout << printBinary(0.25) << endl;
	cout << printBinary2(0.25) << endl;
	cout << printBinary(0.625) << endl;
	cout << printBinary2(0.625) << endl;
	cout << printBinary(0.8) << endl;
	cout << printBinary2(0.8) << endl;
	
	return 0;
}