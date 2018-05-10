#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	long long int n,sum = 0;
	cin >> n;
	long long int a[n];
	long long int b[n];
	for(long long int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	for(long long int i=0;i<n;i++){
		cin >> b[i];
	}
	sort(b,b+n);
	if(sum<=b[n-2]+b[n-1]){
		cout << "YES" << endl;
	}
	else{ cout << "NO" << endl; }
	return 0;
}
	
