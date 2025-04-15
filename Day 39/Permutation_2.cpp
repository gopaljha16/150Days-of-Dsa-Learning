// leetcode permutation 2 medium level question 


// class Solution {
//     public:
       
//        void permute2(vector<int> &arr , vector<vector<int> > &ans , int index ){
    
//         // base case
//         if(index==arr.size()){
//             ans.push_back(arr);
//             return;
//         }
    
//         // visited booleans
//         vector<bool>visited(21, 0);
    
//         // iterating and swaping with checking the condition
//         for(int i=index; i<arr.size() ; i++){
//             if(visited[arr[i]+10]==0){
//                 swap(arr[index] , arr[i]); //swap it
//                 permute2(arr , ans , index+1); ///call again 
//                 swap(arr[index] , arr[i]); // original position
//                 visited[arr[i]+10]= 1; //update to 1 visited
//             }
//         }
//        }
    
//         vector<vector<int>> permuteUnique(vector<int>& nums) {
//             vector<vector<int> >ans;
//             permute2(nums , ans , 0);
    
//             return ans;
//         }
//     };
    
    
    