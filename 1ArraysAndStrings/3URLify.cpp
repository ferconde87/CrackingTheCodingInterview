/*
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)
EXAMPLE
", 13
Input: "Mr John Smith
Output: "Mr%20John%20Smith"
*/

#include <iostream>
#include <string>

using namespace std;

string URLify(string s){
	string r;
	for(int i = 0; i < s.size(); i++){
		if(s[i]==' '){
			r.push_back('%');
			r.push_back('2');
			r.push_back('0');
		}else{
			r.push_back(s[i]);
		}
	}
	return r;
}

//~ s = "hola mundo  "
//~ "hola mundo o"
//~ "hola mundodo"
//~ "hola mundndo"
//~ "hola munundo"
//~ "hola mumundo"
//~ "hola%20mundo"

void URLify(string & s, int size){
	int spaces = 0;
	for(int i = 0; i < size; i++)
		if(s[i]==' ')
			spaces++;
	for(int i = size-1; i >= 0; i--){
		if(s[i]!=' '){
			s[i+spaces*2] = s[i];
		}else{
			s[i+spaces*2] = '0';
			s[i+spaces*2-1] = '2';
			s[i+spaces*2-2] = '%';
			spaces--;
		}
	}
	
		
}

//~ s = "Mr John Smith"
//~ "Mr John Smith    "
//~ "Mr John Smith   h"
//~ "Mr John Smith  th"
//~ "Mr John Smith ith"
//~ "Mr John Smithmith"
//~ "Mr John SmitSmith"
//~ "Mr John S%20Smith"
//~ "Mr John n%20Smith"


int main(){
	string s = "Mr John Smith    ";
	cout << URLify(s) << endl;
	URLify(s, 13);
	cout << s << endl;
	s = "hola mundo  ";
	URLify(s, 11);
	cout << s << endl;
	return 0;
}
