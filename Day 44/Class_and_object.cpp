#include <iostream>
using namespace std;

//    class creating
// class Student {
//   // public:
// private: //private accessing by using the function

// string name;
// int age ,  roll_no;
// string grade;

//   public: // first make the function public.
//   // setter function
//   void setName(string n){
//     if(n.size()==0){
//       cout<<"Empty name please enter the name";
//       return;
//     }
//     name = n ;
//   }

//   void setAge(int a){
//     if(a<0||a>100){
//       cout<<"Invalid age"<<endl;
//       return;
//     }
//     age = a;
//   }

// void setRoll_no(int r){
//   roll_no = r;
// }

//  void setGrade(string g){
//   grade = g;
//  }

// //  getter function
// void getName(){
//   cout<<name<<endl;
// }

// void getAge(){
//   cout<<age<<endl;
// }

// void getRoll_no(){
//   cout<<roll_no<<endl;
// }

// void getGrade(int pin){
//   // here we can add the condition that after adding the pin it should the grade orelse empty the string means the data protection could be done here..
//   if(pin==123){
//     cout<<grade<<endl;
//     return;
//   }

//   // if the pin is wrong then empty string.
//   cout<<" "<<endl;
// }

// };

// padding concept
//  class a{
//    char b;
//    int a;
//   char d;
//   double e;
//   //  empty class size is 1;
//  };

class Student
{
public:
  string name;
  int age, roll_no;
  string grade;
};


int main()
{
  //    creating an object here student is userdefined data type and object is variable
  // sttic memory allcation (stack)
  // Student s1;
  //  access the class properties by dot
  //  s1.name = "Gopal";
  //  s1.age = 21;
  //  s1.roll_no = 216;
  //  s1.grade = "A";

  //  cout<<s1.name;

  // setting the values to the setter function function calling
  // s1.setName("Gopal");
  // s1.setAge(21);
  // s1.setRoll_no(1216);
  // s1.setGrade("A+");

  // // getter function call
  // s1.getName();
  // s1.getAge();
  // s1.getRoll_no();
  // s1.getGrade(1234);

  //  a obj; // empty object size is 1;
  //  cout<<sizeof(obj)<<endl;

  // Dynamic memory allocation.s
  Student *s = new Student;

  // assiging the value 
  (*s).name = "Gopal";
  (*s).age = 20;
  (*s).roll_no = 1216;
  (*s).grade = "A+";

  // PRINTING using the arrow 
  cout<<s->name<<endl;
  cout<<s->age<<endl;
  cout<<s->roll_no<<endl;
  cout<<s->grade<<endl;
}
