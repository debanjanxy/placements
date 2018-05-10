#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,k,l,c,d,p,nl,np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int drink,slice,salt;
	drink = k*l/nl;
	slice = c*d;
	salt = p/np;
	int toasts = min(drink,min(slice,salt));
	cout << toasts/n << endl;
	return 0;
}
