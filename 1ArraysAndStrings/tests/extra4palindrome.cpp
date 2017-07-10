/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­
drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat", "atco eta", etc.) 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

bool isPalindromePermutation(string & s){
	int i = 0;
	int j = s.size()-1;
	while(i<j){
		char iLower = tolower(s[i]); 
		char jLower = tolower(s[j]); 
		if(iLower==jLower){
			i++;j--;
		}else if(iLower==' '){
			i++;
		}else if(jLower==' '){
			j--;
		}else{
			return false;
		}
	}
	return true;	
}

int main(){
	string s;
	cin >> s;
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "pe ep";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl;
	s = "Tact Coa";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl;
	s = "Act tCa";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl;
	return 0;
}
