#include <iostream>
#include "BitManipulation.h"

using namespace std;


int main(){
	
	for(long long int n = 0; n <= 65536; n++){
		if((n & (n-1)) == 0)
			cout << n << "\t\t = " <<  convertToBinaryString(n) << endl;
	}
	
	return 0;
}