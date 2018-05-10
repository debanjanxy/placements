#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int isMagic(long num){
    string numstr = to_string(num);
    int d0=numstr[5]-'0', d1=numstr[4]-'0', d2=numstr[3]-'0', d3=numstr[2]-'0', d4=numstr[1]-'0', d5=numstr[0]-'0';
    int s1 = d0+d1+d2;
    int s2 = d3+d4+d5;
    if(s1==s2){
        return 1;
    }
    else{
        return 0;
    }
}

int compare(long n1, long tick){
    string n1str=to_string(n1), tickstr=to_string(tick);
    int sum=0;
    for(int i=0;i<6;i++){
        if(n1str[i]!=tickstr[i]){
            sum++;
        }
    }
    return sum;
}

int main(){
    char ticket[7];
    int sum1 = 0, sum2 = 0;
    for(int i=0;i<6;i++){
        cin >> ticket[i];
    }
    ticket[6] = '\0';
    long tick;
    sscanf(ticket,"%ld",&tick);
    // cout << tick << endl;
    int curr, res = 99999;
    for(long int i=0;i<999999;i++){
        if(isMagic(i)){
            curr = compare(i,tick);
            res = min(curr,res);
        }
    }
    cout << res << endl;
    
    return 0;
}