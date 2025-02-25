#include <iostream>
using namespace std;

int main(){
    int num = 20;
    int &temp = num;
    temp = temp +1 ;
    cout<<num; // by this it will point that value num value so when we change the temp then it will reflect the changes to the num also.. 

    // num and temp are same; 
}