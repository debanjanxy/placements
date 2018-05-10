#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t,n,r;
    cin >> t;
    while(t--){
        cin >> n >> r;
        if(n<r){
            cout << 0 << endl;
            continue;
        }
        long long dp[n+1][r+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,r);j++){
                if(j==0 || j==i){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%1000000007;
                }
            }
        }
        cout << dp[n][r] << endl;
    }
    return 0;
}