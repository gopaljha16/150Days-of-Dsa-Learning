#include <iostream>
using namespace std;

void ReverseEachRow(int arr[][4] , int row , int col ){
   for(int i=0;i<row;i++){
     int start=0, end= col-1;
     while(start<end){
        swap(arr[i][start] , arr[i][end]);
        start++;
        end--;
     }
   }

//print the array..
   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<arr[i][j]<<" ";
    }
   }
}

int main(){

    // reverse each row of matrix
    int arr[3][4] = {2,3,4,5,1,2,6,8,4,9,3,2};

    // reverse each row
   ReverseEachRow(arr , 3,4);


}