#include <iostream>

using namespace std;

/* Smart Pointer: Write a smart pointer class. A smart pointer is a data type, usually implemented with
templates, that simulates a pointer while also providing automatic garbage collection. It automati­
cally counts the number of references to a SmartPointer<T*> object and frees the object of type
T when the reference count hits zero. */

/// BORRADOR (!)
//~ template <class T>
//~ class SmartPointer{
	//~ T * obj;
	//~ unsigned * ref_count;
	//~ SmartPointer(T * obj){
		//~ //set de value (this->obj = obj)
		//~ //set ref_count = 1
	//~ }
	//~ 
	//~ SmartPointer(SmartPointer<T> & sptr){
		//~ //create a smart pointer that points to an existing object
		//~ //set obj & ref_count to pointer to sptr.obj & sptr.ref_count'
	//~ }
	//~ 
	//~ ~SmartPointer(SmartPointer<T> sptr){
		//~ //destroy reference sptr & decrement ref_count
		//~ //(!) if ref_count == 0 then free memory
	//~ }
	//~ 
	//~ // operator =
	//~ void onSetEquals(SmartPointer<T> prt1, SmartPointer<T> prt2){
		//~ //ptr1 = prt2
		//~ //if prt1 has an existing value, decrement its ref_count
		//~ //then prt1.obj = prt2.obj
		//~ //and prt1.ref_count = prt2.ref_count
	//~ }
//~ }

template <class T>
class SmartPointer{
	protected:
	T * ref;
	unsigned * ref_count;
	void remove(){
		(*ref_count)--;
		if(*ref_count == 0){
			delete ref;
			free(ref_count);
			ref = NULL;
			ref_count = NULL;
		}
	}
	
	public:
	SmartPointer(T * ref){
		this.ref = ref;
		*ref_count = 1;
	}
	
	SmartPointer(SmartPointer<T> & sptr){
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}
	
	~SmartPointer(){
		remove();
	}
	
	SmartPointer<T> & operator=(SmartPointer<T> & sptr){
		if(this == sptr) return this;
		
		if(*ref_count > 0){
			remove();
		}
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
		return this;
	}
	
	T getValue(){
		return *ref;
	}
};

int main(){
	
	
}
