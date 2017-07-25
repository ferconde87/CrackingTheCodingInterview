#include <iostream>
#include "BitManipulation.h"
#include <string>
#include <cmath>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int findFirstOccurrence(char elem, string s){
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i]==elem) return i;
	}
	return -1;
}

int findNextOccurrernce(char elem, int from, string s){
	for(int i = from; i >= 0; i--){
		if(s[i] == elem) return i;
	}
	return -1;
}

string convertToBinaryString(int x){
	string s;
	for(int i = 31; i >= 0; i--){
		s.push_back('0' + getBit(x, i));
	}
	return s;
}

void setValue(char newValue, int index, string s){
	s[index] = newValue; 
}

string nextNumber(string s){
	int i = findFirstOccurrence('1', s);
	int j = findNextOccurrernce('0', i-1, s);
	s[i] = '0';
	s[j] = '1';
	return s;	
}

string prevNumber(string s){
	int i = findFirstOccurrence('0', s);
	int j = findNextOccurrernce('1', i-1, s);
	s[i] = '1';
	s[j] = '0';
	return s; 
}

string prevNumber(int x){
	string s = convertToBinaryString(x);
	return prevNumber(s);
}

string nextNumber(int x){
	string s = convertToBinaryString(x);
	return nextNumber(s);
}

int binaryStringToInt(string s){
	long long res = 0;
	int j = 0;
	for(int i = s.size()-1; i >= 0; i--, j++){
		if(s[i]=='1'){
			res += pow(2, j);
		}
	}
	return res;
}

int main(){
	
	string s = "111010001101";
	cout << s << endl;
	cout << binaryStringToInt(s) << endl;
	
	string next = nextNumber(s); 
	cout << next << endl;
	cout << binaryStringToInt(next) << endl;
	
	string prev = prevNumber(s);
	cout << prev << endl;
	cout << binaryStringToInt(prev) << endl;

	//falto contemplar el caso los números negativos
	//si s tiene 1er índice / s[0] == '1' el número es negativo
		//el next de los positivos es prev y
		//el prev es el next
		
	//ademas si todos los números son 0... ie, s es "0...0"
	//el next que tiene la misma cantidad de 0 y 1 no se puede calcular
	//en 32bits no hay otro número que tenga 32 0's y 0 números 1
	//lo mismo para "1..1" (el número -1)

	return 0;
}
