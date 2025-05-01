#include <iostream>
using namespace std;
 
class Engineer{

     public:
     string specilization;

     void myspecilization(){
        cout<<"My specilization is "<<specilization<<endl;
     }
};

class Employee{
    public:
    int salary;

     void mySalary(){
    cout<<"My salary is :- "<<salary;

     }
};

// here the construtor will be printed which you have gave for example engineer will be first then employee then student if you change employee first then employee then engineer then student constructor..
class Student: public Engineer , public Employee{
    public:
    string name;

    Student(string name , string specilization , int salary){
        this->name = name;
        this->specilization = specilization;
        this->salary = salary;
    }

    void showcase(){
        cout<<"My name is "<<name<<endl;
        myspecilization();
        mySalary();

    }
};



// multiple inheritance
int main(){
  Student S1("Gopal" , "Web Developer" , 120000);
  S1.showcase();
}