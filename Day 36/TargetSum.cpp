#include <iostream>
#include <vector>
using namespace std;

bool TargetSum(int arr[] ,int index , int n , int target ){
    //base case
    if(target==0)
    return 1;
    
    if(index==n || target<0)
    return 0;

    //here we are trying the approach the left or right so here the advantage is that if it get 1||0 then it will not check the right side
    return TargetSum(arr ,index+1 , n , target) || TargetSum(arr , index+1 , n , target-arr[index]);
}

int main(){
    int arr[] = {2,3,6};
    int target = 10;
    cout<<TargetSum(arr , 0 , 3 , target);
}