#include <iostream>
#include <vector>
using namespace std; 

 class Animal{
 
    public:
//    virtual void speak(){
//         cout<<"Huhu"<<endl;
//     }

// pure virtual function here we should give no code part 0 assiging and the condition is that it's object will no be created means we now that animal can;t speak here the specific animal dog , cat can speak so if you want to animal parent using and overiding to the object created we can use the pure virtual function wich is called as abstract class..
  virtual void speak()=0;
 };

 class Dog : public Animal{

     public:
     void speak(){
        cout<<"Bark"<<endl;
     }
 };

 class Cat : public Animal{

    public:
    void speak(){
       cout<<"Meow"<<endl;
    }
};




// Virtual Function
int main(){
//    Animal *p;
//    p = new Dog();
//    p->speak(); //here it will be printing the animal becuase it's deciding which class it is in the compile time we should use virtaul then it will running the runtime and the speak will be overide to the Dog() object which address you have stored.

//    we can create an Dog also but virtual function we can use this.
// this example code will be explaning all virual function which it overide in the runtime which object p has stored.and calling that function only
 Animal *p;
 vector<Animal*>animal;
 animal.push_back(new Dog());
 animal.push_back(new Cat());
 animal.push_back(new Dog());
 animal.push_back(new Cat());

  for(int i=0 ; i<animal.size() ; i++){
    p = animal[i];
    p->speak();
  }
}