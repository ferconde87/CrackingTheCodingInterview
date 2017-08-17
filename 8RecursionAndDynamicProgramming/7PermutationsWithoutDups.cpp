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

vector<string> permuteElement(string s, char c){
	vector<string> ans;
	for(int i = 0; i <= s.size(); i++){
		string t = s;
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


//with recursion
void permute(vector<string> & ans, char c){
	vector<string> copy(ans);
	ans.clear();
	for(int i = 0; i < copy.size(); i++){
		string & s = copy[i];
		for(int j = 0; j <= s.size(); j++){
			string t = s;
			t.insert(t.begin()+j, c);
			ans.push_back(t);
		}
	}
}

vector<string> permutationsRec(string & s, int pos, int end){
	vector<string> ans;
	if(pos == end){
		string base;
		base.push_back(s[end]);
		ans.push_back(base);
		return ans;
	}
	ans = permutationsRec(s, pos+1, end);
	permute(ans, s[pos]);
	return ans;
}

vector<string> permutationsRec(string & s){
	return permutationsRec(s, 0, s.size()-1);
}


int main(){	

	cout << "Permutations" << endl;
	string s = "abc";
	auto vs = permutations(s);
	print(vs);
	s = "abcd";
	vs = permutations(s);
	print(vs);
	cout << endl;
	//
	cout << "Permutations with Recursion" << endl;
	s = "abc";
	vs = permutationsRec(s);
	print(vs);
	s = "abcd";
	vs = permutationsRec(s);
	print(vs);
	cout << endl;
	
	return 0;
}

