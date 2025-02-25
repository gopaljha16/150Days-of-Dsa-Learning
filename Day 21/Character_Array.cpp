#include <iostream>
using namespace std;

int main(){
    char arr[5] = "1234";
    // char *ptr = arr;
    // //by directly using this it wil not print the address in character we have to type cast into void 
    // cout<<arr<<endl;
    // cout<<ptr<<endl;
    // // (void *) // it will print the character array address because we have to type cast it..
    // cout<<(void*)arr<<endl;
    // cout<<(void*) ptr<<endl;


    // like this also it will not give the output address so in this also we have to use (void* )then only it will give the exact address of the name..
   char name = 'a';
   cout<<name<<endl;
   char *ptr2 = &name;
   cout<<(void*)ptr2<<endl;;// correct and exact result will be coming in the output..
   cout<<(void*)&name<<endl; // this will also give the exact address

//    static_cast<void*> // by using this also we will get the exact addres
cout<<static_cast<void*>(arr)<<endl;
}