#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int largest(int x, int y, int z){
    return max(max(x, y), z);
}

int m1(int n,int *arr,int *dp){
	if(n==1) {
		cout << "Inside 1" << endl;
		dp[n-1] = arr[n-1];
		return arr[n-1];
	}
	if(dp[n-1]==-9999){
		cout << "Recursing.." << endl;
		dp[n-1] = largest(m1(n-1,arr,dp),arr[n-1],arr[n-1]+m1(n-1,arr,dp));
		return dp[n-1];
	}
	else{
		cout << "Returning..." << endl;
		return dp[n-1];
	}
	//int c = largest(m1(n-1,arr),arr[n-1],arr[n-1]+m1(n-1,arr));
}

int main(){
	/*
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(int);
	int dp[n];
	fill_n(dp,n,-9999);
	cout << m1(n,arr,dp) << endl;
	*/
	cout << "Hello World" << endl;
	return 0;
}
