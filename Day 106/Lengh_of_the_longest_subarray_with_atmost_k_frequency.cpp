//  Lenght of the longest subarray with atmost k frequency leetcode medium level question

//sliding window approach
// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int len = 0; // store the window length which we will be returining
//         unordered_map<int,  int>count; //which contains the element and their count
         
//         int start = 0 , end = 0;
//         while(end<nums.size()){ // if end will greater than nums size then while loop break
            
//             //count increase
//             count[nums[end]]++; //element count

//             //if the count greater than the k element then window decrease
//             while(count[nums[end]]>k){
//                 count[nums[start]]--; // decreasing so first updating the count
//                 start++; //decrasing the window
//             }
//             //window increase
//             len = max(len , end-start+1); //update the window length
//             end++; // increase the window size..
//         }

//         return len;
//     }
// };