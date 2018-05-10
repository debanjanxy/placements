#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// void printArray(int *arr, int n){
//     cout << endl;
//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main(){
    int m,n, val;
    cin >> n >> m;
    int arr[n] = {0};
    for(int i=0; i<m; i++){
        cin >> val;
        arr[val-1]++;
    }
    cout << *min_element(arr, arr+n) << endl;
    return 0;
}
