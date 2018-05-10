#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int a,b;
		cin >> a >> b;
		if(a==0 && b==0) break;
		int B[a], C[b];
		for(int i=0;i<a;i++) cin>>B[i];
		for(int i=0;i<b;i++) cin>>C[i];
		sort(B,B+a);
		sort(C,C+b);
		int attacker = B[0];
		int defender = C[1];
		if(attacker>=defender) cout << "N" << endl;
		else cout << "Y" << endl;
	}
	return 0;
} 
