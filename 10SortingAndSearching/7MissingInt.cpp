#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/* Given an input file with four billion non-negative integers, provide an algorithm to
generate an integer that is not contained in the file. Assume you have 1 GB of memory available for
this task.
FOLLOW UP
What if you have only 10 MB of memory? Assume that all the values are distinct and we now have
no more than one billion non-negative integers. */

#define cn(x) cout << #x << " = " << x << endl;

int getLastBit(int last){
	for(int i = 31; i >= 0; i--){
		if((last & (1 << i)) != 0) return i;
	}
}

//al imprimir poda los ceros más significativos del último número del vector
void printBits2(vector<int> & v){
	int n = v.size();
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < 32; j++){
			cout << ((v[i] & (1 << j)) != 0) << " ";
		}
	}
	int last = v[n-1];
	int indexOfLastBit = getLastBit(last); 
	for(int i = 0; i <= indexOfLastBit; i++){
		cout << ((last & (1 << i)) != 0) << " ";
	}
	cout << endl;
}

void printBits(vector<int> & v){
	for(int x : v){
		for(int i = 0; i < 32; i++){
			cout << ((x & (1 << i)) != 0) << " ";
		}
	}
	cout << endl;
}

long long missingInt(vector<long long> & v){
	int max = *max_element(v.begin(), v.end());
	int n = (max/32)+1;
	vector<int> bitfield(n, 0);
	for(auto x : v){
		bitfield[x/32] |= (1 << (x % 32));
	}
	//~ printBits2(bitfield);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 32; j++){
			if((bitfield[i] & (1 << j)) == 0){
				return i*32 + j;
			}
		}
	}
	return 0;
}


int main(){
	vector<long long> v = {0,4,2,6,1,3,12,9,13,11,8,600};
	cout << missingInt(v) << endl;
	vector<long long> w(78);
	for(int i = 0; i < 42; i++) w[i] = i;
	for(int i = 43; i < 78; i++) w[i] = i;
	cout << missingInt(w) << endl;
}

