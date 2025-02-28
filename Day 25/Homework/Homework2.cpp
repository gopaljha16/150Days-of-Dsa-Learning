#include <iostream>
using namespace std;

// 2: Print all odd number from n to 1 using recursion
void print(int n){
    // base case..
    if(n==1){
        cout<<1;
        return;
    }
    if(n%2==1)
    cout<<n<<" ";

    print(n-1);
}

int main(){
    int n;
    cout<<"Enter the n value :- ";
    cin>>n;
    print(n);
}