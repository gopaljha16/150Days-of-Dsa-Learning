#include <iostream>
using namespace std;

 class Customer{
    string name;
    int balance ,  age; 
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

    // here the depoist is happening in internally it should user shouln;t know that how it's working at the it work and give the output
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

// Abstraction :- Displaying only Essential Information and Hiding the details
// Here the basically the definition says that we don't need any intenral details it just should work that's the only user here interal details are hiddeen how it's working in backend type how for example sign up in an website howit's creating in the database the account and we login how it's login that we don't need to know we should only know it's giving the output..
int main(){
  Customer A1("Gopal" , 1000, 21);
  A1.deposit(5000);
  A1.display();
}