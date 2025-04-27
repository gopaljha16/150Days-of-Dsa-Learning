#include <iostream>
using namespace std;

class Customer{
     string name;
     int account_no;
     int balance;
    //  Here an consturcuted will be automatically called when an object is formed compiler will be making by thier ow which is called default constructor..

    // If we want to make by our own we can make the consturtor 
    public:
    // default constructor.
    Customer(){
        cout<<"Consturctor is created.";
        // we can give the value also 
        name = "Gopal jha";
        account_no = 12334;
        balance = 10000;
    }  // we can see the output that it will running automatically when an object is formed and it should the output which we have given in the constoructed

    // calling the getter method displaying the value
    void display(){
        cout<<" "<<name<<" "<<account_no<<" "<<balance<<" "<<endl;
    }

    // Parameterized Constructor 
    
    // Customer(string a , int b , int c){
    //     name = a;
    //     account_no = b;
    //     balance = c;
    // }
    
    // scope considering before writing the this pointer to handle this it will pointing to the original name.. age , balance which object has called that address is stored in the this pointer. 
    // Customer(string name , int age , int balance){
    //     this->name = name;
    //     this->account_no = age;
    //     // this->balance = balance;
    //     // Here we can give the value also 
    //     this->balance = 50;
    // }
    
    // Constructor Overloading is that constructor name is name but argumnet or paramerter are different then it is constructor overloading..
    Customer(string a , int b){
        name = a; 
        account_no = b;
    }

    // inline constructor like this we can creating the inline constructor and we hae to remove another paramterized becuase it has same 3 paramters and constructor cannot be redeclared so it will be giving the error. 
    inline Customer (string a , int b, int c): name(a) , account_no(b) , balance(c){

    }

    // customized copy construtor
    // here we have an issue that if we aare making the customized copy constructor then the comipler will be not making the default constructor and it will be calling copy copy and that the issue here we can to give the referce of he A2 TO B &b so now b-Points of the A2 and A2 --> Copies to the A3;
    Customer (Customer &B){
        name = B.name;
        account_no = B.account_no;
        balance = B.balance;
    }

};

int main(){
   
    Customer A1; 
    // parameterizeded basically giving the value when we are creating the object
    Customer A2("Gopal" , 1216 , 1000);
    // Copy consutructor :- here the compiler is automatically creating the copy construtor if we are not creating 
    Customer A3(A2);
    // calling the display to show in the output 
    A1.display();
    A2.display();
    A3.display();

    // Value Assiging using the Asingment operator
    Customer A6;
    A6= A2;
    A6.display();
}