#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float c;
	cin >> c;
	while(c){
		float i=2.00; 
		float sum=0.00;
		while(sum<c)
		{
			sum += 1.00/float(i);
			i++;	
		}
		cout << i-2 << " card(s)" << endl;
		cin >> c;
	}
	return 0;
}
