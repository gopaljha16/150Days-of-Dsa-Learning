#include <iostream>
using namespace std; 


 class Person{

     protected:
     string name;

     public:
     void introduce(){
        cout<<"My name is :- "<<name<<endl;
     }
 };

 class Employee: public Person{
    protected:
    int salary;

    public:
    void monthly_salary(){
        cout<<"My monthly salary is : - "<<salary<<endl;
    }
 };

 class Manager: public Employee{
    public:
    string department;

    public:
    Manager(string name , int salary , string department){
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void mydepartment(){
        cout<<"I am leadding an department :-  "<<department<<endl;
    }
 };


// Multi Level Inheritance
int main(){
  Manager A1("Gopal" , 2000 , "IT");
  A1.mydepartment();
  A1.monthly_salary();
   A1.introduce();
}