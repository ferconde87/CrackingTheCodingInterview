#include <iostream>

using namespace std;

#define NAME_SIZE 50 // Defines a macro

class Person{
	const int id; // all members are private bu default
	char name[NAME_SIZE];
	public:
		Person(int a) : id(a){
			
		}
		~Person(){
			cout << "Deleting...";
		}
		void aboutMe(){
			cout << "I am a person.";
		}
};



int main(){

	Person * p = new Person(1);
	p->aboutMe();
	delete p;
	return 0;
}
