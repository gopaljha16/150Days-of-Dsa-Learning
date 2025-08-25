// Subarray sum divisible by k leetcode medium level problem 

// solution using prefix sum and hashing
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         //unordered map
//         unordered_map<int , int>m;
//         m[0] =1; //initially 
//         int prefixSum = 0 , rem , total = 0;

//         for(int i=0 ; i<nums.size(); i++){
//              prefixSum+=nums[i];

//              //remainder
//              rem = prefixSum%k;
             
//              if(rem<0) //for negative we can make positive
//               rem = k+rem;
            
//             if(m.count(rem)){
//                 total+=m[rem]; // increase total
//                 m[rem]++;
//             }else{ // if rem doesn't exisits
//                 m[rem] = 1;
//             }
//     }

//         return total;
//     }
// };

