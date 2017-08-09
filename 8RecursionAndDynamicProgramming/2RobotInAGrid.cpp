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
int RobotInAGridDP(vvi & vv, vvi & memo, int i, int j, int n, int m){
	if(i > n || j > m) return 0;
	if(i == n && j == m){
		memo[i][j] = 1;
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
	
	return 0;
}

