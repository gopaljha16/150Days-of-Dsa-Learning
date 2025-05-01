#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    int age;

//   here it will be giving the error becuase there is no defualt constructor so for fixing the error we have to give the default constructor
    Human(){

    }

    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

public:
    void display()
    {
        cout << name << " " << age << endl;
    }

    void work()
    {
        cout << "I am working" << endl;
    }
};

class Student : public Human
{

    int roll_no, fees;

    //  here it is inheriting the parent properties and entering the value by via constructor function
public:
    Student(string name, int age, int roll_no, int fees) : Human(name, age)
    {
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
        this->fees = fees;
    }

public:
    void display()
    {
        cout << name << " " << age << " " << roll_no << " " << fees << endl;
    }
};

class Teacher : public Human
{
    public:
    int salary;

    Teacher(string name, int age, int salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void display()
    {
        cout << name << " " << age << " " << salary << endl;
    }
};

// Hirarchical Inheritance. :- One base class and multiple child classes.
int main()
{
    Teacher T1("Gopu" , 22, 999);
    T1.display();
   
}