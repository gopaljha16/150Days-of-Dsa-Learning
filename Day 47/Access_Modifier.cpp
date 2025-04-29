#include <iostream>
using namespace std;

// acess modifier
class Human {

     private:
     int a;
     protected:
     int b;
     public:
     int c;

    //  within class every it will acessable
    Human(){
        a = 10;
        b = 20; 
        c = 30; //here every access specifier can be accessed in the within class..
    }
};
int main(){
  Human Gopal;
//   Gopal.a; // can't be accesible becuase it is private
// Gopal.b // also can't be access it canot be access in the external assess int main
Gopal.c = 10; // can be accesable.

}