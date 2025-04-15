// gfg question medium level Ways to sum to N
// class Solution
// {
//   public:
  
//     int waystoSum(int arr[] , int m , int sum){
        
//         // base case
//         if(sum==0)
//         return 1;
        
//         if(sum<0)
//         return 0;
        
//         long long ans = 0;
//         for(int i=0;i<m;i++){
//             ans+=waystoSum(arr , m , sum-arr[i]);
//         }
        
//         return ans%1000000007;
//     }
    
//     int countWays(int arr[], int m, int N) 
//     { 
//     return waystoSum(arr , m , N);
//     } 
    
// }; This code is not optimized.. so it will not run by using dp we can make it run all the test cases..