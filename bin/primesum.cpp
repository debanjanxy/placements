#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

void printArray(int *arr){
	int l = sizeof(arr)/sizeof(arr[0]);
	cout << "Size =" << l << endl;
	for(int i=0;i<l;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

vector<int> primesum(int n) {
    //cout << "n = " << n << endl;
    int Primes[n+1];
    cout << "Hello" << endl;
    //printArray(Primes);
    for(int i=0;i<=n;i++){
        Primes[i] = 1;
    }
    //cout << Primes[4] << endl;
    //printArray(Primes);
    Primes[0] = 0;
    Primes[1] = 0;
    for(int i=2;i<=int(sqrt(n));i++){
        if(Primes[i]==1){
            for(int j=2;i*j<=n;j++){
                Primes[i*j] = 0;
            }
        }
    }
    //cout << "Element 2" << Primes[2] << endl;
    //printArray(Primes);
    int p1 = INT_MAX, p2 = INT_MAX,x;
    for(int i=2;i<n+1;i++){
        if(Primes[i]==1){
            cout << "i=" << i << " ";
            x = n-i;
            if(Primes[x]==1){
                cout << "x=" << x << " " << endl;
                int a,b;
                a = (i<x)?i:x;
                b = n-a;
                cout << "a=" << a << "b=" << b << endl;
                if((a<p1 || a==p1)&&b<p2){
                    p1 = a;
                    p2 = b;
                    cout << "p1=" << p1 << " " << "p2=" << p2 <<endl;
                }
            }
        }
    }
    vector<int>list;
    list.push_back(p1);
    list.push_back(p2);
    return list;
    
}

int main(){
	vector<int> result;
	int n;
	cin >> n;
	result = primesum(n);
	cout << result[0] << " " << result[1] << " " << endl;
	return 0;
}
