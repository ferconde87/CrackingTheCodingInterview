#include <iostream>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

//compilation with flag -fpermissive
//example with g++ compiler: g++ -fpermissive 2ReverseString.cpp


//Implementation in-place for C
//~ void reverseString2(char * str){
	//~ char * end = str;
	//~ char tmp;
	//~ if(str){
		//~ while(*end){ // find end of the string
			//~ ++end;
			//~ cn(*end)
		//~ }
		//~ --end; // set one char back, since last char is null
		//~ /* swap characters from start of string with the end of the string,
		//~ * until pointers meet in the middle */
		//~ while(*str < *end){
			//~ tmp = *str;
			//~ *str++ = *end;   
			//~ *end-- = tmp;
		//~ }
	//~ }
//~ }

//Implementation just for educational purpose
char * reverseString(char * str){
	char * end = str;
	char tmp;
	int size = 0;
	char * res;
	if(str){
		while(*end){ // find end of the string
			++end;
			size++;
		}
		--end; // set one char back, since last char is null
		/* swap characters from start of string with the end of the string,
		* until pointers meet in the middle */
		res = new char[size];
		int i = 0;
		int last = size-1;
		while(str < end){
			tmp = *str;
			res[last--] = *str++;   
			res[i++] = *end--;
		}
		if(str==end){//when size of str is odd pointers str & end are equals
			res[i] = *str;//and we have to assing the element in the middle
		}
	}
	return res;
}

int main(){
	char * str = "Hell";
	char * res = reverseString(str);
	cout << res << endl;
	str = "Hello";
	res = reverseString(str);
	cout << res << endl;
}
