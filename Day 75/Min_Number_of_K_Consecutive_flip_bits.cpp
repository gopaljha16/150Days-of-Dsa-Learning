// Minimum Number of K Consecutvie Flip Bits

//brute force code time complexity O(nk) space complexity O(1)
// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int flip = 0;
//         int n = nums.size();

//         for(int i=0; i<n ; i++){
//             if(nums[i]==0){ //o then flip to 1
//                 if(i+k-1>=n){
//                     return -1;
//                 }

//                 for(int j=i; j<=i+k-1 ; j++){
//                     nums[j] = !nums[j];
//                 }

//                 flip++;
//             }
//         }
//         return flip;
//     }
// };

//using the method -2 queue and the problem is being sovled in time compelxity O(n);

// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         queue<int>q;
//         int flip = 0;
//         int n = nums.size();

//       //traverse the array 
//       for(int i=0 ; i<n ; i++){
//            //if queue is front is less than the i then pop 
//            if(!q.empty() && q.front()<i){
//                     q.pop();
//            }

//            //logic odd even 1-odd then 0 1-even-then 1 then 0-odd-1 0-even-0
//            if(q.size()%2==nums[i]){
            
//             //edge case if there is not k elements left
//             if(i+k-1 >= n){
//                 return -1;
//             }

//             //push
//             q.push(i+k-1);
//             //increase flip
//             flip++;
//            }
//       }

//       return flip;
       
//     }
// };
