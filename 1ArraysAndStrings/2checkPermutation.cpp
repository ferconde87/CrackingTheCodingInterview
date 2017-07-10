/*
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other
*/

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

void fillHashMap(unordered_map<char, int> & m, string s){
	for(int i = 0; i < s.size(); i++){
		if(m.find(s[i])==m.end()){
			m[s[i]] = 1;
		}else{
			m[s[i]]++;
		}
	}		
}

bool isPermutation(unordered_map<char, int> & a, unordered_map<char, int> & b){
	for(auto it = a.begin(); it != a.end(); it++){
		if(b.find(it->first)==b.end() || b[it->first] != it->second)
			return false;
	}
	return true;
}

//check if b is permutation of a
bool isPermutation(string a, string b){
	unordered_map<char, int> ma;
	unordered_map<char, int> mb;
	fillHashMap(ma, a);
	fillHashMap(mb, b);
	if(ma.size() < mb.size())
		return isPermutation(ma, mb);
	return isPermutation(mb, ma);
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << isPermutation(a, b) << endl;
	return 0;
}
