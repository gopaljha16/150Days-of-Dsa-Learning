#include <iostream>
using namespace std;


 class Customer {
    
    string name;
    int account_no , balance;
    // here we know that we have to to count the total customer we need to make one thing in this first make it static and we have to initialzied this.
    static int total_customer; // This is an attribute of class or class member.
    // Here we can access this total_customer we can make it first public
    static int total_balance;

    public:
    Customer(string name , int account_no , int balance){
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        total_customer++; //incrementing the total_customer
        // balance adding to the total
        total_balance+=balance;
    }

    // static member function
    static void acessStatic(){
        cout<<"Total No of Customers "<<total_customer<<endl;
        cout<<"Total Balance "<<total_balance<<endl;
    }

    void deposit(int amount){
         if(amount>0){
            balance+=amount;
           total_balance+=amount;
         }        
    }

    void withdraw (int amount){
        if(amount<=balance && amount>0){
            balance-=amount;
            total_balance-=amount;
        }
    }

    void display(){
        cout<<name<<" "<<account_no<<" "<<balance<<endl;
    }

    void display_total(){
        cout<<total_customer<<endl;
    }

 };

 int Customer::total_customer=0;
 int Customer::total_balance=0;

int main(){
  Customer A1("Gopal" , 1 , 1222);
//   A1.display_total();
  Customer A2("Rohan" , 2 , 2000);
//   A2.display_total();
  Customer A3("Mohan" , 3 , 2222);
//   A3.display_total();
//   Here we can see that total custoemr is counting..

// we can assing the value by the class also but by making it public we can access this..
// Customer::total_customer = 5; 
// here now we can access this via static member function
Customer::acessStatic();
A1.deposit(3000);
Customer::acessStatic();
A1.withdraw(200);
Customer::acessStatic();


}