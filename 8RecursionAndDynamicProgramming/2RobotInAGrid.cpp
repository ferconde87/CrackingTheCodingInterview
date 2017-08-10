#include <iostream>
#include <vector>
#include <locale>

#define vi vector<int>
#define vvi vector< vi >
#define v(t) vector<t>
#define VV(t) vector< v(t) > 
#define CYESNO(x) cout << (x ? "YES" : "NO") << endl;

using namespace std;

void print(vvi & vv, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << vv[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

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

//BottomUp
//Complejidad temporal O(n * m) , Complejidad espacial O(n*m)
bool RobotInAGridDP(vvi & vv, vvi & memo, int i, int j, int n, int m){
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
	
	//cout << "(" << i << "," << j << ") =" << memo[i][j] << endl;
	
	return memo[i][j];
}


bool RobotInAGridDP(vvi & vv, int n, int m){
	vvi memo(n, vi(m, -1));
	bool ans = RobotInAGridDP(vv, memo, 0, 0, n-1, m-1);
	return ans;
}

//TopDown returning the path
//Complejidad temporal O(n * m) , Complejidad espacial O(n*m)
int RobotInAGridDPWithPath(vvi & vv, vvi & memo, int i, int j, int n, int m){
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

//asume que hay efectivamente un camino de (n-1, m-1) a (0,0)
vector<pair<int, int> > getPath(vvi & memo, int n, int m){
	vector<pair< int, int> > ans;
	int i = n-1;
	int j = m-1;
	while(i >= 0 && j >= 0){
		ans.push_back(make_pair(i,j));
		if(memo[i][j-1] == 1){
			j--;	
		}else{
			i--;
		}
	}
	return ans;
}

vector<pair<int, int> > RobotInAGridDPWithPath(vvi & vv, int n, int m){
	vector<pair<int, int> > ans;
	vvi memo(n, vi(m, -1));
	int isPath = RobotInAGridDP(vv, memo, 0, 0, n-1, m-1);
	print(memo, n, m);
	if(isPath)
		ans = getPath(memo, n, m);
	return ans;
}

//Iterativo
bool RobotInAGridIterative(vvi & vv, int n, int m){
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

//Iterativo usando solo un vector como memo
bool RobotInAGridIterativeFun(vvi & vv, int n, int m){
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


void printPath(vector<pair<int, int> > & path){
	for(auto p : path)
		cout << "(" << p.first << "," << p.second << ") ";
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
	CYESNO(RobotInAGridIterative(vv, n, m))
	CYESNO(RobotInAGridIterativeFun(vv, n, m))
	cout << endl;
	vector<pair<int, int> > pair = RobotInAGridDPWithPath(vv, n, m);
	printPath(pair);
	
	return 0;
}

