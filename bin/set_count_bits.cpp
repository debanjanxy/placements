#include <iostream>
#include <cmath>

#define B2(n) n,n+1,n+1,n+2


using namespace std;

int countSetBits(int n){
	unsigned int count =0;
	while(n){
		//cout << "Inside" << endl;
		n = n&(n-1);
		count++;
	}
	return count;
}


int main(){
	int arr[] = {B2(4)};
	for(int i=0;i<4;i++){
		cout << arr[i] << endl;
	}
	int n,num;
	cin >> n;
	num = n;
	unsigned int count = 0;
	while(num){
		count += num & 1;
		//cout << "Number = " << num << "Count = " << count << endl;
		num >>= 1;
	}
	cout << "Bruteforce: " << count << endl;
	cout << "Brian Kernigham: " << countSetBits(n) << endl;
	cout << "Built-in PopCount: " << __builtin_popcount(n) << endl;
	return 0;
}