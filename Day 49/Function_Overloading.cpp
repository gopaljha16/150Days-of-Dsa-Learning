#include <iostream>
using namespace std;
// Function Overloading :- Here the funtion overload it will know in the compile time only so we can make the same name funtion in one class but with the different paramters means forms that means the function overloading (in compile time it will know which function have to be called..)

 class Area{
    public:

    int calculateArea(int r){ //cirlce calculation 
        return 3.14*r*r;
    }

    int calculateArea(int l , int b){ // rectange calculation
        return l* b;
    }
 };

int main(){
   Area A1,A2;
   cout<<A1.calculateArea(4);
   cout<<endl;
   cout<<A2.calculateArea(3,4); // so here the compiler it will know to whic fucntion to call by the parameter.
}