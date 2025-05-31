#include <iostream>
#include <queue>
using namespace std;

int main(){
    //create queue
    queue<int>q;
    //insert elel
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(80);

    //pop elel
    q.pop();

    //starting number printing
    cout<<q.front()<<endl;

    //back elelment
    cout<<q.back()<<endl;

    //size printing
   cout<<q.size()<<endl;

   //empty of not
   cout<<q.empty()<<endl;
}