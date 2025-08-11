#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    //soo here multiset there the duplicate element are allowed and it will be storing the data in the sorted order

    multiset<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(10);


    //erase
    s.erase(10);
    //so here deleting operation if we delete then duplicate also will be deleted in the same time..

    for(auto it=s.begin() ; it!=s.end() ; it++){
        cout<<*it<<" ";
    }
}