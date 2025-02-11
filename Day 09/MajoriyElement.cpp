// Majority Element 169 Easy level leetcode question 

// int majorityElement(vector<int>& nums) {
//     int n=nums.size();
//     int candidate,count=0;
//     for(int i=0;i<n;i++){
//         if(count==0){
//             count =1;
//             candidate = nums[i];
//         }else{
//             if(candidate == nums[i]){
//                 count++;
//             }else{
//                 count--;
//             }
//         }
//     }

//     //verfiy the candidate is valid or not
//     count=0;
//     for(int i=0;i<n;i++){
//         if(nums[i]==candidate){
//             count++;
//         }
//     }

//     if(count>n/2)
//     return candidate;
//     else
//     return -1;
// }