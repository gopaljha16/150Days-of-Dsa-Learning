#include <iostream>
using namespace std;

// Single inheritance
class Human
{

protected:
    string name;
    int age;

    //   constructor creating and then child can use that
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

public:
    //   Human(){
    //     cout<<"I am Human";
    //   }

    //   ~Human(){
    //     cout<<"I am Human";
    //   }

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
    // here consturctor is first parent is printing then the child constructor
    // Student(){
    //     cout<<" I am student"<<endl;
    // }

    // destructor will be printed the output reverse the child then the parent destructor
    // output   I am student
    // I am Human
    // ~Student(){
    //     cout<<" I am student"<<endl;
    // }

    //   for  exmaple if there are 2 same function named in the parent class and child class so first child is printing it will check that child if there is the display function then it will be printing the display then the parent the display function is there then it will printing that display;
    // void display()
    // {
    //     cout << name << " " << age << " " << roll_no << " " << fees << endl;
    // }
};

int main()
{
    Student A1("Gopal", 21, 16, 10000);
    // here the student inherited the properties and fucntions also so there is an work function which is public which can be directly callled
    // Student A1;
    // A1.work();
    A1.display();
}