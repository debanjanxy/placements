#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


int in = 0;
string getOp1(string expr){
	string op1;
    while(expr[in]!=32){
		op1 += expr[in];
		in++;
	}
	return op1;
}
string getOp2(string expr){
	string op2;
	in += 3;
	while(expr[in] != 32){
		op2 += expr[in];
		in++;
	}
	return op2;
}
string getRes(string expr){
	string res;
	in += 3;
	while(expr[in]!='\0'){
		res = expr[in];
		in++;
	}
	return res;
}
bool isContainMachula(string operand){
	string machu = "machula";
	if(operand.find(machu) != string::npos) return true;
	else return false;
}
int toInteger(string s){
	stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
string toString(int num){
	string result;
	stringstream convert;
	convert << num;
	result = convert.str();
	return result;
}
string makeString(int op1, int op2, int res){
	string op11,op22,res1,expr;
	op11 = toString(op1);
	op22 = toString(op2);
	res1 = toString(res);
	expr += (op11+" + "+op22+" = "+res1);
	return expr;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string expr, op1, op2, res;
		int op11,op22,res1;
		cin >> expr;
		op1 = getOp1(expr);
		op2 = getOp2(expr);
		res = getRes(expr);
		cout << op1 << endl << op2 << endl << res << endl;
		if(isContainMachula(op1)){
			op22 = toInteger(op2);
			res1 = toInteger(res);
			op11 = res1 - op22;
			expr = makeString(op11,op22,res1);
		}
		else if(isContainMachula(op2)){
			op11 = toInteger(op1);
			res1 = toInteger(res);
			op22 = res1 - op11;
			expr = makeString(op11,op22,res1);
		}
		else{
			op11 = toInteger(op1);
			op22 = toInteger(op2);
			res1 = op11+op22;
			expr = makeString(op11,op22,res1);
		}
		cout << expr << endl;
	}
	return 0;
}
