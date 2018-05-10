#include <stdio.h>
#include <iostream>
#define PI 3.14159
using namespace std;

int main(){
	int l;
	while(1){
		cin >> l;
		if(l==0) break;
		float area = (l*l)/(2*PI);
		printf("%0.2f\n",area);
	}
	return 0;
}
