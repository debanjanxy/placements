//#include <simplecpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



int main()
{
    string expr, part,num_str="1234";
    getline(cin,expr);
    int i = 0,num;
    while(expr[i]!=32){
		part += expr[i];
		i++;
	}
    //cin >> noskipws >> expr;
    //int n = expr.length();
    //for(int i=0;i<n/2;i++){
		//part[i] = expr[i];
	//}
	int t = expr.find("jk");
	cout << t << endl;
	cout << part << endl;
    cout << endl << expr << endl;
    num = atoi(num_str);
    num++;
    cout<<num<<endl;
    return 0;
}
