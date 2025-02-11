#include <iostream>
using namespace std;

int main(){
    string s  = "Gopal";
    //reverse the string 
    int start = 0 , end = s.size()-1;
    while(start<end){
        swap(s[start] , s[end]);
        start++;
        end--;
    }
    //print the string
    cout<<s;
}