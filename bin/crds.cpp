#include <iostream>
using namespace std;

long long int func(long long int n){
	if(n==0) return 0;
	return 3*n-1+func(n-1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		long long int res = func(n);
		cout << res%1000007 << endl;
	}
	return 0;
}
