#include<bits/stdc++.h>
using namespace std;
int main()
{
        map<string,int> m;
        m["aa"]=1;
        map<string,set<int> > my;
        set<int> s1;
        set<int> s2;
        s1.insert(1);s1.insert(2);
        s2.insert(3);
        my["aa"]=s1;
        my["bb"]=s2;
        for(auto it=s1.begin();it!=s1.end();it++)
        cout<<*it<<endl;
         map<string,set<int> >::iterator it;
         for(it=my.begin();it!=my.end();it++)
         {
			     set<int> ::iterator jt;
			     for (jt=it->second.begin();jt!=it->second.end();jt++)
			     cout<<*jt<<endl;
		 }
}
