#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int *p = &n; // single pointer     // it is pointing n value
    int **p1 = &p; // double pointer   // it is pointing p address
    int ***p2 = &p1; //triple pointer  //it is pointing p1 address
    int ****p3 = &p2; //four pointer.. // it is pointing p2 address
    
    // so changing the value 
    // single pointer 
    *p = *p +5;
    cout<<n<<endl;

    // double pointer;
    **p1 = **p1 + 5;
    cout<<n<<endl;

    // tripler pointer
    ***p2 = ***p2 + 5;
    cout<<n<<endl;

    // fourth pointer
    ****p3 = ****p3 + 5;
    cout<<n<<endl; 
}