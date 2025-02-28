#include <iostream>
using namespace std;

//  void print1_to_n(int num , int n ){

//     //base case break condition
//     if(num==n){
//         cout<<num;
//         return;
//     }

//     cout<<num<<" ";
//     print1_to_n(num+1 , n);
//  }

// another way
// starting from reverse and printing
 void print1_to_n(int num){

     if(num==1){
        cout<<1<<" ";
        return;
     }

    print1_to_n(num-1);
    cout<<num<<" ";
 }

 /* 
 print1_to_n(5)  
 ├── print1_to_n(4)  
 │    ├── print1_to_n(3)  
 │    │    ├── print1_to_n(2)  
 │    │    │    ├── print1_to_n(1) → Prints: "1 "  
 │    │    │    └── Returns, prints: "2 "  
 │    │    ├── Returns, prints: "3 "  
 │    ├── Returns, prints: "4 "  
 ├── Returns, prints: "5 " */

int main(){
    // iterative way
    int n= 5;
    // for(int i=1;i<=n ; i++){
    //     cout<<i<<" ";
    // }

    // recursive way 
    print1_to_n(n);

}