#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << "= " << x << endl;

struct {
	bool operator()(int l, int r) const {
		return l > r;
	}
} Compare;

//usando min-heap y max-heap (just 4 fun) 
//por el loop que hace n veces pop_heap: O(n log n)
vector<int> peaksAndValley(vector<int> & v){
	vector<int> maxHeap(v);
	make_heap(maxHeap.begin(), maxHeap.end());
	vector<int> minHeap(v);
	make_heap(minHeap.begin(), minHeap.end(), Compare);
	int n = v.size();
	vector<int> ans(n);
	int i = 0;
	int k = 0;
	while(k < n){
		ans[k++] = maxHeap.front();
		pop_heap(maxHeap.begin(), maxHeap.end()-i);
		if(k==n) break;
		ans[k++] = minHeap.front();
		pop_heap(minHeap.begin(), minHeap.end()-i, Compare);
		i++;
	}
	return ans;
}

//vector: O(n log n) por el sort
vector<int> peaksAndValley2(vector<int> & v){
	int n = v.size();
	sort(v.begin(), v.end());
	vector<int> res(n);
	int i = 0;
	int k = 0;
	while(k < n){
		res[k++] = v[n-1-i];
		if(k==n)break;
		res[k++] = v[i];
		i++;
	}
	return res;
}

//TODO solución en O(N) donde solo se modifique un peak o se cree un peak
//123 / => \/ 213-//
//----------------//
//321 \ => /\ 231-//
//----------------//
//213 \/ => /\ 231//
//----------------//
//132 /\ => \/ 312//

void print(vector<int> & v){
	for(int x : v) cout << x << " ";cout << endl;
}

int main(){
	vector<int> v = {5,3,1,2,3};
	vector<int> ans = peaksAndValley(v);
	print(ans);
	ans = peaksAndValley2(v);
	print(ans);
}

