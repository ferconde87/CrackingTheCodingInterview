#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
method. It does, however, have an elementAt ( i) method that returns the element at index i in
0( 1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data
structure only supports positive integers.) Given a Li sty which contains sorted, positive integers,
find the index at which an element x occurs. If x occurs multiple times, you may return any index. */

#define cn(x) cout << #x << " = " << x << endl;

//worst case O(N)
int search(vector<int> & v, int x, int left, int right){
	if(left>right) return -1;
	int mid = (left + right) / 2;
	if(v[mid] == x){ 
		return mid;
	}else if(v[mid] < x){
		if(v[right] < x){
			if(right*2 > v.size()-1){
				if(right+2 > v.size()-1)
					return (v[right+1] == x) ? right+1 : -1;
				return search(v, x, right+1, right+2);//beacuse of this
			}else{
				return search(v, x, right+1, right*2);
			}
		}else{
			if(v[right]==x) return right;
			else return search(v, x, mid+1, right-1);
		}
	}else{
		return search(v, x, left, mid-1);
	}
}

int search(vector<int> & v, int x){
	return search(v, x, 0, 1);
}


///////////////////////////////
int elementAt(vector<int> & v, int i){
	if(i < v.size()) return v[i];
	return -1;
}

int binarySearch(vector<int> & v, int x, int left, int right){
	if(left>right) return -1;
	int mid = (left + right) / 2;
	if(elementAt(v, mid) == -1 || x < v[mid]){
		return binarySearch(v, x, left, mid-1);
	}else if(x > v[mid]){
		return binarySearch(v, x, mid+1, right);
	}else{
		return mid;
	}
}


int search2(vector<int> & v, int x){
	if(elementAt(v, 0)==-1)return 0;
	int n = 1;
	while(elementAt(v, n)!=-1 && v[n] < x) { n*=2;}
	return binarySearch(v, x, n/2, n);
}

int main(){
	vector<int> v = {1,3,5,7,9,11,13,17,19};
	
	cout << "search" << endl;
	assert(search(v,3)==1);
	assert(search(v,5)==2);
	assert(search(v,13)==6);
	assert(search(v,4)==-1);
	assert(search(v,18)==-1);
	
	////////////////////////////
	cout << "search2" << endl;
	assert(search2(v,3)==1);
	assert(search2(v,5)==2);
	assert(search2(v,13)==6);
	assert(search2(v,4)==-1);
	assert(search2(v,18)==-1);
	
}

