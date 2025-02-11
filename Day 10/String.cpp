#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // string s;
   //  cin>>s; // so in this we have an issue that if space , tab , enter comes to the string then it will end there only and further charater will not be printed this is an issue 
    //so in for this issue we can use getline(cin, 5)
    //getline(cin,s); // so in this it will accept the space and tab thing and print but one enter is that if we give the enter then it will end the string there only.. 
    //cout<<s;


    //size of the string we can get by the .size();
   // cout<<s.size(); // give the size of the string for 0

    // contacatination or adding two strings could be done by + operator
   //  string s1 = "Gopal";
   //  string s2 = "Jha";
   // string s3 = s1+s2; // "Gopal" + "Jha" = output GopalJha it will add both the stirngs;
    //another way 
//    string s3 = s1.append(s2) ;
//     cout<<s3; // then also it will give the same output 

//    we can insert element at the end and delete from the end by the push and pop operation
//    string s = "Gopal";
//    s.push_back('p');
//    cout<<s<<endl; // inserts the character at the end 
//    s.pop_back();
//    cout<<s<<endl; // deletes the character from the end

   //another way to attach at the end  // for 'j' single character and string "jha" 
//    string s1 = "Gopal";
//    s1 = s1+"Jh";
//    cout<<s1;


//    \ escape character expected printing  Gopal jha is a "good" boy directly we cannot print this if we use this it will give the error so we use escape charater basically it will eascape the things his and after that escape will be printed
 string s = "Gopal jha is a \"good\" boy"; // this will print that escape me and print my above one means the quotes it will be printing that..
//  if you want to print \ this also so it is possible 
string st = "\\"; //it will print the escape charater or else "\" if we doo this it will give the error
 cout<<st;


    // initialize 
    // string s = "Gopal Jha"; 
    // cout<<s;
}