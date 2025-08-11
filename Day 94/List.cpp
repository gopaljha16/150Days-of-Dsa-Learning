#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){


    //creating list 
    list<int>l; //type is int and this will be creating the list in the doubly linked list
    //operation 
    // push_back , push_front , pop_front() , pop_back() , size , front , back , empty;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.pop_front();

    //iterator prints the value
    for(auto it=l.begin() ; it!=l.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //so here we can print the reversly also 

    for(auto it=l.rbegin() ; it!=l.rend(); it++){
        cout<<*it<<" ";
    }
     
    
    
    // cout<<l.front()<<" "<<l.back()<<endl;
    // cout<<"Is empty list"<<l.empty()<<endl;
    // cout<<"size "<<l.size()<<endl;
}