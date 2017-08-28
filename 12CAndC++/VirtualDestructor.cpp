
#include <iostream>

using namespace std;

#define NAME_SIZE 50

class Person{
	int id; 
	char name[NAME_SIZE];
	virtual ~Person(){
		cout << "Deleting a person." << endl;
	}
};

class Student : public Person{
	public:
	~Student(){
		cout << "Deleting a student." << endl;
	}	
};

int main(){
	Person * p = new Student();
	delete p;
	return 0;
}
