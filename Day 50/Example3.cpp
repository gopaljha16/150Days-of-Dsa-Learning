#include <iostream>
#include <exception>
using namespace std; 

// here it has an exception class
// class exception {

//      string msg;

//      exception(string msg){
//         this->msg = msg;
//      }

//      string what(){
//        return msg;
//      }
// };  like this it will be..

int main(){
    // here automatically it will give the error.
    try{
        // int *p = new int[10000000000000];
        cout<<"Memory allocation is successfuly";  
        // delete []p;
    }catch(const bad_alloc &e){
        cout<<"Exception"<<e.what()<<endl;
    }

}