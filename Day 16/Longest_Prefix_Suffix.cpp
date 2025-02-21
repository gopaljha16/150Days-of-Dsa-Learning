// Longest Prefix Suffix ( hard level gfg question)


// int longestPrefixSuffix(string &s) {
//     vector<int>lps(s.size() , 0); // string size and initailzed with t 0
//     int pre = 0 , suf = 1 ; // prefix and suffix postion 
    
//     // break condition suffix is greater than string size
//     while(suf<s.size()){
//         // prefix and suffix match 
//         if(s[pre]==s[suf]){
//             lps[suf] = pre + 1; // if matches then lps suffix postion then prefix + 1
//             pre++; // move forward
//             suf++; // move forward
//         }
//         // else case if doesn't matches
//         else{
//             if(pre==0){ // prefix is equal to 0 then 
//                 lps[suf] = 0; // lps of suffix make it 0
//                 suf++; // and move forward suffix
//             }else{ // in this prefix indication previous one go and set on that index..
//                 pre = lps[pre - 1];
//             }
//         }
        
//     }  
//     return lps[s.size() -1 ];  // return last index ans
    
// }