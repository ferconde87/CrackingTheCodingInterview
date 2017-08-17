#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <set>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/*Permutations without Dups: Write a method to compute all permutations of a string of unique
characters.*/

vector<string> permuteElementHT(string s, char c){
	vector<string> ans;
	int n = s.size();
	for(int i = 0; i <= n; i++){
		string t = s;
		if(i < n && t[i]==c)continue;
		t.insert(t.begin()+i, c);
		ans.push_back(t);
	}
	return ans;
}

vector<string> permutationsHT(string & s, unordered_set<string> & set){
	vector<string> ans;
	int n = s.size();
	if(n==0) return ans;
	string a;
	a.push_back(s[0]);
	ans.push_back(a);
	vector<string> permutations;
	for(int i = 1; i < n; i++){
		vector<string> copy(ans);
		ans.clear();
		if(i < n-1){
			for(auto xs : copy){
				vector<string> cur = permuteElementHT(xs, s[i]);
				ans.insert(ans.end(), cur.begin(), cur.end());			
			}
		}else{
			for(auto xs : copy){
				vector<string> cur = permuteElementHT(xs, s[i]);
				for(string cs : cur){
					if(set.find(cs)!=set.end())continue;
					set.insert(cs);
					ans.push_back(cs);
				}			
			}		
		}
	}
	return ans;
}

vector<string> permutationsHT(string & s){
	unordered_set<string> map;
	return permutationsHT(s, map);
} 


///////////////////////////////////////////////////////////
vector<string> permuteElement(string s, char c){
	vector<string> ans;
	for(int i = 0; i <= s.size(); i++){
		string t = s;
		if(t[i]==c)continue;
		t.insert(t.begin()+i, c);
		ans.push_back(t);
	}
	return ans;
}

vector<string> permutations(string & s){
	vector<string> ans;
	int n = s.size();
	if(n==0) return ans;
	string a;
	a.push_back(s[0]);
	ans.push_back(a);
	vector<string> permutations;
	for(int i = 1; i < n; i++){
		vector<string> copy(ans);
		ans.clear();
		for(auto xs : copy){
			vector<string> cur = permuteElement(xs, s[i]);
			ans.insert(ans.end(), cur.begin(), cur.end());			
		}
	}
	return ans;
}

void print(vector<string> & vs){
	for(string s : vs){
		cout << s << " ";
	}
	cout << endl;
}


int main(){	

	cout << "Permutations with duplicates using HT" << endl;
	string t = "aba";
	auto vt = permutationsHT(t);
	print(vt);
	t = "abca";
	vt = permutationsHT(t);
	print(vt);
	t = "aaaaa";
	vt = permutationsHT(t);
	print(vt);
	cout << endl;


	cout << "Permutations" << endl;
	string s = "aaaaaaa";
	auto vs = permutations(s);//sin HT no saca todos los repetidos, pero con if(t[i]==c)continue; sacá "muchos"
	print(vs);
	
	return 0;
}

