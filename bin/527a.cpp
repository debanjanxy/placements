#include <iostream>
using namespace std;
/*
long long int boats(long long int a, long long int b){
	if(b==1)return a;
	if(a==b) return 1;
	long long int m = max(a-b,b);
	long long int n = min(a-b,b);
	return 1+boats(m,n);
}*/
int main(){
	long long int a,b;
	cin >> a >> b;
	long long int q=0,r=0,count=0;
	do{
		q = a/b;
		r = a%b;
		a = b;
		b = r;
		count += q;
	}while(r);
	cout << count << endl;
	return 0;
}
