//  SubArryay product less than k leetcode medium level problem

// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size() , count = 0 , product = 1 , start = 0 , end = 0;
//         if(k<=1) return 0;
//         while(end<n){
//             product*=nums[end];// product 

//             // if the product value is greater than the key then window decrease
//             while(product>=k){
//                 product/=nums[start];
//                 start++; //window increasing
//             }

//             // if not big then 
//             count+= end-start+1;
//             end++; 
//         }

//         return count;
//     }
// };

// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size() , count = 0 , product = 1 , start = 0 , end = 0;

//         while(end<n){
//             product*=nums[end];// product 

//             // if the product value is greater than the key then window decrease
//             while(product>=k &&start<=end){
//                 product/=nums[start];
//                 start++; //window increasing
//             }

//             // if not big then 
//             count+= 1+(end-start);
//             end++;
//         }

//         return count;
//     }
// };


// gfg medium level question prodcut less than k



// class Solution {
//   public:
//     long long countSubArrayProductLessThanK(const vector<int>& arr, int n,
//                                             long long k) {
                                            
//          long long  count = 0 , product = 1 , start = 0 , end = 0;
       
//          if(k<=1) return 0;
//         while(end<n){
//             product*=arr[end];// product 

//             // if the product value is greater than the key then window decrease
//             while(product>=k){
//                 product/=arr[start];
//                 start++; //window increasing
//             }

//             // if not big then 
//             count+= 1+(end-start);
//             end++;
//         }

//         return count;
//                                             }
// };