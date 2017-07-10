/*
 * String Rotation:Assumeyou have a method isSubstringwhich checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool stringRotation(string s1, string s2){
	int n = s1.size();
	if(n!=s2.size()) return false;
	int i = 0;
	int j = 0;
	while(j < n){
		if(s1[i]==s2[j])
			i++;
		else
			i=0;
		j++;
	}
	j = 0;
	while(i < n && s1[i]==s2[j]){
		i++;j++;
	}
	return i==n;
}

int main(){
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	cout << stringRotation(s1, s2) << endl;
	s1 = "waterbottle";
	s2 = "erbottlewa";
	cout << stringRotation(s1, s2) << endl;
	s1 = "waterwawat";
	s2 = "wawatwater";
	cout << stringRotation(s1, s2) << endl;
	s1 = "waterwawat";
	s2 = "waterwawaa";
	cout << stringRotation(s1, s2) << endl;
	return 0;
}
