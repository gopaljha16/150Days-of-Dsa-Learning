#include <iostream>
using namespace std;

void PrintCol(int arr[][4], int row , int col){
//    column vise printing
   for(int j=0;j<col;j++){
    for(int i=0;i<row;i++){
        cout<<arr[i][j]<<" ";
    }
   }
}

int main(){
    // search element in 2d array 
    int row , col;
    cout<<"Enter the size of the array";
    cin>>row;
    cin>>col;
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16} ;
    // cout<<"Enter the elements into the array";
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // int target ;
    // cout<<"Enter your element for searching";
    // cin>>target;
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //        if(arr[i][j]==target){
    //         cout<<"Yes Element is present in the array";
    //         return 0;
    //        }
    //     }
    // }
    // cout<<"No element is not present in the array";

     cout<<"col wise";
     PrintCol(arr, 4 ,4);
    
}