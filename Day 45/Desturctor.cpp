#include <iostream>
using namespace std;

 class Customer{
   public:
   string name;
   int *data;

//    construtor
  public:
//   Customer(string name , int b){
//     this->name = name;
//     data = new int;
//     *data = b;
//     cout<<"Constructor is called"<<endl;
//   }

// //   Destructor 
// // Here if we are creating the desctrutor the program will not make the destructor and there is not return type for destructor , only one destructor can only be written , there will be no argument or parameters in this destructor , and it is used the dynamically location realsing because it will be invoked last so it will releasing the dynamically location which we have taken..
//   ~Customer(){
//     delete data; //example dynamically releasing the data memory we have taken
//     cout<<"Destructor is called"<<endl;
//   }

// default constructor for dynamically with no argument
Customer(){
    name = "4";
 cout<<"Construtor is "<<name<<endl;
}

//   call order of constructor and destructor
  
// Here construtor is calling in the order wise 123
Customer (string name){
    this->name = name;
    cout<<"Construtor is "<<name<<endl;
}

// destructor
// destrutor is calling in reverse order 321
 ~Customer(){
    cout<<"Destructor is "<<name<<endl;
 }

 };

int main(){
  Customer A1("1"),A2("2"),A3("3");
//   dynamically creating the object
Customer *A4 = new Customer;
// for releasing the dynamically created object we have to delete in the main function then only it will deleted and and it will shown to in the destrutor
delete A4;
}