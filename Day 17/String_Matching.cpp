// 28 . Find the Index of the First Occurrence in a String (easy level question in this we can do brute force and code will run..)

// class Solution {
//     public:
//       void lpsFind(vector<int>&lps , string &s){
//             int pre = 0 , suf = 1; // taking prefix and suffix
//             while(suf<s.size())
//             { //break condition when suffix is greater than string size
//             // if match 
//             if(s[pre] == s[suf]){
//                 // if matches then suf index add the pefix + 1 and increment prefix and suffix
//                 lps[suf] = pre + 1;  
//                 suf++ , pre++;
//             }
//             // doesn't match
//             else{
//                 // if pre = 0 then suf make is 0 and move forward 
//                 if(pre==0){
//                     lps[suf] = 0;
//                     suf++;

//                 }else{
//                     // if not 0 then pre take it's previous lps and go to that index prefix pointer
//                     pre = lps[pre - 1];
//                 }
//              }
//             }
//       }
    
//         int strStr(string haystack, string needle) {
//              vector<int>lps(needle.size() , 0); // new arrray lps stores lps initialized with the 0 
//             lpsFind(lps , needle); // lps function 
    
//             // initialized first and second 
//             int first = 0  , second = 0;
//             // break statement second greater than needle size and first is greater then haystack size..
//             while(second<needle.size() && first<haystack.size()){

//                 // if match increment second and first
//                 if(needle[second] == haystack[first]){
//                     second++;
//                     first++;
//                 }
//                 // if doesn't match then 
//                 else{
//                     // if second = 0 then first increment
//                     if(second == 0){
//                         first++;
//                     }
//                     // and if second is not 0 then second go to previous lps and index..
//                     else{
//                         second  = lps[second-1];
//                     }
//                 }
//             }
    
//             // if second has completed the iteration of it's string then return first - second answers
//             if(second == needle.size())
//             return first - second;
    
//             // if haystack has completed iteration then return -1;
//             return -1;
//         }
      
//     };