#include <iostream>
using namespace std;

int main(){
  //calculate the size of the string
  //this calculates the size of the string..
  string s = "Gopal"; // in string sy
  int size = 0;
  while(s[size]!='\0'){  // it checks the null character if it is equal to then it will break the loop
    size++;
  }
  cout<<size;
}