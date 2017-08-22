#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/* Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to
each other. */

vector<string> groupOfAnagrams(vector<string> & vs){
	unordered_map<string, vector<string> > map;
	for(string s : vs){
		string t = s;
		sort(t.begin(), t.end());
		auto it = map.find(t);
		if(it == map.end()){
			vector<string> w;
			w.push_back(s);
			map.insert(make_pair(t, w));
		}else{
			it->second.push_back(s);
		}
	}
	vector<string> ans;
	//~ for(auto it = map.begin(); it != map.end(); it++){
		//~ vector<string> anagrams = it->second;
		//~ for(string a : anagrams){
			//~ ans.push_back(a);
		//~ }
	//~ }
	for(auto pair : map){
		vector<string> anagrams = pair.second;
		for(string a : anagrams){
			ans.push_back(a);
		}
	}
	return ans;
}


void print(vector<string> & v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<string> vs = {"hola", "acre", "arce", "race", "pepe", "aloh"};
	auto ans = groupOfAnagrams(vs);
	print(ans);
}

