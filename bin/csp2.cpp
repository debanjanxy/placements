#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iterator>
#include <map>


using namespace std;

long long int findZeros(string bs){
	long long int res = 0,max = 0, l=bs.length();
	for(long long int i=0;i<l;i++){
		if(bs[i]=='1') res = 0;
		else res++;
		if(res>=max) max = res;
	}
	return max;
}
long long int all_zeros(string bs,long long int n){
	for(long long int i=0;i<n;i++){
		if(bs[i]=='1') return 0;
	}
	return 1;
}	

int main(){
	string bs;
	long long int n,k;
	cin >> n >> k;
	cin >> bs;
	long long int res = 0;
	if(bs[0]=='0' && bs[n-1]=='0'){
		long long int i=0;
		if(all_zeros(bs,n)){
			res = n*k;
		}
		else{
			if(k==1){
				res = findZeros(bs);
			}
			else{
		while(bs[i]!='1'){
			i++;
		}
		long long int j = n-1;
		while(bs[j]!='1'){
			j--;
		}
		long long int x = (n-1)-j;
		long long int k = findZeros(bs);
		if(k>i+x) res = k;
		else res = i+x;
		}
	}
	}
	else{
		res = findZeros(bs);
	}
	cout << res << endl;
	return 0;
}
