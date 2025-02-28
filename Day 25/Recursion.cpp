#include <iostream>
using namespace std;

// normal function methood
// void fun3(int n ){
//     cout<<n<<" Days left for the birthday"<<endl;
// }

// void fun2(int n ){
//     cout<<n<<" Days left for the birthday"<<endl;
// }

// void fun1(int n ){
//     cout<<n<<" Days left for the birthday"<<endl;
// }

// void fun0(int n ){
//     cout<<"Happy Birthday to me...";
// }

// by calling function inside function
// void fun0(int n ){
//     cout<<"Happy Birthday to me...";
// }

// void fun1(int n ){
//     cout<<n<<" Days left for the birthday"<<endl;
//     fun0(n-1);
// }

// void fun2(int n ){
//     cout<<n<<" Days left for the birthday"<<endl;
//     fun1(n-1);
// }

// void fun3(int n ){
//     cout<<n<<" Days left for the birthday"<<endl;
//     fun2(n-1);
// }

// Recursion Way..
void fun3(int n){
    // base case..
    if(n==0){
        cout<<"Happy Birthday to me..";
        return;
    }
    cout<<n<<" Days Left for birthday";
    cout<<endl;
    fun3(n-1);
}
// in recursion way it should contain an break condtion or base case which says when it should be stop when it start their recursion 
// In recursion the function calling itself until their break condtion is match then it will stop their recursion the above say the example..
// Immport Break Condition is most important or else it will run an infinite loop and **return** write in the condition it will go to infinite loop and it will run continously...so make sure to write the return and break condtion 
// if we not give the base case then stack will overflow and it will crash the code..

// Iterative way == Recursion way..
// both needs the  break condtion when break condition mets then it will be stopped..


// 

int main(){
    // Printing the happy birthday left by using iterative way 
    // int n =5;
    // for(int i=n ; i>=0 ; i--){
    //     if(i==0){
    //         cout<<"Happy Birthday";
    //         return 0;
    //     }
    //     cout<<i<<" Days Left for the birthday";
    //     cout<<endl;
    // }

    // by using function doing this birthday printing
    // fun3(3);
    // fun2(2);
    // fun1(1);
    // fun0(0);

    // another way calling one fucntion and doing the same work
    // fun3(3);

    // recursion way...
    fun3(10);
}