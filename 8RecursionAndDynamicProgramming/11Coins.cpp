#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <set>
#include <stack>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/* Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and
pennies (1 cent), write code to calculate the number of ways of representing n cents.*/

int coins(int n, vector<int> & currency, int index){
	if(index == currency.size()-1) return 1;
	int coin = currency[index];
	int ans = 0;
	for(int i = 0; i * coin <= n; i++){
		int rem = n - (i * coin);
		ans += coins(rem, currency, index+1);
	}
	return ans;
}
//~ 
int coins(int n, vector<int> & currency){
	int index = 0;
	return coins(n, currency, index);
}


//////
int coins2(int n, int lastCoinUsed){
	if(n < 0) return 0;
	if(n == 0) return 1;
	int ans = 0;
	if(lastCoinUsed == 25)
		ans += coins2(n-25, 25);
	if(lastCoinUsed >= 10)
		ans += coins2(n-10, 10);
	if(lastCoinUsed >= 5)
		ans += coins2(n-5, 5);
	if(lastCoinUsed >= 1)
		ans += coins2(n-1, 1);
	return ans;
}

int coins2(int n){
	int lastCoinUsed = 25;
	return coins2(n, 25);
}


/// version with memoization
int makeChange(int amount, vector<int> & denoms, int index, vector<vector<int > > & m){
	if(m[amount][index] > 0){
		return m[amount][index];
	}
	if(index == denoms.size()-1) return 1;
	int denomAmount = denoms[index];
	int ways = 0;
	for(int i = 0; i * denomAmount <= amount; i++){
		int amountRemaining = amount - i * denomAmount;
		ways += makeChange(amountRemaining, denoms, index+1, m);
	}
	m[amount][index] = ways;
	return ways;
}


int makeChange(int amount){
	vector<int> denoms = {25, 10, 5, 1};
	vector<vector<int> > m(amount+1, vector<int>(denoms.size(), 0));
	return makeChange(amount, denoms, 0, m);
}

int main(){
	
	vector<int> currency = {25, 10, 5, 1};//en orden descendente para no repetir casos
	
	cout << 1 << " = " << coins(1, currency) << endl;
	cout << 5 << " = " << coins(5, currency) << endl;
	cout << 6 << " = " << coins(6, currency) << endl;
	cout << 10 <<" = " << coins(10, currency) << endl;
	cout << 25 <<" = " << coins(25, currency) << endl;
	cout << 1 << " = " << coins2(1) << endl;
	cout << 5 << " = " << coins2(5) << endl;
	cout << 6 << " = " << coins2(6) << endl;
	cout << 10 << " = " << coins2(10) << endl;
	cout << 25 << " = " << coins2(25) << endl;
	cout << "with memoization" << endl;
	cout << makeChange(1) << endl;
	cout << makeChange(5) << endl;
	cout << makeChange(6) << endl;
	cout << makeChange(10) << endl;
	cout << makeChange(25) << endl;
	
	return 0;
}

