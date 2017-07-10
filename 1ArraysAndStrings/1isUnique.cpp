/*
 * Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures? Hints: #44, #117, #132
* */

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//asumption: ascii characteres
bool allUnique(string & s){
	vector<int> v(128, 0);
	for(int i = 0; i < s.size(); i++){
		v[s[i]]++;
	}
	
	for(int i = 0; i < 128; i++){
		if(v[i]>1){
			return false;
		}
	}	
	return true;
}

bool allUniqueHT(string & s){
	unordered_set<int> ht;
	for(int i = 0; i < s.size(); i++){
		if(ht.find(s[i])==ht.end())
			ht.insert(s[i]);
		else
			return false;
	}
	return true;
}

bool allUniqueSorting(string & s){
	sort(s.begin(), s.end());
	for(int i = 0; i < s.size()-1; i++){
		if(s[i]==s[i+1])
			return false;
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	cout << allUnique(s) << endl;
	cout << allUniqueHT(s) << endl;
	cout << allUniqueSorting(s) << endl;
	return 0;
}
