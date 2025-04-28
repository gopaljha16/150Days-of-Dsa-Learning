#include<iostream>
using namespace std;


 class Customer{
    string name;
    int balance ,  age; //he we know we shouldn not give the acces public because the data could be manipulated by the user..
    // and it should be access by using the the function with the condition making that user could not enter any misalinious data that harm or wrong information of the user or user manipulation

    public:

    Customer(string name , int balance , int age){
        this->name = name;
        this->balance = balance;
        this->age = age;
    }

    // for example age limitation
     
    void ageVerfiy(int age){
        if(age<0 && age>100){
            cout<<"Invalid Age";
        }
    }

    void deposit(int amount){
        if(amount>0){
            balance+=amount;
        }else{
            cout<<"Invalid Amount"<<endl;
        }
    }

    void withdraw(int amount){
        if(amount<=balance && amount>0){
            balance-=amount;
        }else{
            cout<<"Invalid amount Please fix it."<<endl;
        }
    }

    void display(){
        cout<<name<<" "<<balance<<" "<<age<<" "<<endl;
    }
 };

// Encapsulation :- Wrapping up of a data and information in a single unit , while controlling access to them..(basically here we are doing that user should not get the direct acess becuase they can make it dirtly and manipulate the data) so we will be giving the access via function in function we can give the condition if that matches then only it will be manupulating the value or else it will not be valid then not changes will occur
int main(){
   
    Customer A1("Gopal" , 1000 , 20);
    A1.deposit(-20); //here user is trying to manipulate the amount but for function there is an validation that checks then only it will doing and if it doesn't matches the condition then there will be the issue..and it will not be added or working 
    // So here all the things should be private and via function it should do..
    A1.display();

}