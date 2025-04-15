#include <iostream>
#include <vector>
using namespace std;  

void permutation(vector<int>&arr , vector<vector<int>>&ans , int index ){

    // base case
    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size() ; i++){
        // swap it first
        swap(arr[index] , arr[i]);
        permutation(arr , ans ,index+1);
        // again swap it becuase after the function call it should come to its original position 
        swap(arr[index] , arr[i]);
    }
} 


int main(){
    vector<int>arr = {1,2,3};
    vector<vector<int>>ans;
    permutation(arr , ans , 0);

    //print ans
    for(int i=0;i<ans.size() ; i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}