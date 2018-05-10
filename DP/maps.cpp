#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main(){
    map <int, int> map1;

    map1.insert(pair <int,int> (1,40));
    map1.insert(pair <int,int> (2,30));
    map1.insert(pair <int,int> (3,20));
    map1.insert(pair <int,int> (4,50));
    map1.insert(pair <int,int> (6,59));
    map1.insert(pair <int,int> (9,12));
    map1.insert(pair <int,int> (7,89));
    map1.insert(pair <int,int> (8,40));
    map1.insert(pair <int,int> (10,34));

    map <int,int> :: iterator it;
    cout << "\nThe map map1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for(it=map1.begin();it!=map1.end();++it){
        cout << "\t" << it->first << "\t" << it->second << "\n";
    }
    cout << endl;

    map <int,int> map2(map1.begin(),map1.end());
    cout << "\nThe map map2 is : \n";
    cout << "\tKEY\tELEMENTS\n";
    for(it=map2.begin();it!=map2.end();++it){
        cout << '\t' << it->first << '\t' << it->second << '\n';
    }
    cout << endl;

    int num;
    num = map2.erase(4);
    cout << num << "removed" << endl;
    cout << "\nThe map map2 is : \n";
    cout << "\tKEY\tELEMENTS\n";
    for(it=map2.begin();it!=map2.end();++it){
        cout << '\t' << it->first << '\t' << it->second << '\n';
    }
    cout << endl;

    cout << map2.find(1)->second << map2.find(1)->first << endl;

    return 0;
}