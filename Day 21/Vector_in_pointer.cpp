#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 void pass(vector<int>&v){
    for(int i = 0 ; i<5; i++){
        v[i ] = 10;
    }
 }

int main(){
    vector<int>v(5, 0); // 5 size 0 value;
    pass(v);
    for(int i = 0 ; i<5; i++){
       cout<<v[i ]<<" ";
    } // value is changed to the 10 
}