#include <iostream>
#include <vector>
using namespace std;

 void SubsetSum(int arr[] , int index , int n , int sum , vector<int>&ans){
 
    //base case 
    if(index==n){
        ans.push_back(sum);
        return;
    }

    // no 
    SubsetSum(arr , index+1 , n , sum , ans);
    // yes
    SubsetSum(arr , index+1 , n , sum+arr[index] , ans);
 }

int main(){
    int arr[]  = {3,4,5};
    vector<int>ans;
    SubsetSum( arr , 0 , 3,0  , ans);
    // print ans
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}