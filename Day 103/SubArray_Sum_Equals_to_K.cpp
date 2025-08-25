// Subarray sum equals to k leetcode medium level question

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int , int>m;
//         m[0] =1; //intially adding to map becuase edge case
//         int prefixSum = 0;
//         int total = 0;

//         //iteration 
//         for(int i=0 ; i<nums.size(); i++){
//             prefixSum+=nums[i];
//             if(m.count(prefixSum-k)){
//                 total+=m[prefixSum-k];
//                 m[prefixSum]++;
//             }else{
//                 m[prefixSum]++;
//             }
//       }

//       return total;
//     }
// };