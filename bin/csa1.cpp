#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iterator>
#include <map>


using namespace std;

int main(){
	string word;
	cin >> word;
	int t[26],val=97;
	//char ch[26];
	/*
	for(int i=0;i<26;i++){
		ch[i] = val;
		val++;
	}
	for(int i=0;i<26;i++){
		cin >> t[i];
	}*/
	map <char, int> mp;
	for(int i=0;i<26;i++){
		cin >> t[i];
		mp.insert(pair <char, int> (val,t[i]));
		val++;
	}
	int sum = 0;
	int l = word.length();
	char now;
	for(int i=0;i<l;i++){
		now = word[i];
		sum += mp.at(now);
	}
	cout << sum << endl;
	return 0;
}
	
	
