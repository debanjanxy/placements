#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

void fillDiagonal(int **res, int i, int j, int n,int k){
	if(i==n && j==n) return;
	res[i][j] = res[i-1][j-1]+k;
	fillDiagonal(res,i+1,j+1,n,k);
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int res[n][n];
	res[0][0] = m;
	fillDiagonal(res,1,1,n,k);
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(i>j) res[i][j] = res[i-1][j]-1;
			else if(i<j) res[i][j] = res[i][j-1]-1;
		}
	}
