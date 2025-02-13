// Sorting the Sentence (leetcode question easy level )

// class Solution {
// public:
//     string sortSentence(string s) {
//         vector<string>ans(10);
//         string temp;
//         int count=0,index=0;
//         int n = s.size();
//         while(index<n){
//             if(s[index]==' '){
//               int pos = temp[temp.size()-1]-'0';
//               temp.pop_back();
//               ans[pos] = temp;
//               temp.clear();
//               count++; 
//             }
//             else{
//                 temp+=s[index];
//             }
//             index++;
//         }
//         //when loop completed last word handler
//         int pos = temp[temp.size()-1] - '0';
//               temp.pop_back();
//               ans[pos] = temp;
//               temp.clear();
//               count++; 

//     for(int i=1;i<=count ; i++){
//         temp+=ans[i];
//         temp+=' ';
//     }

//     // string last word gap delete
//     temp.pop_back();

//     return temp;
//     }
// };