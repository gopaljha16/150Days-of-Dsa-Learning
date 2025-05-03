#include <iostream>
using namespace std;

int main(){
// In this code there is an exception that when i divide the number with 0 then it's giving the value as 0 so here the exception should be handled. we can use ifelse or try catch throw
    int a,b;
   // if(b==0){
    //     cout<<"Can't be divisible by 0"<<endl;
    // }
    cin>>a>>b;
    try{
        if(b==0){
            throw "Can't be divisble by 0\n";
        }
         
        int c = a/b;
        cout<<c<<endl;
    }catch(const char *e){
        cout<<"Exception occured "<<e<<endl;
    }
  
}