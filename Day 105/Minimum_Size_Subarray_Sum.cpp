//  Minium Size Subarray Sum leetcode medium level question

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size() , total = INT_MAX , start = 0 , end = 0 , sum = 0;

//         while(end<n){
//             //sum 
//             sum+=nums[end];
            
//             //so here the sum of element is greater than target  so we should minimize and get the minimum sub array count..
//             while(sum>=target){
//                 total = min(total, end -start+1); // it will get the minium total
//                 sum-= nums[start++]; // sohere we are minimizing the window then decrease thesum
//             }
//             end++; //move end if the sum is not equal to target
//         }

//         return total==INT_MAX ? 0 : total;
//     }
// };