#include <iostream>
#include <vector>

using namespace std;

vector< vector <int> > getRotateMatrix(vector< vector<int> > & m){
	int rows = m.size();
	if(rows==0) return m;
	int cols = m[0].size();
	if(cols == 0) return m;
	vector< vector <int> > result(cols, vector<int>(rows));
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result[j][rows-i-1] = m[i][j];
		}
	}
	return result;
}

void rotateMatrix(vector< vector<int> > & m){
	int rows = m.size();
	if(rows==0) return;
	int cols = m[0].size();
	if(cols == 0) return;
	
	vector< vector <int> > result(cols, vector<int>(rows, 0));
	int mid = rows/2;
	for(int i = 0; i < mid; i++){
		for(int j = i; j < cols-i-1; j++){
			int temp1 = m[j][rows-i-1];
			m[j][rows-i-1] = m[i][j];
			int temp2 = m[rows-i-1][cols-j-1];
			m[rows-i-1][cols-j-1] = temp1;
			int temp3 = m[cols-j-1][i];
			m[cols-j-1][i] = temp2;
			m[i][j] = temp3;
		}
	}
}

//igual que rotateMatrix con reordenamiento de las instrucciones (más prolijo quizá)
void rotateMatrix2(vector< vector<int> > & m){
	int rows = m.size();
	if(rows==0) return;
	int cols = m[0].size();
	if(cols == 0) return;
	
	vector< vector <int> > result(cols, vector<int>(rows, 0));
	int mid = rows/2;
	for(int i = 0; i < mid; i++){
		for(int j = i; j < cols-i-1; j++){
			int temp1 = m[j][rows-i-1];
			int temp2 = m[rows-i-1][cols-j-1];
			int temp3 = m[cols-j-1][i];
			m[j][rows-i-1] = m[i][j];
			m[rows-i-1][cols-j-1] = temp1;
			m[cols-j-1][i] = temp2;
			m[i][j] = temp3;
		}
	}
}

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	vector< vector <int > > matrix(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> matrix[i][j];
	
	vector< vector<int > > result = getRotateMatrix(matrix);
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	rotateMatrix(matrix);
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
