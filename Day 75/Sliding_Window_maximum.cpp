// Sliding Window Maximum leetcode hard level quuestion

// Brute Force Approch time complexity O(nk);

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>ans;
//         int n = nums.size();
        
//         for(int i=0 ; i<=n-k ; i++){
//             int total = INT_MIN;
//             for(int j=i ; j<i+k  ; j++){
//                 total = max(total , nums[j]);
//             }
//             ans.push_back(total);
//         }

//         return ans;
//     }
// };
//The above code gets the time limit exceeded so this is not the apporch it needs the O(N);

//method 2 using the dequeue to front and back popping
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         deque<int>d;
//         vector<int>ans;

//         //k-1 element traversing
//         for(int i=0 ; i<k-1 ; i++){
//           //if empty deque
//           if(d.empty()){
//             d.push_back(i);
//           }else{ //not empty
//               while(!d.empty() && nums[i]>nums[d.back()]){ //here the nums is greater than the back element then pop..(smaller element popping)
//                 d.pop_back();
//               }
//               d.push_back(i);
//           }
//         }

//         ///k-1 to n travesal window traversing
//         for(int i=k-1; i<n ; i++){
//             //popping the smaller element form deque
//             while(!d.empty() && nums[i]>nums[d.back()]){
//                 d.pop_back();
//             }
//             d.push_back(i); //the qeueue is empty or the element is greater then push the element into the deque
//             //popping the front element which is out the window
//             if(d.front()<=i-k){
//                 d.pop_front();
//             }
//             //pushing the front element (becuase it's the maximum element)
//             ans.push_back(nums[d.front()]);
//         }

//         return ans;
//     }
// };