#include <iostream>
using namespace std;


class Human{
    public:
    string name;

    void display(){
        cout<<"My name is "<<name<<endl;
    }
};

// here we will be getting the error so becuase of it;s getting 2 times name and display function because of both enginner and employe inherting the same human and it's will confusing which name display so we have to use virtual it know that its has only one name display one thing both it;s inherts and the error it will fixed and working fine..
class Engineer : public virtual Human{

    public:
    string specilization;

    void myspecilization(){
       cout<<"My specilization is "<<specilization<<endl;
    }
};

class Employee : public virtual Human{
   public:
   int salary;

    void mySalary(){
   cout<<"My salary is :- "<<salary;

    }
};

class Student: public Engineer , public Employee{
   public:
   string age;

//    Default constructor.
   Student(){

   }

   Student(string name , string specilization , int salary , int age){
       this->name = name;
       this->specilization = specilization;
       this->salary = salary;
       this->age = age;
   }

};


// Multipath inheritance.
int main(){
  Student A1("Gopal" , "Webdev" , 20000 , 21);
  A1.display();
}