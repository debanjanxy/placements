#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	long long int t;
	cin >> t;
	int l = 1;
	while(t--){
		int stamp,n;
		cin >> stamp >> n;
		int arr[n],sum=0;
		for(int i=0;i<n;i++){cin >> arr[i];}
		sort(arr,arr+n, greater<int>());
		int i;
		for(i=0;i<n;i++){
			if(sum>=stamp){
				break;
			}
			sum += arr[i];
		}
		cout << "Scenario #" << l++ << ":" << endl;
		if(sum<stamp || (n==1&&stamp==1)) cout << "impossible"<<endl;
		else cout << i+1 << endl;
	}
	return 0;
}
