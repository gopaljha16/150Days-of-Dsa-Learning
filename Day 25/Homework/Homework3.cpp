#include <iostream>
using namespace std;

// 3: Print all numbers from 1 to n using recursion. 
  
   void print(int n){
   
    if(n==20){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    print(n+1);

   }


int main(){
   int n = 1;
//    cout<<"Enter the n value :- ";
//    cin>>n;

//    for(int i=1 ;i<=n;i++){
//     cout<<i;
//    }
   print(n);
}