#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

int fourSeven(long long value){
	ostringstream str1;
	str1 << value;
    string s = str1.str();
    //cout << s << endl;
    long long l = s.length();
    long long n4=0,n7=0;
    for(int i=0;i<l;i++){
        if(s[i]=='4') n4++;
        else if(s[i]=='7') n7++;
    }
    if(n4==n7 && n4!=0 && n7!=0) return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    int flag = 0;
    long long res = 9999999999;
    string res_name;
    for(int a0 = 0; a0 < n; a0++){
        int f = 0;
        string name;
        long long int value;
        cin >> name >> value;
        f = fourSeven(value);
        
        //cout << endl << name << " " << f << endl;
        if(f){
            if(value<=res){
                res = value;
                flag = 1;
                res_name = name;
            }
        }
    }
    if(!flag){ cout << -1 << endl; }
    cout << res_name << endl;
    return 0;
}
