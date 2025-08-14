#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    // priority_queue<int>p; //maxheap 

    // p.push(10);
    // p.push(30);
    // p.push(420);
    // p.push(45);
    // p.push(6);
    // p.push(1);

    // //top element
    // cout<<p.top()<<" ";

    // //delete element
    // p.pop();
    // cout<<p.top()<<" ";

    // //size print
    // cout<<p.size()<<" ";

    // //print element
    // while(!p.empty()){
    //     cout<<p.top()<<" ";
    //     p.pop();
    // }

    //minheap
    priority_queue<int , vector<int> , greater<int>>p;
        p.push(10);
    p.push(30);
    p.push(420);
    p.push(45);
    p.push(6);
    p.push(1);

    //top element
    // cout<<p.top()<<" ";

    // //delete element
    // p.pop();
    // cout<<p.top()<<" ";

    // //size print
    // cout<<p.size()<<" ";

    //print element
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }


}