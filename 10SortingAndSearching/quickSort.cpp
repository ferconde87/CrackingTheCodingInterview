#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int partition(vector<int> & v, int left, int right){
	int pivot = v[(left + right) / 2];
	while(left <= right){
		//Find element on the left that should be on right
		while(v[left] < pivot) left++;
		//Find element on the right that should be on left
		while(v[right] > pivot) right--;
		
		//Swap elements, and move left and right indices
		if(left <= right){
			swap(v[left], v[right]);
			left++;
			right--;
		}	
	}
	return left;	
}

void quickSort(vector<int> & v, int left, int right){
	int index = partition(v, left, right);
	if(left < index-1){
		quickSort(v, left, index-1);
	}
	if(index < right){
		quickSort(v, index, right);
	}
}

void quickSort(vector<int> & v){
	quickSort(v, 0, v.size()-1);
}

void print(vector<int> & v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}


int main(){
	int t;
	cin >> t;
	int n;
	for(int i = 0; i < t; i++){
		cin >> n;
		vector<int> v(n);
		for(int j = 0; j < n; j++){
			cin >> v[j];
		}
		cout << "original = ";print(v);
		quickSort(v);
		cout << "ordenado = ";print(v);		
	}
}
