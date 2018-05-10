#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    vector <int> v;
    vector <int> :: iterator it;
    int c = 0, max=0,res, sum=0,x,n,inp;
    cin >> n;
    for(int i=0;i<n;i++){ 
        cin >> inp;
        v.push_back(inp); 
    }
    int c0 = count(v.begin(),v.end(),0);
    int c1 = count(v.begin(), v.end(), 1);
    int c2 = count(v.begin(), v.end(), 2);
    int res0 = 2*c1+c2;
    int res1 = c0+2*c2;
    int res2 = 2*c0+c1;
    int r;
    r = min(min(res0,res1),res2);
    cout << r << endl;
    return 0;
}