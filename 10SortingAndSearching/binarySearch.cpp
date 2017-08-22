#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int binarySearchIterative(vector<int> & v, int x){
	int low = 0;
	int high = v.size()-1;
	int mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid]){
			high = mid-1;		
		}else if(x > v[mid]){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}

int binarySearch(vector<int> & v, int x, int low, int high){
	if(low > high) return -1;// not found it	
	int mid = (low + high) / 2;
	if(x < v[mid]){
		return binarySearch(v, x, low, mid-1);
	}else if(x > v[mid]){
		return binarySearch(v, x, mid+1, high);
	}else{
		return mid;
	}
}

int binarySearch(vector<int> & v, int x){
	return binarySearch(v, x, 0, v.size()-1);
}

int main(){
	vector<int> v = {1,3,5,7,9,11,13,15,17};
	assert(binarySearch(v, 4)==-1);
	assert(binarySearchIterative(v, 4)==-1);
	assert(binarySearch(v, 15)==7);
	assert(binarySearchIterative(v, 15)==7);
	
	vector<int> w = {-1,-1,1,2,3,4,5,7,8,8,8,8,9,10,11,12};
	assert(binarySearch(w, 0)==-1);
	assert(binarySearchIterative(w, 0)==-1);
	assert(binarySearch(w,10)==13);
	assert(binarySearchIterative(w, 10)==13);
}
