#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k){
    int dp[k+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<n+1;i++){
        for(int j=min(i,k);j>0;j--){
            cout << dp[j] << " ";
            dp[j] = dp[j]+dp[j-1];
        }
        cout << endl;
    }
    //cout << dp[k] << endl;
    return dp[k];
}

int main(){
    int n,k;
    cin >> n >> k;
    int res = binomialCoeff(n,k);
    cout << "Result = " << res << endl;
    return 0;
}