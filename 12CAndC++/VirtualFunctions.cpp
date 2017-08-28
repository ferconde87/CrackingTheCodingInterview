#include <iostream>

using namespace std;

#define NAME_SIZE 50 // Defines a macro

//~ class Person{
	//~ int id; // all members are private bu default
	//~ char name[NAME_SIZE];

	//~ public:
		//~ void aboutMe(){
			//~ cout << "I am a person.";
		//~ }
//~ };

//~ class Student : public Person{
	//~ public:
		//~ void aboutMe(){
			//~ cout << "I am a student.";
		//~ }
//~ };


//~ int main(){
	//~ Person * p = new Student();
	//~ p->aboutMe(); // prints "I am a person."
	//~ /* In this case, "I am a person." would be printed instead. This is because the function aboutMe is resolved
	   //~ at compile-time, in a mechanism known as static binding */
	//~ delete p;
	//~ return 0;
//~ }

class Person{
	int id; // all members are private bu default
	char name[NAME_SIZE];

	public:
	/* by defining addCourse to be a "pure virtual function;· Person is now an abstract class and we
	   cannot instantiate it */
	virtual void aboutMe(){
		cout << "I am a person.";
	}
	virtual bool addCourse(string s) = 0;//the imple­mentation being left to the subclass.
};

class Student : public Person{
	public:
	void aboutMe(){
		cout << "I am a student.";
	}
	
	bool addCourse(string s){
		cout << "Added course " << s << " to student." << endl;
		return true; 
	}
};

//~ class Teacher : public Person{
	//~ public:
	//~ void aboutMe(){
		//~ cout << "I am a teacher.";
	//~ }
//~ }


int main(){
	Person * p = new Student();
	p->aboutMe(); // prints "I am a student."
	p->addCourse("History");
	delete p;
	//~ Person * t = new Teacher();
	//~ t->aboutMe();
	//~ delete t;
	return 0;
}
