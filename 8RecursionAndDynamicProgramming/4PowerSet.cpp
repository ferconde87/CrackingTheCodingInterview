#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <set>

using namespace std;


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


int main(){
	set<int> s = {1,2,3};
	auto ans = powerSet(s); 
	print(ans);
	s = {};
	ans = powerSet(s); 
	print(ans);
	s = {1,2,3, 4};
	ans = powerSet(s); 
	print(ans);

	return 0;
}
