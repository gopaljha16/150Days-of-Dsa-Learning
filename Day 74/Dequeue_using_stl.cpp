#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int>d;
    d.push_back(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);
    d.pop_back();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
}