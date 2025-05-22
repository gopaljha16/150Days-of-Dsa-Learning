#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int>S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    cout<<S.top()<<endl;
    S.pop();
    cout<<S.size()<<endl;
    cout<<S.empty()<<endl;
}