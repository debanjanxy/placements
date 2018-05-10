#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long int n,k,val,sum,res=0, index;
    //input
    cin >> n >> k;
    long int a[n], t[n], temp[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    //algorithm
    for(int i=0; i<n; i++){
        temp[i] = a[i]*t[i];
    }
    for(int i=0;i<n;i++){
        for(int y=i;y<k && i+y<n;y++){
            sum += temp[y];
        }
        if(sum<res){
            index = i;
            res = sum;
        }
        else if(sum==res){
            int s = 0, r = 0;
            for(int y=index;y<k+index && k+y<n;y++){
                s += a[y];
            }
            for(int y=i;y<k+i && y+k<n;y++){
                r += a[y];
            }
            if(r>s){
                index = i;
            }
        }
    }

    for(int i=index;i<k+index;i++){
        t[i] = 1;
    }
    res = 0;
    for(int i=0;i<n;i++){
        res += a[i]*t[i];
    }
    cout << res << endl;
    return 0;
}
