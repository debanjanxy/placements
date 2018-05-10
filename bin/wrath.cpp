#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	long long int n,count=0;
	cin >> n;
	long long int l[n];
	for(long long int i=0;i<n;i++){
		cin >> l[i];
	}
	long long int p1=0,p2=1;
	for(long long int i=0;i<n;i++){
		l[i] = i-l[i];
	}
	while(p2<n){
		
	}
	for(long long int i=0;i<n;i++){
		if(l[i] != -1) count++;
	}
	cout << count << endl;
	return 0;
}
