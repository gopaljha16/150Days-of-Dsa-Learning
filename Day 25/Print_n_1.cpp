#include <iostream>
using namespace std;

// recursive method
void print(int n ){
    // base case..
    if(n==1){
        cout<<1;
        return;
    }
    cout<<n<<" ";
    print(n-1);
}

int main(){
    // Print n to 1;
    int n;
    cout<<"Enter the n value :- ";
    cin>>n;

    // iterative way
    // for(int i=n;i>0;i--){
    //     cout<<i<<" ";
    // }

    //recursive way..
    print(n);
}