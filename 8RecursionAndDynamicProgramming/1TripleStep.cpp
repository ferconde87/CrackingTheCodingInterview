#include <iostream>
#include <vector>

using namespace std;

//O(3^n)
int tripleStep(int n){
	if(n < 3) return n;
	if(n == 3) return 4;
	return tripleStep(n-1) + tripleStep(n-2) + tripleStep(n-3);
}

//O(n) complejidad temporal y espacial
int tripleStepDP(int n, vector<int> & v){
	if(n < 3) return n;
	if(n == 3) return 4;
	v[0] = 1;
	v[1] = 2;
	v[2] = 4;
	for(int i = 3; i < n; i++){
		v[i] = v[i-1] + v[i-2] + v[i-3];
	}
	return v[n-1];
}

int tripleStepDP(int n){
	vector<int> v(n,0);
	return tripleStepDP(n , v);
}

//O(n) complejidad temporal y O(1) espacial
int tripleStepDPImproved(int n, vector<int> & v){
	if(n < 3) return n;
	if(n == 3) return 4;
	v[0] = 1;
	v[1] = 2;
	v[2] = 4;
	for(int i = 3; i < n; i++){
		v[i] = v[i-1] + v[i-2] + v[i-3];
	}
	return v[n-1];
}

int tripleStepDPImproved(int n){
	if(n < 3) return n;
	if(n == 3) return 4;
	int i1 = 1;
	int i2 = 2;
	int i3 = 4;
	int ans;
	for(int i = 4; i <= n; i++){
		ans = i1 + i2 + i3;
		i1 = i2; i2 = i3; i3 = ans;
	}
	return ans;
}

int main(){
	
	cout << tripleStep(5) << endl;
	cout << tripleStepDP(5) << endl;
	cout << tripleStepDPImproved(5) << endl;
	cout << tripleStep(6) << endl;
	cout << tripleStepDP(6) << endl;
	cout << tripleStepDPImproved(6) << endl;
	
	
	return 0;
}
