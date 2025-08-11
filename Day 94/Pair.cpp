#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
 
    //one method
    // pair<int,int>p;
    // p = make_pair(20,30);
    //second method for pair
    // p.first = 100;
    // p.second = 200;

    // if you want to add 3 values then we use
    pair<string , pair<int, int>>p;
    p = make_pair("Gopal" , make_pair(20,50)); //name age weight
    // cout<<p.first<<" "<<p.second<<endl;
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    //like theese we can create many pair doulbe..
    
}