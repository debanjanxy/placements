#include <iostream>
#include <cmath>

using namespace std;

void swap(int *a, int *b){
	*b = (*a)+(*b)-(*a=*b);
}

int main(){
	int a=3,b=6;
	cout << "a: " << a << " b: " << b << endl;
	swap(&a,&b);
	cout << "a: " << a << " b: " << b << endl;
	return 0;
}