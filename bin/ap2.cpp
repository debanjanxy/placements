#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int f,l,s,n,a,d;
		cin >> f >> l >> s;
		n = (2*s)/(l+f);
		d = (l-f)/(n-5);
		a = f-2*d;
		cout << n << endl;
		for(int i=0;i<n;i++){
			cout << a+i*d << " ";
		}
		cout << endl;
	}
	return 0;
}
