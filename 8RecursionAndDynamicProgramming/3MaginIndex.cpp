#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

#define CYESNO(x) cout << (x ? "YES" : "NO") << endl;
#define CN(x) cout << #x << " = " << x << endl;
using namespace std;


int findMagicIndexBF(vector<int> & v){
	for(int i = 0; i < v.size(); i++)
		if(v[i]==i)return i;
	return -1;
}

//sin repetidos: v estrictamente creciente
int findMagicIndex(vector<int> & v, int start, int end){
	if(start > end) return -1;
	int mid = (start + end) / 2;
	if(v[mid] == mid) return mid;
	if(v[mid] < mid){
		return findMagicIndex(v, mid+1, end);
	}else{
		return findMagicIndex(v, start, mid-1);
	}
}

int findMagicIndex(vector<int> & v){
	return findMagicIndex(v, 0, v.size()-1);
}

////con repetidos
int findMagicIndexWithReps(vector<int> & v, int start, int end){
	if(start > end) return -1;
	int mid = (start + end) / 2;
	int x = v[mid];
	if(x == mid) return x;
	
	int leftEnd = min(mid-1, x);
	int ansLeft = findMagicIndexWithReps(v, start, leftEnd);
	if(ansLeft != -1) return ansLeft;
	
	int rightStart = max(mid+1, x);
	int ansRight = findMagicIndexWithReps(v, rightStart, end);
	if(ansRight != -1) return ansRight;
	
	return -1;
}


int findMagicIndexWithReps(vector<int> & v){
	return findMagicIndexWithReps(v, 0, v.size()-1);
}

int main(){
	
	//sin elementos repetidos
	vector<int> v = {-10, -3, 0, 3, 8, 9, 12, 15};
	cout << findMagicIndex(v) << endl;
	v = {-2, -1, 2, 3, 5, 8, 9, 12, 13, 16};
	cout << findMagicIndex(v) << endl;
	//con repetidos
	v = {0, 0, 4, 4, 4};
	cout << findMagicIndexWithReps(v) << endl;
	assert(findMagicIndexWithReps(v)==0);//podría también 4 (cambiando el algoritmo, claro) 
	
	v = {0, 0, 4, 4, 5};
	cout << findMagicIndexWithReps(v) << endl;
	assert(findMagicIndexWithReps(v)==0);
	
	v = {-1, 0, 4, 4, 5};
	cout << findMagicIndexWithReps(v) << endl;
	assert(findMagicIndexWithReps(v)==-1);
	
	v = {-1, 0, 4, 4, 4};
	cout << findMagicIndexWithReps(v) << endl;
	assert(findMagicIndexWithReps(v)==4);

	return 0;
}
