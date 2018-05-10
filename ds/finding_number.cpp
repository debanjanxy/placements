#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPivot(int *a, int start, int end){

		int mid = (start+end)/2;
		if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
			return mid;
		}
		else if(a[mid]>a[mid+1] && a[mid]<a[mid-1]){
			return findPivot(a,start, mid-1);
		}
		else{
			return findPivot(a,mid+1,end);
		}

}

int binary_search_ascending(int *a, int start, int end, int x){

	if(start<=end){
		int mid = (start+end)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x){
			return binary_search_ascending(a,start,mid-1,x);
		}
		else{
			return binary_search_ascending(a,mid+1,end,x);
		}
	}
	return -1;

}

int binary_search_descending(int *a, int start, int end, int x){

	if(start<=end){
		int mid = (start+end)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x){
			return binary_search_descending(a,mid+1,end,x);
		}
		else{
			return binary_search_descending(a,start,mid-1,x);
		}
	}
	return -1;

}

int findX(int *a, int start, int end, int pivot_index, int x){
	
	int index0, index1;
	// cout << "a[pivot_index] = " << a[pivot_index] << ", x = " << x << endl;
	if(a[pivot_index]==x) return pivot_index;
	// else if(a[pivot_index+1]>=x){
	// 	cout << "binary_search_descending" << endl;
	// 	index = binary_search_descending(a,pivot_index+1,end,x);
	// }
	// else{
	// 	cout << "binary_search_ascending" << endl;
	// 	index = binary_search_ascending(a,start,pivot_index-1,x);
	// }
	index0 = binary_search_ascending(a,start,pivot_index-1,x);
	index1 = binary_search_ascending(a,pivot_index+1,end,x);
	if(index0==-1){
		return index1;
	}
	else return index0;

}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int pivot_index = findPivot(a,0,n);
		// cout << "Pivot index = " << pivot_index << endl;
		int index = findX(a,0,n,pivot_index,x);
		if(index==-1){
			cout << "OOPS! NOT FOUND" << endl;
		}
		else{
			cout << index << endl;
		}
		return 0;
	}
}