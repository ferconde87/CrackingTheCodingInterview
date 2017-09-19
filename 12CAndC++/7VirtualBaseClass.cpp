#include <iostream>

using namespace std;

class Foo{
	public:
		void f(){
			cout << "I'm f from Foo" << endl;
		}
		virtual void g(){
			cout << "I'm g from Foo" << endl;
		}
		virtual void h(){
			cout << "I'm h from Foo" << endl;
		}
		virtual ~Foo(){
			cout << "Foo's destructor" << endl;
		}
};

class Bar : public Foo{
	public:
		void f(){
			cout << "I'm f from Bar" << endl;
		}
		void g(){
			cout << "I'm g from Bar" << endl;
		}
		~Bar(){
			cout << "Bar's destructor" << endl;
		}
};

/* Why does a destructor in base class need to be declared virtual?
 * Destructors are used to clean up memory and resources. If Foo's
destructor were not virtual, then Foo's destructor would be called, even when pis really of type Bar.
This is why we declare destructors to be virtual; we want to ensure that the destructor for the most derived
class is called. */

void function(){
	Foo * q;
	Foo * p = new Bar();
	p->f();//To ensure that p->f() will invoke the most derived implementation off (), we need to declare f () to be
		   //a virtual function.
	p->g();
	p->h();
	delete p;
}

int main(){
	function();
}
