// Sort Vowels in a String (leetcode meduim level question 2785)

// string sortVowels(string s) {
//     vector<int>lower(26,0);
//     vector<int>upper(26,0);

//     // select the vowels count store of the vowels in the array 
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='a' || s[i]=='e' || s[i]=='i' || 
//         s [i]=='o' || s[i]=='u'){
//             lower[s[i]-'a']++;
//             s[i]='#';
//         }
//         else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || 
//         s [i]=='O' || s[i]=='U'){
//             upper[s[i]-'A']++;
//             s[i]='#';
//         }
//     }

//     // sort the vowel 
//     string ans ; // for storing the sorted vowels
//      // upper
//       for(int i=0;i<26;i++){
//         char c = 'A'+i;
//         while(upper[i]){
//             ans+=c;
//             upper[i]--;
//         }
//     } 
//     // lower
//     for(int i=0;i<26;i++){
//         char c = 'a'+i;
//         while(lower[i]){
//             ans+=c;
//             lower[i]--;
//         }
//     } 
   
//     // update the string 
//     int first = 0 , second =0;
//     while(second<ans.size()){
//         if(s[first]=='#'){
//             s[first] = ans[second];
//             second++;
//         }
//         first++;
//     }

//     // return the updated string 
//     return s;
// }