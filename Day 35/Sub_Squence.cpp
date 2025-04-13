#include <iostream>
#include <vector>
using namespace std;

void Subseq(int arr[] , int index , int n , vector<vector<int> >&ans , vector<int>temp){
   
    // base case stoppage case 
    if(index==n){
        ans.push_back(temp); //temp value inserted putting into the ans
        return;
    }

    //No choosing
    Subseq(arr , index+1 , n , ans , temp);
    // yes chosing the element so inserting and moving 
    temp.push_back(arr[index]);
    Subseq(arr , index+1 , n , ans , temp);
}

int main(){
    int arr[] = {1,2,3};
    // 2d array for storing all the subsequence
    vector<vector<int> >ans;
    // temporary array for inserting the subsequens
    vector<int>temp;
    Subseq(arr , 0 , 3 , ans , temp);

    // print
    for(int i=0;i<ans.size();i++){
       for(int j=0 ; j<ans[i].size() ; j++){
                cout<<ans[i][j]<<" ";
       }
       cout<<endl;
    }
}

// Leetcode medium question 78. Subsets 
// here optimized the space complexity where we have taken the only one temp as an reference and adding and then after completion deleting from the temp..
// class Solution {
//     public:
          
//           void Subseq(vector<int> &arr , int index , int n , vector<vector<int>>&ans , vector<int>&temp){
//             //   base case
//              if(index==n){
//                 ans.push_back(temp);
//                 return;
//              }
    
//             // no
//             Subseq(arr , index+1 , n , ans , temp);
//             // yes including the subset
//             temp.push_back(arr[index]);
//             Subseq(arr , index+1 , n , ans , temp);
//             temp.pop_back();
//           }
    
//         vector<vector<int>> subsets(vector<int>& nums) {
//             vector<vector<int >>ans;
//             vector<int>temp;
//             Subseq(nums , 0 , nums.size() , ans ,temp);
    
//             return ans;
//         }
//     };