#include <iostream>
using namespace std;

bool CheckPalindrome(string str , int start , int end){

    //base (stoppage condition)
    if(start>=end)
    return 1;

    // condition checking not matching
    if(str[start]!=str[end])
    return 0;

    //  matching then call again..
    return CheckPalindrome(str , start+1, end-1);
}

int main(){
    string str = "mom";
    cout<<CheckPalindrome(str , 0 , 2);
}