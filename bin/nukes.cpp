#include <iostream>
using namespace std;
void printArray(int *arr,int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){
	int a,n,k;
	cin >> a >> n >> k;
	int chambers[k] = {0};
	while(a){
		int i=0;
		while(chambers[i]<=n){
			chambers[i]++;
			a--;
		}
		while(chambers[i]==n+1){
			chambers[i] = 0;
			chambers[i+1] += 1;
			i++;
		}
	}
	printArray(chambers,k);
	return 0;
}