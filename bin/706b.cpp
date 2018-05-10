#include <iostream>
#include <algorithm>
using namespace std;

int bs(int sh[], int l,int r,int x){
	int c=-1,p;
	if(r>=l){
		int mid = (l+r)/2;
		if(sh[mid]==x) return mid;
		if(sh[mid] > x)c = bs(sh,l,mid-1,x);
		else{
			c = mid;
			p = bs(sh,mid+1,r,x);
			if(p>c) c = p;
		}
	}
	return c;
}
int main(){
	long long int n,q,money,k;
	cin >> n;
	int sh[n];
	for(int i=0;i<n;i++) cin >> sh[i];
	sort(sh,sh+n);
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> money;
		k = bs(sh,0,n,money);
		cout << k+1 << endl;
	}
	return 0;
}
