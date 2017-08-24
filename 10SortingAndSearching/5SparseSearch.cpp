#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* Sparse Search: Given a sorted array of strings that is interspersed with empty strings, write a
method to find the location of a given string. */

#define cn(x) cout << #x << " = " << x << endl;



int sparseSearch(vector<string> & v, string x, int left, int right){
	if(left > right) return -1;
	int mid = (left+right)/2;
	if(v[mid]==""){
		int ans = sparseSearch(v,x,left,mid-1);
		return (ans!=-1) ? ans : sparseSearch(v,x,mid+1,right);
	}else if(x < v[mid]){
		return sparseSearch(v,x,left,mid-1);
	}else if(v[mid] < x){
		return sparseSearch(v,x,mid+1,right);
	}else{
		return mid;
	}
}


int sparseSearch(vector<string> & v, string x){
	return sparseSearch(v, x, 0, v.size()-1);
}

int main(){
	vector<string> v = {"at", "", "", "", "ball", "", "", "car", "", "","dad", ""};
	string x = "ball";
	cout << sparseSearch(v, x) << endl;//Output:4
	x = "pepe";
	cout << sparseSearch(v, x) << endl;//Output:-1
	x = "dad";
	cout << sparseSearch(v, x) << endl;//Output:10
}

