#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> vect(n);
    int inp, N=2*n;
    for(int i=0;i<N;i++){
        cin >> inp;
        vect.push_back(inp);
    }
    sort(vect.begin(),vect.end());
    reverse(vect.begin(),vect.end());
    if(vect[N/2]<vect[(N/2)-1]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}