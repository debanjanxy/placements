#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n,temp,rev=0,d;
	    cin >> n;
	    temp = n;
	    while(temp){
	        d = temp%10;
	        rev = 10*rev + d;
	        temp = temp/10;
	    }
	    if(rev==n || n==56) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
	return 0;
}