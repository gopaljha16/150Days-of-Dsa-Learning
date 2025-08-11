#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    int age;
    string name;

    bool operator < (const Person &other) const{
        return age>other.age;
    } // so here it's using the operator for printing the values in order it happending the peson first object will be there and other object will be passsing an the operator so hee it's age is first object and other.age is another object if true false comes then the data changes sorted order changes..
};

int main(){
    // set<int, greater<int>>s; // here we can use the greater for it will be getting the data in reverse or greater element will come first then small means decreasing order..
    // s.insert(10);
    // s.insert(20);
    // s.insert(30);
    // s.insert(40);
    // s.insert(1000);
    // s.insert(1010);
    // s.insert(1010);

    // //for printing iteration will be there it will be there..

    // for(auto it=s.begin() ; it!=s.end() ;it++){
    //     cout<<*it<<" ";
    // }

    //search the element find operation 
    // if(s.find(20)!=s.end()){ // so it will search the element finding if the element get then present if didn't get then it will go till end and move last and then 0 it will be returing 
    //     cout<<"Present";
    // }else{
    //     cout<<"Not Present";
    // }

    //we can use the count also for checking the element is present in the set
//    if(s.count(10)) // so here it will be chcecking the element it present if it returns 1 then present or else 0 then absent
//     cout<<"Present";
//     else
//     cout<<"Absent";

//     //normally also we can use this
//     cout<<s.count(20)<<" "<<endl; //returns 1 or 0

  //delete operation
//   s.erase(10);
//      for(auto it=s.begin() ; it!=s.end() ;it++){
//         cout<<*it<<" ";
//     }


  // set using in the class 
  
 set<Person>s;
 Person p1,p2,p3;
 p1.age = 20 , p1.name = "Gopal";
 p2.age = 30 , p2.name = "Gopu";
 p3.age = 40 , p3.name = "Npu";

 //now insert the objects
 s.insert(p1);
 s.insert(p2);
 s.insert(p3);

 //print
 for(auto it=s.begin() ; it!=s.end() ; it++){
    cout<<it->age<<" "<<it->name<<endl;
 }
}