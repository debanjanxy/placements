#include<bits/stdc++.h>
using namespace std;
int main()
{
        set<int>s;
        int a=2;
        s.insert(1);
        s.insert(a);
        s.insert(a);
        s.insert(3);
        set<int>::iterator it;
        it=s.lower_bound(2);
        if(it!=s.begin())
        it--;
        cout<<*it<<endl;
}
