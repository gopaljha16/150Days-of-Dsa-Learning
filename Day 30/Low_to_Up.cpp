#include <iostream>
using namespace std;

 void  LowToUp(string &str , int index){
  
    // base case
    if(index==-1)
    return;
     
    // changing to uppercase
    str[index] = 'A'+str[index]-'a';

    LowToUp(str ,index-1);
 } 

int main(){

    string str = "gopal";
    LowToUp(str , 4);
    cout<<str;
}