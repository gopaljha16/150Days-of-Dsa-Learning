#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr = {1,0,1,0,1,0};
    // sort the array by vector
    // sort(arr.begin() , arr.end()); time complexity O(nlogn)
    int n = arr.size();
    //time completexity O(n)
    // int count0 =0;
    // int count1=0;

    // for(int i=0;i<n;i++){
    //   if(arr[i]==0){
    //     count0++;
    //   }else{
    //     count1++;
    //   }
    // }

    // //adding the 0 now..
    // for(int i=0;i<count0;i++){
    //     arr[i]=0;
    // }

    // //adding 1 
    // for(int i=count0 ; i<n ; i++){
    //     arr[i]=1;
    // }

    // //printing array
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //by using two pinter 
    int start =0,end=n-1;  // time complexity O(n) in one iteration all done..
    while(start<end){
        if(arr[start]==0)
        start++;
        else{
            if(arr[end]==0){
                swap(arr[start], arr[end]);
                start++;
                end--;
            }else{
                end--;
            }
        }
    }

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}