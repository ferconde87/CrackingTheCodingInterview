#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/* Given a sorted array of n integers that has been rotated an unknown
number of times, write code to find an element in the array. You may assume that the array was
originally sorted in increasing order. */

int binarySearch(vector<int> & v, int x, int left, int right){
	if(left > right) return -1;
	int mid = (left + right) / 2;
	if(v[mid] == x) return mid;
	if(x < v[mid]) return binarySearch(v, x, left, mid-1);
	else return binarySearch(v, x, mid+1, right);
}

//O(n)
int searchInRotatedArray(vector<int> & v, int x, int left, int right){
	if(left+1 >= right){
		if(v[left]==x) return left;
		else if(v[right]==x) return right;
		else return -1;
	}
	int mid = (left + right) / 2;
	int midValue = v[mid];
	if(midValue==x) return mid;
	if(v[mid-1] <= midValue && midValue <= v[mid+1]){
		int ans = searchInRotatedArray(v, x, 0, mid-1);
		if(ans != -1) return ans;
		return searchInRotatedArray(v, x, mid+1, left);	 
	}else{
		if(v[left] <= x && x <= v[mid-1]) return binarySearch(v, x, left, mid-1);
		return binarySearch(v, x, mid+1, right);
	}
}


int searchInRotatedArray(vector<int> & v, int x){
	return searchInRotatedArray(v, x, 0, v.size()-1);
}

////////////////////////////////////////////////
//O(N) repetidos (si todos o la mayoria son repetidos, tiene que mirar todos los elementos)
//O(log N) sin repetidos
int search(vector<int> & v, int x, int left, int right){
	if(left > right) return -1;
	int mid =  (left + right) / 2;
	if(x == v[mid]) return mid;
	
	if(v[left] < v[mid]){//left is normally ordered
		if(v[left] <= x && x < v[mid]){
			return search(v, x, left, mid-1);
		}else{
			return search(v, x, mid+1, right);
		}
	}else if(v[mid] < v[left]){//right is normally ordered
		if(x > v[mid] && x <= v[right]){
			return search(v, x, mid+1, right);
		}else{
			return search(v, x, left, mid-1);
		}
	}else if(v[left] == v[mid]){//left or right half is all repeated
		if(v[mid] != v[right]){
			return search(v, x, mid+1, right);
		}else{
			int ans = search(v, x, left, mid-1);
			if(ans != -1) return ans;
			return search(v, x, mid+1, right);
		}
	} 
}

int search(vector<int> & v, int x){
	return search(v, x, 0, v.size()-1);
}

void print(vector<int> & v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> v = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	cout << searchInRotatedArray(v, 5) << endl;
	cout << searchInRotatedArray(v, 6) << endl;
	cout << searchInRotatedArray(v, 14) << endl;
	cout << searchInRotatedArray(v, 13) << endl;
	cout << searchInRotatedArray(v, 10) << endl;
	cout << searchInRotatedArray(v, 15) << endl;
	cout << search(v, 5) << endl;
	cout << search(v, 6) << endl;
	cout << search(v, 14) << endl;
	cout << search(v, 13) << endl;
	cout << search(v, 10) << endl;
	cout << search(v, 15) << endl;
}


