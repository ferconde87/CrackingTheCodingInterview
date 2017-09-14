#include <iostream>

using namespace std;


class Shape{
	public:
	int edge_length;
	virtual int circumference(){
		cout << "Circumference of the Base Class \n";
	}
};

class Triangle : public Shape{
	public:
	virtual int circumference(){
		cout << "Circumference of the Triangle Class \n";
		return 3 * edge_length;
	}
};

class Square :public Shape{
	public:
};


int main(){
	Shape * x = new Shape();
	x->circumference();
	Shape * y = new Triangle();
	y->circumference();
	Shape * z = new Square();
	z->circumference();
}
