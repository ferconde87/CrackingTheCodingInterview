#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <set>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

set<set<int> > powerSet(set<int> s){
	set<set<int> > ans;
	set<int> empty;
	ans.insert(empty);
	for(int x : s){
		set<set<int> > copy(ans);
		for(auto xs : copy){
			xs.insert(x);
			ans.insert(xs);
		}
	}
	return ans;
}

void print(set<set<int> > & s){
	if(s.size()==1){ cout << "{{''}}" << endl; return; }
	cout << "{{'";
	set< set <int> >::iterator itlast = s.end();
	itlast--;
	for(set< set <int> >::iterator itxs = s.begin(); itxs != s.end(); itxs++){
		set<int>::iterator itlastx = (*itxs).end();
		if(itlastx == (*itxs).begin()) { cout << "'}, "; continue;}
		itlastx--;
		cout << "{";
		for(set<int>::iterator itx = (*itxs).begin(); itx != (*itxs).end(); itx++){
			cout << *itx;
			if(itx != itlastx) cout << ", ";
		}
		if(itxs != itlast) cout << "}, ";
	}
	cout << "}}" << endl;
}


void print(vector<vector<int> > & vv){
	int n = vv.size();
	cout << "{";
	for(int i = 0; i < n; i++){
		cout << "{";
		int m = vv[i].size();
		for(int j = 0; j < m; j++){
			cout << vv[i][j];
			if(j == m-1) continue;
			cout << ", ";
		}
		if(i == n-1) continue;
		cout << "},";
	}
	cout << "}}" <<endl;
	
}
//using vector
vector<vector<int> > powerSet(vector<int> & v){
	vector<vector<int> > ans;
	vector<int> empty;
	ans.push_back(empty);
	for(int x : v){
		auto copy(ans);
		for(auto c : copy){
			c.push_back(x);
			ans.push_back(c);
		}
	}
	return ans;
}


int main(){
	//~ set<int> s = {1,2,3};
	//~ auto ans = powerSet(s); 
	//~ print(ans);
	//~ s = {};
	//~ ans = powerSet(s); 
	//~ print(ans);
	//~ s = {1,2,3, 4};
	//~ ans = powerSet(s); 
	//~ print(ans);
	
	vector<int> v = {1,2,3};
	auto vans = powerSet(v);
	print(vans);

	return 0;
}
