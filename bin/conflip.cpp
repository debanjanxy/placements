#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int g;
		cin >> g;
		while(g--){
			long long int n,res1,res2;
			int i,q;
			cin >> i >> n >> q;
			if(n%2==0){
				cout << n/2 << endl;
			}
			else{
				res1 = n/2;
				res2 = n-res1;
				if(i==q) cout << res1 << endl;
				else cout << res2 << endl;
			}
		}
	}
	return 0;
}