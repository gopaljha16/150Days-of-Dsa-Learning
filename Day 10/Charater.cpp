#include <iostream>
using namespace std;

int main(){
    //charater creating 
    // char arr[] = {'a','b','c','d','e'};
    // // printing char
    // for(int i=0;i<5;i++)
    // cout<<arr[i];

    // another way 
    // char chart[20]; // 20 size
    // cin>>chart;
    // cout<<chart;

    //null charater "\0" which where ever its sees in this it will end and before that only charaters will be printed..
    // null charater will assined in every size of array last for example arr[20] 20 size 0-19 in 19 index it will resevered the null charater
    char arr[20];
    cin>>arr;
    arr[2] = '\0';
    cout<<arr;
    // input gopal
 //  output go means in this where the null charater is there then it will print that only above the null charater will not be printed..  
}