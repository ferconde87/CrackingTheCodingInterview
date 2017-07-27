#include <iostream>
#include "BitManipulation.h"
#include <string>
#include <cmath>

/* Next Number: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation. */

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



// Versión mejorada: sin convertir el número a string 
int nextNumber2(int x){
	int i = 0;
	for(; i < 32; i++){
		if((x & (1 << i)) != 0){//hay un 1 en la posición i
			x &= ~(1 << i);//set 0 at pos i
			break;
		}
	}
	i++;
	for(; i < 32; i++){
		if((x & (1 << i)) == 0){//hay un 0 at pos i
			x |= (1 << i);
			break;
		}
	}
	return x;
}

int prevNumber2(int x){
	int i = 0;
	for(; i < 32; i++){
		if((x & (1 << i)) == 0){//hay un 0 en la posición i
			x |= (1 << i);//set 1 at pos i
			break;
		}
	}
	i++;
	for(; i < 32; i++){
		if((x & (1 << i)) != 0){//hay un 1 at pos i
			x &= ~(1 << i);//set 0
			break;
		}
	}
	return x;
}

//versión con define
#define bitIs0(x, i) (x & (1 << i)) == 0
#define bitIs1(x, i) (x & (1 << i)) != 0
#define set1(x, i) x |= (1 << i)
#define set0(x, i) x &= ~(1 << i)

int nextNumber3(int x){
	int i = 0;
	for(; i < 32; i++){
		if(bitIs1(x,i)){
			set0(x,i);
			break;
		}
	}
	i++;
	for(; i < 32; i++){
		if(bitIs0(x,i)){
			set1(x,i);
			break;
		}
	}
	return x;	
}

int prevNumber3(int x){
	int i = 0;
	for(; i < 32; i++){
		if(bitIs0(x,i)){
			set1(x,i);
			break;
		}
	}
	i++;
	for(; i < 32; i++){
		if(bitIs1(x,i)){
			set0(x,i);
			break;
		}
	}
	return x;
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

	cout << "2nd version" << endl;
	cout << 3275 << endl; 
	cout << nextNumber2(3725) << endl;
	cout << prevNumber2(3725) << endl;
	
	cout << "3rd version" << endl;
	cout << 3275 << endl; 
	cout << nextNumber3(3725) << endl;
	cout << prevNumber3(3725) << endl;
	
	//falto contemplar el caso los números negativos
	//si s tiene 1er índice / s[0] == '1' el número es negativo
		//el next de los positivos es prev y
		//el prev es el next
		
	//ademas si todos los números son 0... ie, s es "0...0"
	//el next que tiene la misma cantidad de 0 y 1 no se puede calcular
	//en 32bits no hay otro número que tenga 32 0's y 0 números 1
	//lo mismo para todos 1s "1..1" (el número -1)

	return 0;
}