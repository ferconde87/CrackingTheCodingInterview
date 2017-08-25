#include <iostream>
#include <vector>

using namespace std;


void printAllDuplicates(vector<int> & v){
	vector<int> memo(1000, 0);
	for(int x : v){
		int rem = ((x-1)%32);
		int mask = 1 << rem;
		int i = (x-1)/32;
		if((memo[i] & mask) != 0){
			cout << x << endl;;
		}else{
			memo[i] |= mask;
		}			
	}
}


//CTCI
class BitSet{
	private:
		vector<int> bitset;
	public:
		BitSet(int size){
			bitset.resize(((size-1) >> 5)+1);
		}
		bool get(int pos){
			int wordNumber = ((pos-1) >> 5); //divide by 32
			int bitNumber = ((pos-1) & 0x1F); // mod 32;
			return (bitset[wordNumber] & (1 << bitNumber)) != 0;
		}
		void set(int pos){
			int wordNumber = ((pos-1) >> 5);
			int bitNumber = ((pos-1) & 0x1F);
			bitset[wordNumber] |= (1 << bitNumber);
		}
};

void checkDuplicates(vector<int> & v){
	BitSet * bs = new BitSet(32000);
	for(int i = 0; i < v.size(); i++){
		int num = v[i];
		if(bs->get(num)){
			cout << num << endl;
		}else{
			bs->set(num);
		}
	}
}


int main(){
	vector<int> v = {4,2,5,2,4,6,3,3,1,9,7,11,12,14,15,16,12,17,29,38,29,192,32,293,349,123,24,34,54,65,764,35,64,34,23,645,3,345};
	
	printAllDuplicates(v);//2 4 3 12 29 34 3
	
	checkDuplicates(v);
}
