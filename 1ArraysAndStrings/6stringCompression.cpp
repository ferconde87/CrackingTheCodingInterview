/*
 * String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
*/

#include <iostream>
#include <string>

using namespace std;


string compression(string & s){
	string result;
	int n = s.size();
	if(n<=1) return s;
	int count = 1;
	char elem = s[0];
	string number;
	for(int i = 1; i < n; i++){
		if(elem!=s[i]){
			result.push_back(elem);
			number = to_string(count);
			result.append(number);
			count = 1;
			elem = s[i];
		}else{
			count++;
		}
	}
	result.push_back(elem);
	number = to_string(count);
	result.append(number);
	if(result.size()>n)
		return s;
	return result;
}


int main(){
	
	string s;
	s = "aabcccccaaa";
	cout << compression(s) << endl;

}
