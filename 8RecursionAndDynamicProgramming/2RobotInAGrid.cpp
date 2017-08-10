#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector< vi >
#define v(t) vector<t>
#define VV(t) vector< v(t) > 
#define CYESNO(x) cout << (x ? "YES" : "NO") << endl;

using namespace std;

bool isOffLimit(int x){
	return x!=0;
}

//Complejidad temporal O(2^{n*m}) , Complejidad espacial O(n*m)
bool RobotInAGrid(vvi & vv, int i, int j, int n, int m){
	if(i > n || j > m) return false;
	if(i == n && j == m) return true;
	if(isOffLimit(vv[i][j])) return false;
	return RobotInAGrid(vv, i+1, j, n, m) || RobotInAGrid(vv, i, j+1, n, m);
}


bool RobotInAGrid(vvi & vv, int n, int m){
	return RobotInAGrid(vv, 0, 0, n-1, m-1); 
}

//TopDown
//Complejidad temporal O(n * m) , Complejidad espacial O(n*m)
bool RobotInAGridDP(vvi & vv, vvi & memo, int i, int j, int n, int m){
	if(i > n || j > m) return 0;
	if(i == n && j == m){
		return 1;
	} 
	if(memo[i][j] != -1) return memo[i][j];
	if(isOffLimit(vv[i][j])){
		memo[i][j] = 0;
	}else{
		memo[i][j] = RobotInAGridDP(vv, memo, i+1, j, n, m) || RobotInAGridDP(vv, memo, i, j+1, n, m);
	}
	return memo[i][j];
}


bool RobotInAGridDP(vvi & vv, int n, int m){
	vvi memo(n, vi(m, -1));
	return RobotInAGridDP(vv, memo, 0, 0, n-1, m-1);
}

//Bottom Up
bool RobotInAGridBottomUp(vvi & vv, int n, int m){
	vvi memo(n, vi(m, -1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(isOffLimit(vv[i][j])){
				memo[i][j] = 0;
			}else{
				memo[i][j] = (i != 0 && memo[i-1][j]) || (j != 0 && memo[i][j-1]) || (i == 0 && j == 0);
			}
		}
	}
	return memo[n-1][m-1];
}

//Bottom Up usando solo un vector como memo
bool RobotInAGridBottomUpFun(vvi & vv, int n, int m){
	vi memo(m, -1);//just for fun
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(isOffLimit(vv[i][j])){
				memo[j] = 0;
			}else{
				memo[j] = (i != 0 && memo[j]) || (j != 0 && memo[j-1]) || (i == 0 && j == 0);
			}
		}
	}
	return memo[m-1];
}

void print(vvi & vv, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << vv[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){
	
	int n, m;
	cin >> n >> m;
	vvi vv(n, vi(m, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> vv[i][j];
	
	CYESNO(RobotInAGrid(vv, n, m))
	CYESNO(RobotInAGridDP(vv, n, m))
	CYESNO(RobotInAGridBottomUp(vv, n, m))
	CYESNO(RobotInAGridBottomUpFun(vv, n, m))
	
	return 0;
}

