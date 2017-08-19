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

//quisé construir por casos, no genera todos los casos y repite alguno y se olvida de otro
//ejemplo... no genera (())(()) ... ver solución CTCI
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

/////////////////////////////CTCI
void addParen(vector<string> & v, int leftRem, int rightRem, string str, int index){
	if(leftRem < 0 || rightRem < leftRem) return; //invalid state

	if(leftRem == 0 && rightRem == 0){
		v.push_back(str);
	}else{
		str[index] = '(';// Add left and recurse
		addParen(v, leftRem-1, rightRem, str, index + 1);
		
		str[index] = ')';
		addParen(v, leftRem, rightRem - 1, str, index + 1);
	}
}

vector<string> generateParens(int count){
	string str;
	str.resize(count*2);
	vector<string> v;
	addParen(v, count, count, str, 0);
	return v;
}


/////////////////////////////mi versión similar a CTCI
void addParen2(vector<string> & v, int leftRem, int rightRem, string str){
	if(leftRem < 0 || rightRem < leftRem) return; //invalid state
	
	if(leftRem == 0 && rightRem == 0){
		v.push_back(str);
	}else{
		if(leftRem > 0){
			str.push_back('(');// Add left and recurse
			addParen2(v, leftRem-1, rightRem, str);
		}
		if(rightRem > 0){
			str.push_back(')');
			addParen2(v, leftRem, rightRem - 1, str);
		}
	}
}

vector<string> generateParens2(int count){
	string str;
	vector<string> v;
	addParen2(v, count, count, str);
	return v;
}


int main(){	

	//parens no OK
	auto ans = parens(1);
	print(ans);
	ans = parens(2);
	print(ans);
	ans = parens(3);
	print(ans);
	ans = parens(4);
	print(ans);
	ans = parens(5);
	print(ans);	
	cout << endl;
	
	ans = generateParens(1);
	print(ans);
	ans = generateParens(2);
	print(ans);
	ans = generateParens(3);
	print(ans);
	ans = generateParens(4);
	print(ans);
	ans = generateParens(5);
	print(ans);	
	cout << endl;
	
	ans = generateParens2(1);
	print(ans);
	ans = generateParens2(2);
	print(ans);
	ans = generateParens2(3);
	print(ans);
	ans = generateParens2(4);
	print(ans);
	ans = generateParens2(5);
	print(ans);	
	
	return 0;
}

