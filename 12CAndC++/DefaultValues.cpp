#include <iostream>

using namespace std;

int function(int a, int b = 3){
	return a + b;
}

int main(){
	cout << function(2) << endl;
	cout << function(2,3) << endl;
	cout << function(4,5) << endl;
}
