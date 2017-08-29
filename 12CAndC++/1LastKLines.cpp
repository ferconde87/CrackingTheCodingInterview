#include <iostream>
#include <fstream>
#include <queue>

using namespace std;


void lastKLines(){
	string line;
	int k;
	string namefile;
	cin >> k;
	cin >> namefile;
	ifstream fileToRead (namefile);
	if (fileToRead.is_open()){
		queue<string> q;
		int i = 0;
		while (getline(fileToRead,line) && i < k){
		  q.push(line);
		  i++;
		}
		while(getline(fileToRead, line)){
			q.pop();
			q.push(line);
		}
		fileToRead.close();
		while(!q.empty()){
			cout << q.front() << endl;
			q.pop();
		}
	}else{
	   cout << "Error: Unable to open file" << endl;
	}
}


int main(){
	lastKLines();
}
