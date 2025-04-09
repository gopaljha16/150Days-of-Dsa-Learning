// LEETCODE MEDIUM LEVEL QUESTION  912. Sort an Array


// class Solution {
//     public:
    
//       void Merge(vector<int> &arr , int start , int mid , int end){
//         vector<int>temp(end-start+1);
//         int index=0 , left = start , right = mid+1;
    
//         while(left<=mid && right<=end){
//             if(arr[left]<arr[right]){
//                 temp[index] = arr[left];
//                 index++, left++;
//             }else{
//                temp[index] = arr[right];
//                 index++, right++;
//             }
//         }
    
//         // left out side left and right
//         while(left<=mid){
//           temp[index] = arr[left];
//           index++ , left++;
//         }
    
//         // right side
//         while(right<=end){
//             temp[index]= arr[right];
//             index++, right++;
//         }
    
//         // adding to the original array
//         index =0;
//         while(start<=end){
//             arr[start] = temp[index];
//             start++ , index++;
//         }
//       }
    
    
//        void MergeSort(vector<int>&arr , int start , int end){
//         //    base case 
//         if(start==end)
//          return;
    
//          int mid = start + (end-start)/2;
//         MergeSort(arr, start , mid); //left side
//         MergeSort(arr,mid+1 , end); //right side
//         Merge(arr, start , mid , end);
//        }
    
//         vector<int> sortArray(vector<int>& nums) {
//             MergeSort(nums , 0 , nums.size()-1);
    
//             return nums;
//         }
//     };