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
#include <unordered_map>
#include <chrono>

using namespace std;

bool isPalindromePermutation(string & s){
	unordered_map<char, int> hm;
	for(int i = 0; i < s.size(); i++){
		if(s[i]==' ') continue;
		char lower = tolower(s[i]);
		if(hm.find(lower)==hm.end()){
			hm[lower] = 1;
		}else{
			hm[lower]++;
		}
	}
	bool allowOneOddChar = true;
	for(auto it = hm.begin(); it != hm.end(); it++){
			if(it->second%2){//isOdd
				if(allowOneOddChar)
					allowOneOddChar = false;
				else
					return false;
			}
	}
	return true;
}

bool isPalindromePermutation2(string & s){
	int n = s.size();
	if(n<=1) return true;//nos aseguramos que hayan 2 elementos
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	sort(s.begin(), s.end());
	int count = 0;
	//~ for(int i = 0; i < s.size(); i++)
		//~ if(s[i]!= ' ')count++;
	bool allowOneOddChar = true;;
	count = 0;
	for(int i = 0; i < n-1; i++){
		if(s[i]==' ')continue;
		if(s[i]==s[i+1]){
			if(!count)
				count = 2;
			else
				count++;
			i++;
		}else{
			
			if(allowOneOddChar)
				allowOneOddChar = false;
			else
				return false;
		}
	}
	
	return (s[n-1]==s[n-2]) || allowOneOddChar;
}

bool isPalindromePermutation3(string & s){
	vector<bool>  v(128, true);
	int n = s.size();
	for(int i = 0; i < n; i++){
		//~ v[s[i]] = !v[s[i]];
		if(s[i]==' ')continue;
		char lower = tolower(s[i]);
		if(v[lower])
			v[lower] = false;
		else
			v[lower] = true;
	}
	
	bool allowOneOddChar = true;
	for(int i = 0; i < 128; i++){
		if(!v[i]){
			if(allowOneOddChar)
				allowOneOddChar = false;
			else
				return false;
		}
	}	
	return true;	
}

int main(){
	string s;
	
	auto t1 = chrono::high_resolution_clock::now();
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "pe ep";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "Tact Coa";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "Act tCa";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "evEn N c";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "evEn N c c";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	s = "evEn N c z ";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation(s) << endl; 
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> ms = t2 - t1;
	cout << "time = " << ms.count() << endl;
	cout << endl;
	
	s = "";
	auto t3 = chrono::high_resolution_clock::now();
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	cout << "isPalindromePermutation(" << s <<") = " << isPalindromePermutation2(s) << endl; 	 
	s = "pe ep";
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	s = "Tact Coa";
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	s = "Act tCa";
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	s = "evEn N c";
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	s = "evEn N c c";
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	s = "evEn N c z ";
	cout << "isPalindromePermutation2(" << s <<") = " << isPalindromePermutation2(s) << endl;
	auto t4 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> ms2 = t4 - t3;
	cout << "time2 = " << ms2.count() << endl;
	cout << endl;
	
	s = "";
	t1 = chrono::high_resolution_clock::now();
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "pe ep";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "Tact Coa";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "Act tCa";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "evEn N c";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "evEn N c c";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	s = "evEn N c z ";
	cout << "isPalindromePermutation3(" << s <<") = " << isPalindromePermutation3(s) << endl; 
	t2 = chrono::high_resolution_clock::now();
	ms = t2 - t1;
	cout << "time3 = " << ms.count() << endl;
	cout << endl;
	
	t1 = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000; i++){
		s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
		isPalindromePermutation(s);
	}
	cout << isPalindromePermutation(s) << endl; 
	t2 = chrono::high_resolution_clock::now();
	ms = t2 - t1;
	cout << "time = " << ms.count() << endl;
	
	t3 = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000; i++){
		s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
		isPalindromePermutation2(s);
	}
	cout << isPalindromePermutation2(s) << endl; 
	t4 = chrono::high_resolution_clock::now();
	ms2 = t4 - t3;
	cout << "time2 = " << ms2.count() << endl;
	
	t1 = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000; i++){
		s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
		isPalindromePermutation3(s);
	}
	cout << isPalindromePermutation3(s) << endl; 
	t2 = chrono::high_resolution_clock::now();
	ms = t2 - t1;
	cout << "time3 = " << ms.count() << endl;
	
	return 0;
}
