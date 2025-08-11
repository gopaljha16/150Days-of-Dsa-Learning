#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    map<int,int>m; 
    // multimap<int,int>m; //here it can have multiple key

    //unique keys and it will be in the sorted way
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,10));
    m.insert(make_pair(40,110));
    m.insert(make_pair(50,33));
    m.insert(make_pair(60,40));
    m.insert(make_pair(20,50));

    //another way to implement 
    //m[20] =40;//here it will do the updation also if there is not key present then it will be create the key and value which your giving
   //in multimap it will not work because here there can be many keys it can't update so it's like this
    //delete
    m.erase(20);

    //printing
    if(m.count(20)){
        cout<<m[20]<<endl; //here it for edge case if the key doens't exist thne it will be not print so we use this if 0 not print 1 then it will be pritning
    }

    //printig value 
    for(auto it=m.begin() ; it!=m.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}