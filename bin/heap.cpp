#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap{
	vector<int>harr;
public:
	void MinHeapify(int i);
	int parent(int i){return (i-1)/2;}
	int left(int i){return 2*i+1;}
	int right(int i){return 2*i+2;}
	int extractMin();
	void decreaseKey(int i,int new_val);
	int getMin(){return harr[0];}
	void deleteKey(int i);
	void insertKey(int k);
};
void MinHeap::insertKey(int k){
	int i = harr.size()-1;
	harr[i] = k;
	while(i!=0 && harr[parent(i)]>harr[i]){
		swap(harr[i],harr[parent(i)]);
		i = parent(i);
	}
}


int main(){
	MinHeap h;
	h.insertKey(3);
	return 0;
}



























/*
void heapify(vector<long long int>h,int i){
	int l = 2*i+1;
	int r = 2*i+2;
	int smallest = i;
	if(h[i]>=h[l]) smallest = l;
	if(h[smallest]>=h[r]) smallest = r;
	if(smallest!=i){
		swap(&h[i],&h[smallest]);
		heapify(h,smallest);
	}
}

int main(){
	vector<long long int>h;
	//hepaify(heap.begin(),heap.end());
	h.push_back(5);
	h.push_back(6);
	h.push_back(3);
	heapify(h,0);
	for(unsigned int i=0;i<h.size();i++){
		cout << h[i] << " ";
	}
	return 0;
} 
'''
*/
