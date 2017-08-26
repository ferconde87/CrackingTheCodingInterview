#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define cn(x) cout << #x << "= " << x << endl;

//1) using min-heap ... 
//armar el Ranker O(N*log(N))
//getRankOfNumber O(1)
// pero está soluciono no permite nuevos insert
struct {
	bool operator()(int l, int r) const {
		return l > r;
	}
} Compare;

class Ranker{
	unordered_map<int, int> map;
	public:
		Ranker(unordered_map<int, int> & map){
			this->map = map;
		}
		int getRankOfNumber(int i){
			return map[i];
		}
};

Ranker * rankFromStream2(vector<int> & v){
	int n = v.size();
	if(n==0) return NULL;
	unordered_map<int, int> map;
	sort(v.begin(), v.end(), Compare);
	int last = 0;
	for(int i = n-1; i >= 0; i--){
		map[v[i]] = last++;
	}
	Ranker * ranker = new Ranker(map);
	return ranker;
}

Ranker * rankFromStream(vector<int> & v){
	int n = v.size();
	if(n==0) return NULL;
	unordered_map<int, int> map;
	make_heap(v.begin(), v.end(), Compare);
	int last = 0;
	for(int i = n-1; i >= 0; i--){
		map[v.front()] = last++;
		pop_heap(v.begin(), v.begin()+i, Compare);
	}
	Ranker * ranker = new Ranker(map);
	return ranker;
}

//2)CTCI
//insert O(log N)
//getRankOfNumber O(log N)
class RankNode{
	int left_size = 0;
	RankNode * left;
	RankNode * right;
	int data;
	public:
		RankNode(int d){
			data = d;
		}
		void insert(int d){
			if(d <= data){
				if(left != NULL) left->insert(d);
				else left = new RankNode(d);	
				left_size++;
			}else{
				if(right != NULL) right->insert(d);
				else right = new RankNode(d);
			}
		}
		int getRank(int d){
			if(d == data){
				return left_size;
			}else if(d <data){
				if(left == NULL) return -1;
				else return left->getRank(d);
			}else{
				int right_rank = (right == NULL) ? -1 : right->getRank(d);
				if(right_rank == -1) return -1;
				else return left_size + 1 + right_rank;
			}
		}
		int getRankOfNumber(int number){
			return getRank(number);
		}
		void track(int number){
			this->insert(number);
		}
};


int main(){
	vector<int> v = {5,1,4,4,5,9,7,13,3};
	Ranker * r = rankFromStream(v);
	cout << "rankFromStream" << endl;
	cout << r->getRankOfNumber(1) << endl;
	cout << r->getRankOfNumber(3) << endl;
	cout << r->getRankOfNumber(4) << endl;
	cout << r->getRankOfNumber(13) << endl;
	cout << "rankFromStream2" << endl;
	r = rankFromStream2(v);
	cout << r->getRankOfNumber(1) << endl;
	cout << r->getRankOfNumber(3) << endl;
	cout << r->getRankOfNumber(4) << endl;
	cout << r->getRankOfNumber(13) << endl;
	cout << "rankFromStreamCTCI" << endl;
	RankNode * root = new RankNode(v[0]);
	for(int i = 1; i < v.size(); i++){
		root->track(v[i]);
	}	
	cout << root->getRankOfNumber(1) << endl;
	cout << root->getRankOfNumber(3) << endl;
	cout << root->getRankOfNumber(4) << endl;
	cout << root->getRankOfNumber(13) << endl;
}

