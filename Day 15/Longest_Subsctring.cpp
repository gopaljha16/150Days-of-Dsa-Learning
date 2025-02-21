// Longest Substring without repeating characters (leetcode question medium level)

// class Solution {
//     public:
//         int lengthOfLongestSubstring(string s) {
//             vector<bool>count(256, 0); // 256 and initialized by 0
//             int first = 0, second = 0 , len = 0;
    
//             // break condition second if greater than  the size of string
//             while(second < s.size()){
//                 // repeated char then this condition 
//                 while(count[s[second]]){ 
//                     count[s[first]] = 0;
//                     first++;
//                 }
         
//                 // update the second
//                 count[s[second]] = 1;
//                 // length of the charters which are unique  
//                 len = max(len , second - first+1);
//                 //increment the second
//                 second++;
//             }
//             return len;
//         }
//     };