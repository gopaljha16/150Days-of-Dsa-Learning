//  Count Subarray with k different element leetcode hard level question

// atleast k approch 

// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int total=0; //which we will be returing the to the answer
//         unordered_map<int ,int>freq; //freqeuncy counting

//         int start = 0 , end = 0, n = nums.size() , count = 0;
//        //so here solving by using the atleast approch atleast(k)-atleast(k+1)
//         while(end<n){
//             //freqeuncy updating
//             freq[nums[end]]++;

//             if(freq[nums[end]]==1)
//               count++;
            
//             //window length increase till number of different integer are equal to k
//             while(count==k){
//                 total+=n-end; //update the k
//                 freq[nums[start]]--; //frequency update

//             if(freq[nums[start]]==0) //freq decrease count also decrease
//               count--;

//             start++; //window decrease
//             }
//           end++; //increase the window
//         }

//         //atleast(k+1)
//         start = 0 , end = 0 , count = 0;
//         freq.clear(); //map clear
//         k++; //increase the k
        
//         while(end<n){
//             //freqeuncy updating
//             freq[nums[end]]++;

//             if(freq[nums[end]]==1)
//               count++;
            
//             //window length increase till number of different integer are equal to k
//             while(count==k){
//                 total-=n-end; //update the k
//                 freq[nums[start]]--; //frequency update

//             if(freq[nums[start]]==0) //freq decrease count also decrease
//               count--;

//             start++; //window decrease
//             }
//           end++; //increase the window
//         }
//         return total;      
//     }  
// };