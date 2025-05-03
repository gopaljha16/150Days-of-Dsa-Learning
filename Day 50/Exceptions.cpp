#include <iostream>
#include <exception>
using namespace std;

// Exception Handling.
/* An Exception is an unexpected problem that arises during the execution of a program our program terminates suddenly with some errors/issues  . Exception occurs during the running of the program*/

// Try Block
/* The try keyword represents a block of code that may throw an exception placed inside the try block . It's followed by one or more catch blocks. If an exception occurs, try block throws that exception.*/

// Catch Block
/* The catch statement represents a block of code that is executed when a particular exception is thrown from the try block. The code to handle the exception is written insdie the catch block */

// Thows keyword
/* An exception in c++ can be thrown using the throw keyword.
When a program encounters a throw statement, then it immediately terminates the current function and starts finding a matching catch block to handle the throw exception */


// custom exception 
class InvalidAmountError : public runtime_error{
     public :
     
    InvalidAmountError(const string &msg): runtime_error(msg){

    };
};

class Customer{

     string name;
     int balance , acc_no;

     public:
     Customer(string name , int balance , int acc_no){
        this->name = name;
        this->balance = balance;
        this->acc_no = acc_no;
     }

     // deposit
     void deposit(int amount){
        if(amount>0){
            balance+=amount;
            cout<<amount<<" is credited to the account successfully\n";
        }else{
            throw runtime_error("amount should be greater than 0");
        }
     } 
     //withdraw
     void withdraw(int amount){
        if(amount>0 && amount<=balance){
         balance-=amount;
         cout<<amount<<" amount is debited from the account successfully\n";
        }else if(amount<0){
          throw runtime_error("amount should be greater than 0");
        }else{
            throw runtime_error("Insuffient balance");
        }
     }
};

int main(){
  Customer C1("Gopal" , 3000, 123);
  try{
    C1.deposit(100);
    C1.withdraw(3200);
  }
  // }catch(const char *e){
  //   cout<<"Exception occured :- "<<e<<endl;
  // }
  // here we are using the runtime_class
  catch(const InvalidAmountError &e){
    cout<<"Exception Occured : "<<e.what()<<endl;
  }


}