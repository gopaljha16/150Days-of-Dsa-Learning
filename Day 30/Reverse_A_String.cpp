#include <iostream>
using namespace std;

 void reverse(string &str , int start , int end){
    
    // base case
    if(start>=end){
       return ;
    }

    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    // like thid we have swapped it..
    reverse(str , start+1 , end-1);
 }

int main(){

    string str = "gopal";
    reverse(str , 0 , 4);
    cout<<str; //here no changes becuase we are sending pass by value by giving pass by reference the changes will be reflected.
}