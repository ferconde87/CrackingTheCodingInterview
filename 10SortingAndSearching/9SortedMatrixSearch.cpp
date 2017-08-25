#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define cn(x) cout << #x << "= " << x << endl;

int findInRow(vector<vector<int> > & m, int x, int col, int left, int right){
	if(left > right) return -1;
	int mid = (left+right)/2;
	if(x < m[mid][col]){
		return findInRow(m, x, col, left, mid-1);
	}else if(m[mid][col] < x){
		return findInRow(m, x, col, mid+1, right);
	}else{
		return mid;
	}
}

pair<int, int> findByRows(vector<vector<int> > & m, int x, int rows, int cols){
	for(int j = 0; j < cols; j++){
		int i = findInRow(m, x, j, 0, rows-1);
		if(i!=-1){
			return make_pair(i, j);
		}
	}
	return make_pair(-1,-1);
}


int findInColumn(vector<vector<int> > & m, int x, int row, int left, int right){
	if(left > right) return -1;
	int mid = (left+right)/2;
	if(x < m[row][mid]){
		return findInColumn(m, x, row, left, mid-1);
	}else if(m[row][mid] < x){
		return findInColumn(m, x, row, mid+1, right);
	}else{
		return mid;
	}
}

pair<int, int> findByColumns(vector<vector<int> > & m, int x, int rows, int cols){
	for(int i = 0; i < rows; i++){
		int j = findInColumn(m, x, i, 0, cols-1);
		if(j!=-1){
			return make_pair(i, j);
		}
	}
	return make_pair(-1,-1);
}

pair<int, int> find(vector<vector<int> > & matrix, int x){
	int rows = matrix.size();//
	if(rows == 0) return make_pair(-1,-1);
	int cols = matrix[0].size();
	if(rows < cols){
		return findByColumns(matrix, x, rows, cols);
	}else{
		return findByRows(matrix, x, rows, cols);
	}
}

int main(){
	int n, m, elem;
	cin >> n >> m >> elem;
	vector<vector<int> > matrix(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	pair<int, int > res = find(matrix, elem);
	cout << res.first << " " << res.second << endl;
	
	//~ res = find(matrix, 9);
	//~ cout << res.first << " " << res.second << endl;
	//~ res = find(matrix, 12);
	//~ cout << res.first << " " << res.second << endl;
	//~ res = find(matrix, 13);
	//~ cout << res.first << " " << res.second << endl;
}

