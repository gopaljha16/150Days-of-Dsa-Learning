#include <iostream>
using namespace std;

int CountVowels(string str , int index){


    // base condition
    if(index==-1)
    return 0;

    // condtion matching 
    if(str[index]=='a' || str[index]=='e' || str[index]=='i' || str[index]=='o' || str[index]=='u'){
        return 1 + CountVowels(str , index-1);
    }else{
       return CountVowels(str , index-1);
    }
}

int main(){

    string str = "geiou";
    cout<<CountVowels(str , 4);
}