#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findIndex(vector<long long> a, int i, long n){
    int index=-1;
    long long res=99999999;
    for(int j=0;j<n;j++){
        if(j!=i){
            if(a[j]>a[i]){
                if(res>a[j]){
                    index = j;
                    res = a[j];
                }
            }
        }
    }
    return index;
}

void printVector(vector<int> p, long n){
    for(long i=0;i<n;i++){
        cout << p[i] << " ";
    }
    cout << endl;
}

int countZeros(vector <int> p, long n){
    int res=0;
    for(int i=0;i<n;i++){
        cout << p[i] << "-";
        if(p[i]==0){ res++; }
    }
    return res;
}

int main(){
    long int n;
    long long inp;
    cin >> n;
    vector <long long> a;
    for(int i=0;i<n;i++){
        cin >> inp;
        a.push_back(inp);
    }
    vector <int> flag = {0};
    vector <int> p = {0};
    int index;
    for(int i=0;i<n;i++){
        //cout << "cp1" << endl;
        index = findIndex(a,i,n);
        cout << a[i] << ":" << index << ":" << flag[index];
        if(index!=-1 && flag[index]==0){
            cout << ": inside ";
            flag[index]=1;
            p[i] = index+1;
        }
        cout << "--" << p[i] << ":" << index << ":" << flag[index] << endl;
    }
    printVector(p,n);
    cout << p[0] << p[1] << p[2] << p[3] << endl;
    long res = count(p.begin(),p.end(),0);
    res = countZeros(p,n);
    cout << res << endl;
    return 0;
}