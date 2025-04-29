#include <iostream>
using namespace std;

 class Human {
  protected:
   string name;
   int age , ph_no;
 };

//  inheritance of one class properties from another class
class Student: protected Human{
   public:
   int roll_no ;
   string branch;

//    we know then we can access the private , protected by making within class and printing that
public:
//   void func(string n , int a , int b){
//     name = n ; 
//     age = a ;
//     ph_no = b;
//   }

// we can make the consturctor acess and print it..
  Student (string name , int age , int ph_no , int roll_no , string branch){
   this->name = name;
   this->age = age ;
   this->ph_no = ph_no;
   this->roll_no = roll_no;
   this->branch  = branch;
  }

   void display(){
    cout<<name<<" age is "<<age<<" phone number "<<ph_no<<" roll no is "<<roll_no<<" branch is "<<branch<<endl;
   }
};

// Here private will be not accessed or intherited to another class (private properties)
// Private can be inherited. .
// If we give protected classs then inheriting or it public then the string name, age , ph_no will be treadted as the protected only so if we try to acess from the external acess then it cannot be accessed.
// When publlic inherited then it will be treadted as the public only public and public of child class.
// Public - Protected then the class properites will be treated as protected.
// protected - Protected then it will treadted as protected so it cannot be acess in external code acess.
// here by making within class we can access all the priavte protected and public and put the value via functions and print also..


// here there is advantage what you want need to encapsuation needed or not keeping you data private or hidden it's your wish...
// and in this what you want to be treating to the properites it upon you make it private  , protected , public.

// for example make on child class inherit the properites
 class Teacher: private Human{
  int salary , id;

//   like this it will be private and cannot direclty acess need the function of constructor to make it or manipulate the data..
 };

int main(){
//  Student A1;
//  A1.name = "Gopal";
// A1.func("Gopal" , 20 , 12334);
Student A1("Gopal" , 20 , 1234, 1216 , "IT");
A1.display();
}