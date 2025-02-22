// 686. Repeated String Match Leetcode medium level question 

// void lpsFind(vector<int>&lps , string &s){
//     int pre = 0 , suf = 1; // taking prefix and suffix
//     while(suf<s.size())
//     { //break condition when suffix is greater than string size
//     // if match 
//     if(s[pre] == s[suf]){
//         lps[suf] = pre + 1;  
//         suf++ , pre++;
//     }
//     // doesn't match
//     else{
//         if(pre==0){
//             lps[suf] = 0;
//             suf++;
//         }else{
//             pre = lps[pre - 1];
//         }
//      }
//     }
// }

// int kmp_match(string haystack, string needle) {
//      vector<int>lps(needle.size() , 0); // new arrray lps stores lps initialized with the 0 
//     lpsFind(lps , needle); // lps function 

//     // initialized first and second 
//     int first = 0  , second = 0;
//     while(second<needle.size() && first<haystack.size()){
//         if(needle[second] == haystack[first]){
//             second++;
//             first++;
//         }
//         else{
//             if(second == 0){
//                 first++;
//             }
//             else{
//                 second  = lps[second-1];
//             }
//         }
//     }

//     if(second == needle.size())
//     return 1;

//     return 0;
// }

// int repeatedStringMatch(string a, string b) {
//     // if match 
//     if(a==b)
//     return 1;

//     int repeat =1;
//     string temp = a ;//this holds an a

// //    break condition temp is greater tan size break loop
//     while(temp.size()<b.size()){
//         temp+=a;
//         repeat++;
//     }

//     // kmp pattern search
//     if(kmp_match(temp , b) == 1)
//     return repeat; // if matches then reperatation print

//     // temp+a kmp math  again add a and again match 
//     if(kmp_match(temp+a , b)==1)
//      return repeat+1;

// //    if doesn't got answer then 
//     return -1;
// }