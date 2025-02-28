#include <iostream>
using namespace std;

  void print(int n){
    // base case
    if(n==0){
        return;
    }

    cout<<n<<" : Coder Army"<<endl;
    print(n-1);
  }

int main(){
    print(10);
}