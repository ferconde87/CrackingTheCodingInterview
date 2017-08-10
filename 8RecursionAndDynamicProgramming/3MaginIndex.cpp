#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define CYESNO(x) cout << (x ? "YES" : "NO") << endl;
#define CN(x) cout << #x << " = " << x << endl;
using namespace std;


int findMagicIndexBF(vector<int> & v){
	for(int i = 0; i < v.size(); i++)
		if(v[i]==i)return i;
	return -1;
}

int findMagicIndex(vector<int> & v, int start, int end){
	if(start > end) return -1;
	int mid = (start + end) / 2;
	CN(start)
	CN(end)
	cout << "-" << endl;
	CN(mid)
		
	if(v[mid] == mid) return mid;
	if(v[mid] < mid){
		return findMagicIndex(v, mid+1, end);
	}else{
		return findMagicIndex(v, start, mid-1);
	}
}


int findMagicIndex(vector<int> & v){
	CN(v.size())
	return findMagicIndex(v, 0, v.size()-1);
}

////con repetidos
int findMagicIndexWithReps(vector<int> & v, int start, int end){
	if(start > end) return -1;
	int mid = (start + end) / 2;
	CN(start)
	CN(end)
	cout << "-" << endl;
	CN(mid)
		
	if(v[mid] == mid) return mid;
	if(v[mid] < mid){
		return findMagicIndexWithReps(v, mid+1, end);
	}else{
		return findMagicIndexWithReps(v, start, mid-1);
	}
}


int findMagicIndexWithReps(vector<int> & v){
	CN(v.size())
	return findMagicIndexWithReps(v, 0, v.size()-1);
}

int main(){
	
	vector<int> v = {-10, -3, 0, 3, 8, 9, 12, 15};
	
	cout << findMagicIndex(v) << endl;
	
	vector<int> w = {-2, -1, 2, 3, 5, 8, 9, 12, 13, 16};
	
	cout << findMagicIndex(w) << endl;
	
	return 0;
}
