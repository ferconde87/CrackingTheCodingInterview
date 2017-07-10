/*Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;


void zeroMatrix(vector< vector <int > > & m){
	vector< pair<int, int> > v;
	int rows = m.size();
	if(rows==0)return;
	int cols = m[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(m[i][j]==0){
				pair<int, int> p = make_pair(i,j);
				v.push_back(p);
			}
		}
	}
	for(int k = 0; k < v.size(); k++){
		int i = v[k].first;
		for(int j = 0; j < cols; j++){
			m[i][j] = 0;
		}
		int j = v[k].second;
		for(int i = 0; i < rows; i++){
			m[i][j] = 0;
		}
	} 
}


//O(1) complejidad espacial
//tendría que ver que min no sea el último minimo
//y que si ese es el caso que el número min-1 (que va a dar overflow) no esté en la matrix
void zeroMatrix2(vector< vector <int > > & m){
	int rows = m.size();
	if(rows==0)return;
	int cols = m[0].size();
	int min = m[0][0];
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(m[i][j] < min)
				min = m[i][j];
				
	int specialMark = (min == 1) ? -1 : min-1;//otherwise we put 0 as a special mark ^^
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(m[i][j] == 0)
				m[i][j] = specialMark;
				
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(m[i][j] == specialMark){
				for(int k = 0; k < rows; k++){
					if(m[k][j]!=specialMark)
						m[k][j] = 0;
				}
				for(int k = 0; k < cols; k++)
					if(m[i][k]!=specialMark)
						m[i][k] = 0;
			}
		}
	}

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(m[i][j] == specialMark)
				m[i][j] = 0;		
}


int main(){
	int n, m;
	cin >> n >> m;
	vector< vector <int > > matrix(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> matrix[i][j];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	
	zeroMatrix2(matrix);
			
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	
}
