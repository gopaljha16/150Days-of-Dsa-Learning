#include <iostream>
using namespace std;

int main(){
    // 1: Print sum of each column in 2D array.
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};

    int sum=0;
    for(int i=0;i<3;i++){
        sum=0;
        for(int j=0;j<3;j++){  
            sum+=arr[i][j];
        }
    }

    cout<<sum;
}