#include <iostream>
using namespace std;

int main(){
    // first diagonal and second diagonal and in this the row==col then only diagonal sum is possible 

    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    // // first diagonal 
    // int first =0;
    // for(int i=0;i<4;i++){
    //     first+=arr[i][i];
    // }

    // cout<<"First diagonal"<<first<<endl;

    // second diagonal
    int second =0 , i=0,j=3;
    while(j>=0){
        second+=arr[i][j];
        i++;
        j--;
    }

    cout<<"Second Diagonal Sum "<<second;
}