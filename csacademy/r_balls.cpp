#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

vector <long long int> decr(vector <long long int> v, vector <int> &flag){
    for(int i=0;i<v.size();i++){
        if(v[i]==0 || flag[i]==1){
            v[i]++;
            flag[i] = 1;
        }
        else{ v[i]--; }
    }
    return v;
}

int main(){
    vector <long long int> vect;
    long int n;
    long long int inp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> inp;
        // cout << "Hello1";
        vect.push_back(inp);
        // cout << "Hello2";
    }
    cout << "Hello";
    // vector <int> flag = {0};
    // long long int prev_sum=accumulate(vect.begin(),vect.end(),0);
    // vect = decr(vect,flag);
    // long long int curr_sum=accumulate(vect.begin(),vect.end(),0);
    // while(prev_sum>=curr_sum){
    //     prev_sum = curr_sum;
    //     decr(vect,flag);
    //     curr_sum = accumulate(vect.begin(),vect.end(),0);
    // }
    // cout << prev_sum << endl;
    return 0;
}