#include <iostream>
using namespace std;

int main(){
    //  Smallest Element: Find and print the smallest element in the 2D arrays.
    
   int arr[3][3] = {9,4,3,5,4,3,1,6,2};

   int smallEle = arr[0][0];
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(arr[i][j]<smallEle){
            smallEle = arr[i][j];
        }
    }
   }
    cout << "Smallest number is: " << smallEle << endl;
} 