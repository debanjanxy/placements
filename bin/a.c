#include <stdio.h>
#include <math.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
int find_min(int *arr, int n){
	int min_elem;
	if(n==1)return arr[0];
	min_elem = MIN(arr[n-1],find_min(arr,n-1));
	return min_elem;
}
int main(){
	int arr[] = {98,45,12,78,100,23,11,87,34,51,90,97};
	int length = sizeof(arr)/sizeof(arr[0]);
	int min = find_min(arr,length);
	printf("%d",min);
	return 0;
}
