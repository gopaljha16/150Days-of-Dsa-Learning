#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // print row index with max sum
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int sum=INT32_MIN , index=-1;

    for(int i=0;i<4;i++){
        int total = 0;
        for(int j=0;j<4;j++){
            total+=arr[i][j];
            if(sum<total){
                sum = total;
                index = i;
            }
        }
    }
 
 //prints the index of the row..
    cout<<index;
}