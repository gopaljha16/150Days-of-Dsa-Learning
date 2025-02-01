// gfg code
//  int maxSubarraySum(vector<int> &arr) {
//         // Your code here
//         int n= arr.size();
//         int prefix = 0, maxi= INT_MIN;
//         for(int i=0;i<n;i++){
//             prefix+=arr[i];
//             maxi = max(maxi , prefix);
//             if(prefix<0)
//             prefix=0;
//         }
        
//         return maxi;
//     }