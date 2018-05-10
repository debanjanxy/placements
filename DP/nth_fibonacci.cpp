#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long long fibo(int n, vector <long long> &dp){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else if(dp[n]!=-1){
        return dp[n];
    }
    else{
        long long res = (fibo(n-1,dp)+fibo(n-2,dp))%1000000007;
        dp[n] = res;
    }
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        // long long dp[n] = {-1};
        vector <long long> dp(n+1,-1);
        dp[0] = 0; dp[1] = 1;
        long long res = fibo(n,dp)%1000000007;
        cout << res << endl;
    }
    return 0;
}