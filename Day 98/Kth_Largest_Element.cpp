//Kth largest element in the array leetcode medium level question 

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         //minheap 
//         priority_queue<int,vector<int>, greater<int>>p;

//         //insert k elements in queue
//         for(int i=0 ; i<k ; i++)
//             p.push(nums[i]);

//         //now other elements comparing 
//         for(int i=k ; i<nums.size() ; i++){
//             //comapre the p.top whcih is smallest element so here if the comapre is nums[i] is greater then top element delete and push the nums[i] element
//             if(nums[i]>p.top()){
//                 p.pop();
//                 p.push(nums[i]);
//             }
//         }

//         return p.top(); //min element
//     }
// };