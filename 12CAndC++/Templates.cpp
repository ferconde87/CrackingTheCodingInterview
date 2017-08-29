#include <iostream>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

template <class T>
class ShiftedList{
	T * array;
	int offset, size;
	public:
	ShiftedList(int sz) : offset(0), size(sz) {
		array = new T[size];
	}
	~ShiftedList(){
		delete [] array;
	}
	void shiftBy(int n){
		offset = (offset + n) % size;
	}
	T getAt(int i){
		return array[convertIndex(i)];
	}
	T setAt(T item, int i){
		array[convertIndex(i)] = item;
	}
	private:
	int convertIndex(int i){
		int index = (i-offset) % size;
		cn(i)cn(index)
		while(index < 0) index += size;
		return index;
	}
};


int main(){
	ShiftedList<int> * shiftedList = new ShiftedList<int>(5);
	shiftedList->setAt(0,0);
	shiftedList->setAt(1,1);
	shiftedList->setAt(2,2);
	shiftedList->setAt(3,3);
	shiftedList->setAt(4,4);
	shiftedList->shiftBy(2);
	cn(shiftedList->getAt(0));
	cn(shiftedList->getAt(1));
	cn(shiftedList->getAt(2));
	cn(shiftedList->getAt(3));
	cn(shiftedList->getAt(4));
	
}
