#include <iostream>
#include <queue>

using namespace std;

struct comparator{
	bool operator()(int i,int j){
		return i>j;
	}
};
int main(){
	priority_queue<int, std::vector<int>, comparator>minHeap;
	int n;
	cin >> n;
	for(int i=1;i<n;i++){ minHeap.push(i); }
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> val;
		
	while(!minHeap.empty()){
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	return 0;
}
