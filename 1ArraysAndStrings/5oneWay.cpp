/*
 * One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isOneAwayPermutation(string & a, string & b){
	int n = a.size();
	int m = b.size();
	if(!(n==m||n-1==m||n+1==m))
		return false;
	vector<int> v(128, 0);
	bool oneAllow = n-1!=m;
	for(int i = 0; i < n; i++)
		v[a[i]]++;
	for(int i = 0; i < m; i++){
		if(v[b[i]]==0){
			if(oneAllow)
				oneAllow = false;
			else
				return false;
		}else{
			v[b[i]]--;
		}
	}
	return true;
}

bool isOneAway(string & a, string & b){
	int n = a.size();
	int m = b.size();
	if(!(n==m||n-1==m||n+1==m))
		return false;
	vector<int> v(128, 0);
	bool oneAllow = true;
	if(n==m){
		for(int i = 0; i < n; i++){
			if(a[i]==b[i]) continue;
			if(a[i]!=b[i]){
				if(oneAllow)
					oneAllow = false;
				else
					return false;
			}
		}
	}else if(n < m){
		int offset = 0;
		for(int i = 0; i < n; i++){
			if(a[i]==b[i+offset]) continue;
			if(a[i]!=b[i+offset]){
				if(oneAllow){
					oneAllow = false;
					offset++;
					if(a[i]!=b[i+offset])
						return false;
				}else{
					return false;
				}
			}
		}		
	}else{
		int offset = 0;
		for(int i = 0; i < m; i++){
			if(a[i+offset]==b[i]) continue;
			if(a[i+offset]!=b[i]){
				if(oneAllow){
					oneAllow = false;
					offset++;
					if(a[i+offset]!=b[i])
						return false;
				}else{
					return false;
				}
			}
		}		
	}
	return true;
}


bool isOneAway2(string & a, string & b){
	int n = a.size();
	int m = b.size();
	if(!(n==m||n-1==m||n+1==m))
		return false;
	vector<int> v(128, 0);
	bool oneAllow = true;
	if(n==m){
		for(int i = 0; i < n; i++){
			if(a[i]==b[i]) continue;
			if(a[i]!=b[i]){
				if(oneAllow)
					oneAllow = false;
				else
					return false;
			}
		}
	}else{
		int offsetA = 0;
		int offsetB = 0;
		int size = min(n,m);
		for(int i = 0; i < size; i++){
			if(a[i+offsetA]==b[i+offsetB]) continue;
			if(a[i+offsetB]!=b[i+offsetB]){
				if(oneAllow){
					oneAllow = false;
					if(n>m)offsetA++;
					else offsetB++;
					if(a[i+offsetA]!=b[i+offsetB])
						return false;
				}else{
					return false;
				}
			}
		}		
	}
	
	return true;
}


bool isOneAway3(string & a, string & b){
	int n = a.size();
	int m = b.size();
	if(!(n==m||n-1==m||n+1==m))
		return false;
	vector<int> v(128, 0);
	bool oneAllow = true;
	int offsetA = 0;
	int offsetB = 0;
	int size = min(n,m);
	for(int i = 0; i < size; i++){
		if(a[i+offsetA]==b[i+offsetB]) continue;
		if(a[i+offsetB]!=b[i+offsetB]){
			if(oneAllow){
				oneAllow = false;
				if(n>m) offsetA++;
				else if(n>m) offsetB++;
				else continue;
				if(a[i+offsetA]!=b[i+offsetB])
					return false;
			}else{
				return false;
			}
		}
	}		
	return true;
}

int main(){
	string a, b;
	
	//tengo que ver lo del assert (!)
	
	//~ a = "pale"; b = "ple";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "pales"; b = "pale";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "pale"; b = "bale";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "pale"; b = "bake";
	//~ cout << isOneAway(a, b) << endl;
	a = "zzzjl"; b = "zzjl";
	cout << isOneAway(a, b) << endl;
	a = "zzzxl"; b = "zzjl";
	cout << isOneAway(a, b) << endl;
	a = "zzxl"; b = "zzzjl";
	cout << isOneAway(a, b) << endl;
	a = "zzxl"; b = "zzjl";
	cout << isOneAway(a, b) << endl;	
	//~ a = "zzzl"; b = "zzjl";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "zzzjl"; b = "zzzzjl";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "pale"; b = "pale";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "zzzll"; b = "llzzz";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "zzzll"; b = "llazzz";
	//~ cout << isOneAway(a, b) << endl;
	//~ a = "zzzll"; b = "llabzz";
	//~ cout << isOneAway(a, b) << endl;

	a = "zzzjl"; b = "zzjl";
	cout << isOneAway2(a, b) << endl;
	a = "zzzxl"; b = "zzjl";
	cout << isOneAway2(a, b) << endl;
	a = "zzxl"; b = "zzzjl";
	cout << isOneAway2(a, b) << endl;
	a = "zzxl"; b = "zzjl";
	cout << isOneAway2(a, b) << endl;
	
	a = "zzzjl"; b = "zzjl";
	cout << isOneAway3(a, b) << endl;
	a = "zzzxl"; b = "zzjl";
	cout << isOneAway3(a, b) << endl;
	a = "zzxl"; b = "zzzjl";
	cout << isOneAway3(a, b) << endl;
	a = "zzxl"; b = "zzjl";
	cout << isOneAway3(a, b) << endl;
}
