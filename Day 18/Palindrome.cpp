// Min Chars to Add for Palindrome (gfg hard question)

// int minChar(string& s) {
        
//     // reverse of string
//     string rev = s;
//     reverse(rev.begin() , rev.end());
//     int size = s.size();
     
//     // attach to the original string $ dollar sign for diffrenctiation
//     s+='$'; //seperator
//     // then string + reverse
//     s+=rev; //reverse added
    
//     // lps longest prefix suffix
//     int n = s.size();
//     vector<int>lps(s.size() , 0);
//     int pre = 0 , suf = 1;
//     while(suf<s.size()){
//         // if match 
//         if(s[pre]==s[suf]){
//             lps[suf] = pre + 1;
//             pre++ , suf++;
//         }else{
//             if(pre==0){
//                 lps[suf] = 0;
//                 suf++;
//             }else{
//                 pre = lps[pre -1];
//             }
//         }
//     }
    
//     return size - lps[n-1];
    
// }