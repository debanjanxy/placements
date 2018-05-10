#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int m = 2*n+1;
	int a[m][m];
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			a[i][j] = -1;
		}
	}
	for(int i=0;i<=n;i++){
		a[i][n] = i;
		a[m-1-i][n] = i;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			//if(a[i][j]!=-1){
				cout << a[i][j] << " ";
			//}
		}
		cout << endl;
	}
	return 0;
}
