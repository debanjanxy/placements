#include <iostream>
using namespace std;


class MinHeap{
	int *elements;
	int capacity;
	int heap_size;
public:
	MinHeap(int capacity);
	void MinHeapify(int i);
	int parent(int i){return (i-1)/2;}
	int left(int i){ return (2*i+1);}
	int right(int i){ return (2*i+2);}
	int extractMin();
	void decreaseKey(int i, int new_val);
	int getMin(){ return elements[0];}
	void deleteKey(int i);
	void insertKey(int k);
};
MinHeap :: MinHeap(int cap){
	heap_size = 0;
	capacity = cap;
	elements = new int[cap];
}

void MinHeap :: MinHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l<heap_size && elements[l]<elements[i]) smallest = l;
	if(r<heap_size && elements[r])	
}