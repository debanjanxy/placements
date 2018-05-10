#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int sum=0,curr,value,index=0;
		long int a[n],ps[n],ss[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum += a[i];
		}
		ps[0] = a[0];
		ss[0] = sum;
		value = ps[0]+ss[0];
		index = 0;
		for(int i=1;i<n;i++){
			ps[i] = ps[i-1]+a[i];
			ss[i] = ss[i-1]-a[i-1];
			curr = ps[i]+ss[i];
			if(curr<value){
				value = curr;
				index = i;
			}
		}
		cout << index+1 << endl;
	}
	return 0;
}
