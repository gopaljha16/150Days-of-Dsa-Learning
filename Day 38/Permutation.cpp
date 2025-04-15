#include <iostream>
#include <vector>
using namespace std;

  void Permutation(int arr[] , vector<vector<int> >&ans , vector<int>&temp , vector<bool>&visited){

    // base case
    if(visited.size()==temp.size()){
        ans.push_back(temp);
        return;
    }

    //loop creating that cheks visited or not so here no visisted then it will be visted[i] = 1 and temp into that element then function calling again  then visited making 0 and empty that pop back
    for(int i=0 ; i<visited.size() ; i++){
        if(visited[i]==0){
            visited[i] =1;
            temp.push_back(arr[i]);
            Permutation(arr , ans , temp , visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
  }

int main(){

    int arr[] = {1,2,3,4};
    vector<vector<int> >ans;
    vector<int>temp;
    vector<bool>visited(4,0); //size 3 and values 0
    Permutation(arr , ans , temp , visited);

    // ans printing
    for(int i=0 ; i<ans.size() ; i++){
     for(int j=0 ; j<ans[i].size() ; j++)
     {
        cout<<ans[i][j]<<" ";
     }
     cout<<endl;
    }
}

// leetcode permutation question 
// class Solution {
//     public:
    
//       void Permutation(vector<int>&arr , vector<vector<int> >&ans , vector<int>&temp , vector<bool>&visited){
    
//         // base case
//         if(visited.size()==temp.size()){
//             ans.push_back(temp);
//             return;
//         }
    
        
//         for(int i=0 ; i<visited.size() ; i++){
//             if(visited[i]==0){
//                 visited[i] =1;
//                 temp.push_back(arr[i]);
//                 Permutation(arr , ans , temp , visited);
//                 visited[i] = 0;
//                 temp.pop_back();
//             }
//         }
//       }
    
//         vector<vector<int>> permute(vector<int>& nums) {
//             vector<vector<int> >ans;
//             vector<int>temp;
//             vector<bool>visited(nums.size() , 0);
//             Permutation(nums , ans , temp , visited);
    
//             return ans;
//         }
//     };