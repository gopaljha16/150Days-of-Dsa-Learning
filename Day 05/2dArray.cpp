#include <iostream>
using namespace std;

int main(){

    // creation
   // int arr[4][3] ; //means 4 row and 3 column
   // initialization 
   int arr[4][3]  = {1,2,3,4,5,6,7,8,9,10,11,12};
//    value printing
for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j]<<" ";
    }
}
}