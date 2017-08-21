#include <vector>
#include <iostream>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

void merge(vector<int> & v, vector<int> & w, int lstart, int lend, int rstart, int rend){
	int i = lstart;
	int j = rstart;
	int k = lstart;
	
	while(i <= lend && j <= rend){
		if(v[i] < v[j]){
			w[k] = v[i];
			i++;
		}else{
			w[k] = v[j];
			j++;
		}
		if(lstart == 0 && rend == 4){
			cout << k << " ";cn(w[k])
		}
		k++;
	}
	
	while(i <= lend){
		w[k] = v[i];
		k++; i++;
	}
	
	while(j <= rend){
		w[k] = v[j];
		k++; j++;
	}
	
	for(int i = lstart; i <= rend; i++)
		v[i] = w[i];
}



void mergeSort(vector<int> &v, vector<int> & w, int start, int end){
	if(start >= end) return;
	
	int mid = (start + end) / 2;
	mergeSort(v, w, start, mid);
	mergeSort(v, w, mid+1, end);
	merge(v, w, start, mid, mid+1, end);
}


void mergeSort(vector<int> & v){
	int n = v.size();
	vector<int> w(n);
	mergeSort(v, w, 0, n-1);
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
	int k = 0;
	while(k < t){
		cin >> n;
		vector<int> v;
		v.resize(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		cout << "original = ";print(v);
		mergeSort(v);
		cout << "ordenado = ";print(v);	
		
		k++;
	}
	return 0;
}
