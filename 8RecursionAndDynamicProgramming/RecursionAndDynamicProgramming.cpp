#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n){
	if(n == 0 || n == 1) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciTopDown(int n, vector<int> & memo){
	if(n == 0 || n == 1) return n;
	if(memo[n] == 0){
		memo[n] = fibonacciTopDown(n-1, memo) + fibonacciTopDown(n-1, memo);
	}
	return memo[n];	
}

int fibonacciTopDown(int n){
	vector<int> memo(n, 0);
	return fibonacciTopDown(n, memo);
}

int fibonacci2(int n, vector<int> & v){
	if(n <= 0) return 0;
	v[1] = 1;
	for(int i = 2; i <= n; i++){
		v[i] = v[i-1] + v[i-2];
	}
	return v[n];
}

int fibonacci2(int n){
	vector<int> v(n+1, 0);
	return fibonacci2(n, v);
}

//b
int fibonacci2b(int n, vector<int> & v){
	if(n <= 1) return n;
	v[1] = 1;
	for(int i = 2; i < n; i++){
		v[i] = v[i-1] + v[i-2];
	}
	return v[n-1] + v[n-2];
}

int fibonacci2b(int n){
	vector<int> v(n, 0);
	return fibonacci2b(n, v);
}

int fibonacci3(int n){
	if(n <= 0) return 0;
	int i1 = 1;
	int i2 = 1;
	int ans = 1;
	for(int i = 2; i < n; i++){
		ans = i1 + i2;
		i1 = i2;
		i2 = ans;
	}
	return ans;
}

int main(){
	
	cout << fibonacci(8) << endl;
	cout << fibonacci2(8) << endl;
	cout << fibonacci3(8) << endl;
	cout << fibonacciTopDown(8) << endl;
	
	return 0;
}
