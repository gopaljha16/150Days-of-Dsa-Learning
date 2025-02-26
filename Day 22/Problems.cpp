#include <iostream>
using namespace std;

    void second(int *p1 , int *p2){
        p1 = p2;
        *p2 = 2;
    };

    int fifth(int x , int *py , int **ppz){
        int y , z;
        **ppz+=1;
        z = **ppz;
        *py+=2;
        y = *py;
        x+=3;
        return x+y+z;
    };

    void sixth(char *str1 , char *str2){
        while((*str1 = *str2)){
            str1++ , str2++;
        }
    }

int main(){
    // first problem
    // char c[] = "Gate2024";
    // char *p = c;
    // cout<<p+p[3]-p[1]; // output  is 2024

    // second prblem
    // int i = 0 , j = 1;
    // second(&i , &j);
    // cout<<i<<" "<<j; // output is 0 2

    // third problem
    // int *ptr ;
    // int  x = 0;
    // ptr = &x;
    // int  y = *ptr ;
    // *ptr = 1;
    // cout<<x<<" "<<y; // output is 1 0

    // // fourth problem 
    // int a = 5 , b =10;
    // int &name = a;
    // int *ptr = &a;
    // (*ptr)++;
    // ptr = &b;
    // *ptr = *ptr+5;
    // name+=5;
    // cout<<a<<" "<<b; // output is 11 15

    // fifth problem 
    // int c, *b , **a;
    // c = 4 , b = &c , a = &b;
    // cout<<fifth(c, b, a); // 19 will be the output

    // sixth problem 
    char first[] = "Rohit";
    char second[] = "Gopal";
    sixth(first , second);
    cout<<first; // it output is gopal like we are copying the string  second to first...
}