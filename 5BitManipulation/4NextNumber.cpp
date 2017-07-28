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


//versiones nextNumber 1, 2 y 3 NOT WORKING dan un próximo y un anterior pero no el menor próximo ni el mayor anterior...

// string prevNumber(int x){
	// string s = convertToBinaryString(x);
	// return prevNumber(s);
// }

// string nextNumber(int x){
	// string s = convertToBinaryString(x);
	// return nextNumber(s);
// }


// // 
// // Versión mejorada: sin convertir el número a string 
// int nextNumber2(int x){
	// int i = 0;
	// for(; i < 32; i++){
		// if((x & (1 << i)) != 0){//hay un 1 en la posición i
			// x &= ~(1 << i);//set 0 at pos i
			// break;
		// }
	// }
	// i++;
	// for(; i < 32; i++){
		// if((x & (1 << i)) == 0){//hay un 0 at pos i
			// x |= (1 << i);
			// break;
		// }
	// }
	// return x;
// }

// int prevNumber2(int x){
	// int i = 0;
	// for(; i < 32; i++){
		// if((x & (1 << i)) == 0){//hay un 0 en la posición i
			// x |= (1 << i);//set 1 at pos i
			// break;
		// }
	// }
	// i++;
	// for(; i < 32; i++){
		// if((x & (1 << i)) != 0){//hay un 1 at pos i
			// x &= ~(1 << i);//set 0
			// break;
		// }
	// }
	// return x;
// }

// //versión con define
// #define bitIs0(x, i) (x & (1 << i)) == 0
// #define bitIs1(x, i) (x & (1 << i)) != 0
// #define set1(x, i) x |= (1 << i)
// #define set0(x, i) x &= ~(1 << i)

// int nextNumber3(int x){
	// int i = 0;
	// for(; i < 32; i++){
		// if(bitIs1(x,i)){
			// set0(x,i);
			// break;
		// }
	// }
	// i++;
	// for(; i < 32; i++){
		// if(bitIs0(x,i)){
			// set1(x,i);
			// break;
		// }
	// }
	// return x;	
// }

// int prevNumber3(int x){
	// int i = 0;
	// for(; i < 32; i++){
		// if(bitIs0(x,i)){
			// set1(x,i);
			// break;
		// }
	// }
	// i++;
	// for(; i < 32; i++){
		// if(bitIs1(x,i)){
			// set0(x,i);
			// break;
		// }
	// }
	// return x;
// }

//////////////////////////////////////////////////////
// Las otras soluciones no siempre dan el número más próximo o anterior
//////////////////////////////////////////////////////
int nextNumber4(int x){
	int i = 0; int ones = 0;
	while((x & (1 << i)) == 0)
		i++;
	while((x & (1 << i)) != 0){
		i++;
		ones++;
	}
	
	if(ones == 0) { cout << "Error: todos 0's" << endl; return -1; }
	if(i == 31) { cout << "Error: no núm +grande con = #1's" << endl; return -1; }
	
	x |= (1 << i);
	x &= ~((1 << i) - 1);//borra todos los bits a la derecha de i
	x |= ((1 << ones-1) - 1);//seteo 'ones' -1; descuento un 1 xq seteé un 1 antes
	return x;
}

int prevNumber4(int x){
	int i = 0; int zeros = 0;
	while((x & (1 << i)) != 0){
		i++;
	}
	while((x & (1 << i)) == 0){
		i++;
		zeros++;
	}
	x &= ~(1 << i);//seteo un 0 en la posición i // nos aseguramos que el número sea más chico que x
	//ahora tratamos de hacerl
	x |= ((1 << i) - 1);//pongo 1s entre posición i+1 a fin
	x &= ~((1 << zeros-1) - 1);//pongo 'zeros' cantidad de 0s lo más al final posible
	//x &= ((~0) << zeros-1); otra mask similar como la anterior

	//de está forma el nuevo número es el más grande de los más chicos que x (con la misma #)
	return x;
}

//Arithmetic Approach idea CTCI + solución anterior
int getNextArith(int n){
	int c0 = 0; int c1 = 0; int i = 0;
	for(;((n & (1 << i)) == 0);i++) c0++;
	for(;((n & (1 << i)) != 0);i++) c1++;
	return n + (1 << c0) + (1 << (c1 - 1)) - 1;
}

int getPrevArith(int n){
	int c0 = 0; int c1 = 0; int i = 0;
	for(;((n & (1 << i)) != 0);i++) c1++;
	for(;((n & (1 << i)) == 0);i++) c0++;
	return n - (1 << c1) - (1 << (c0 - 1)) + 1;	
}


int main(){
	
	cout << "4th version (the first that works well)" << endl;
	cout << 3725 << endl;
	cout << nextNumber4(3725) << endl;
	cout << prevNumber4(3725) << endl;
	cout << 13948 << endl;
	cout << nextNumber4(13948) << endl;
	cout << prevNumber4(13948) << endl;
	cout << 10115 << endl;
	cout << prevNumber4(10115) << endl;
	cout << "5th Arithmetic" << endl;
	cout << 3725 << endl;
	cout << getNextArith(3725) << endl;
	cout << getPrevArith(3725) << endl;
	cout << 13948 << endl;
	cout << getNextArith(13948) << endl;
	cout << getPrevArith(13948) << endl;
	cout << 10115 << endl;
	cout << getPrevArith(10115) << endl;		
	//ademas si todos los números son 0... ie, s es "0...0"
	//el next que tiene la misma cantidad de 0 y 1 no se puede calcular
	//en 32bits no hay otro número que tenga 32 0's y 0 números 1
	//lo mismo para todos 1s "1..1" (el número -1)
	
	
	// int mask = ~((1 << 8) - 1);
	// cout << convertToBinaryString(mask) << endl;
	// mask = ((~0) << 8);//más linda 8)
	// cout << convertToBinaryString(mask) << endl;

	return 0;
}