#include <iostream>
using namespace std;

bool giveMoney(int i, int m, int *arr){
	bool val;
	if(i<=n && m==0) val = true;
	else if(m < 0||(i==n&&m>0)) val = false;
	else val = giveMoney(i+1,m-arr[i],arr)||giveMoney(i+1,m,arr);
	t[i,m] = val;
}

int main(){
	int n,m;
	cin >> n;
	cin >> m;
	int arr[n];
	int t[n+1][m+1];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	bool ans = giveMoney(0,m,arr);
	if(ans) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}