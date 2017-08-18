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

/*Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
of n pairs of parentheses.*/

void print(vector<string> & vs){
	for(string s : vs){
		cout << s << " ";
	}
	cout << endl;
}

vector<string> parens(int n){
	vector<string> ans;
	if(n==1){
		string initial = "()";
		ans.push_back(initial);
		return ans;
	}
	ans = parens(n-1);
	vector<string> copy(ans);
	ans.clear();
	stack<char> stack;
	for(string xs : copy){
		string pair = "()";
		if(xs[1] == '('){
			string temp = xs;
			temp.insert(0, "()");
			ans.push_back(temp);
		}
		int i = 0;
		int n = xs.size();
		for(i = 1; i < n; i++){
			string temp = xs;
			stack.push(xs[i]);
			while(!stack.empty()){
				if(xs[i]==')') stack.pop();
				else stack.push(xs[i]);
				i++;
			}
			if(i == n || (i < n-1 && xs[i+1]=='(')){
				temp.insert(i, "()");
				ans.push_back(temp);
			}
		}
	}
	for(string xs : copy){
		string temp = xs;
		temp.insert(0,"(");
		temp.insert(xs.size(),")");
		ans.push_back(temp);
	}
	return ans;
}


int main(){	

	auto ans = parens(1);
	print(ans);
	ans = parens(2);
	print(ans);
	ans = parens(3);
	print(ans);
	ans = parens(4);
	print(ans);
	
	return 0;
}

