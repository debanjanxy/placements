#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
//#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
//#include <fstream>
//#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include <unordered_map>

using namespace std;

int computeHGS(vector<vector<int> > arr,int i,int j){
    //i = 0; j = 0;
    return (arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]);
    //return arr[3][1];
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int val,max=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            val = computeHGS(arr,i,j);
            if(val>max) max = val;
        }
    }
    cout << max << endl;
    return 0;
}
