#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main(){
	int bin;
	cin >> bin;
	ostringstream str1;
	str1 << bin;
	string bin_str = str1.str();
	int dec = 0;
	for(int i=0;i<bin_str.length();i++){
		int bit = bin_str[i]-'0';
		dec = 2*dec+bit;
	}
	cout << dec << endl;
	return 0;
}