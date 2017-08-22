#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/* Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the
end to hold B. Write a method to merge B into A in sorted order. */

void sortedMerge(vector<int> & a, int elements_in_a, vector<int> & b){
	int elements_in_b = b.size();
	int lastIndex = elements_in_a + elements_in_b - 1;
	int i = elements_in_a - 1;
	int j = elements_in_b - 1;
	int k = lastIndex;
	while(i >= 0 && j >= 0){
		if(a[i] > b[j]){
			a[k] = a[i];
			i--;
		}else{
			a[k] = b[j];
			j--;
		}
		k--;
	}
	
	while(j >= 0){
		a[k] = b[j];j--;k--;
	}
	//*this is not necessary cuz 'a' would be already in its place
	//~ while(i >= 0){
		//~ a[k] = a[i];i--;k--;
	//~ }
}


void print(vector<int> & v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> a = {1, 2, 4, 7, 9, 12};
	int n = a.size();
	vector<int> b = {-1, 3, 4, 6, 8, 9, 13};
	a.resize(20);
	
	sortedMerge(a, n, b);
	print(a);
	
	vector<int> c = {1, 2, 4, 7, 9, 12};
	int m = c.size();
	vector<int> d = {10, 11, 12, 13, 18, 19};
	c.resize(20);
	
	sortedMerge(c, m, d);
	print(c);
}
