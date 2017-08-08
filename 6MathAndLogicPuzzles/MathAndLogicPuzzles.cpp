#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //sqrt

#define endl "\n"

using namespace std;

bool isPrime(int x){
	if(x < 2) return false;
	int n = (int)sqrt(x);
	for(int i = 2; i < n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

vector<bool> sieveOfEratosthenes(int max){
	vector<bool> sieve(max+1, true);
	sieve[0] = false; sieve[1] = false;
	int n = (int)sqrt(max);
	int i = 2;
	while(i <= n){
		for(int p = i*i; p <= max; p+= i)
			sieve[p] = false;
		i++;
		while(sieve[i]==0 && i <= max)i++;
	}
	return sieve;
}

void print(vector<bool> v){
	for(int i = 0; i < v.size(); i++){
		cout << i << " = " << v[i] << "; ";
		if(i > 0 && i % 10 == 0) cout << "\n";
	}
	cout << endl;
}

void printTrueIndexes(vector<bool> v){
	for(int i = 0; i < v.size(); i++){
		if(v[i] == true) cout << i << " ";
	}
	cout << endl;
}

int main(){
	
	vector<bool> sieve = sieveOfEratosthenes(10000);
	//print(sieve);
	printTrueIndexes(sieve);
	
	return 0;
}