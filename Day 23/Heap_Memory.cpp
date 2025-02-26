#include <iostream>
using namespace std;

int main(){
   // dynamic memory allocation..
    // for memory allocating in the heap we need to use the keyword (new);
    // new key activates or sort of something that it will be storing the allocation in the heap 
    //  new int  it will return address;

    int *ptr = new int;
    cout<<ptr<<endl; // it will print the address where this varibale has stored in the heap memory allocation..
    // for assign the value
    *ptr = 5;
    cout<<*ptr<<endl; // like this we can see in that address value which is stored...

    // float type value 
    float *ptr2 = new float;
    *ptr2 = 10.5;
    cout<<*ptr2<<endl;

    // user define array 
    int n;
    cout<<"Enter the size of array :- ";
    cin>>n;
    int *p = new int[n]; //like this memory will be allocated..

    // assigning the values;
    for(int i = 0; i<n ; i++){
        p[i] = i+1;  // assigning the value from 1 to n
    }

    //print the value
    for(int i=0 ; i<n ; i++){
        cout<<p[i]<<" ";  // prints the value
    }

    // releasing the memory which is allocated by the variables , float and array by using 
    // delete keyword;
    delete ptr; // variables can be deleted like this only..
    delete ptr2;
    delete[] p; // for array deleting we need to use square bracket then it will be delete from the heap memory allocation 
}