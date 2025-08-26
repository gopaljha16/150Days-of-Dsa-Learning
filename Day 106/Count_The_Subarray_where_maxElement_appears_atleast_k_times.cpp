//  Count the subarray where maxElement appears atleast k times leetcode medium level question 

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         long long total = 0;
//         int n = nums.size(), maxEle = 0;
           
//         //max element
//         for(int i=0 ; i<n ; i++){
//             maxEle = max(maxEle , nums[i]);
//         }

//         int start = 0 , end = 0 , count = 0;

//         while(end<n){ // loop will break when end will greater than the n
          
//            //increase the count of max element
//            if(nums[end]==maxEle){
//             count++;
//            }
         
//            while(count==k){ // if the count is equal to k then window decrease and total update
//              total+= n-end; // get the count of the windows addd them
//              if(nums[start]==maxEle){ // decreasing the count when maxElement gets 
//                 count--;
//              }
//              start++; //decrease the window
//            }

//            end++; //window increasing
              
//         }

//         return total;
//     }
// };