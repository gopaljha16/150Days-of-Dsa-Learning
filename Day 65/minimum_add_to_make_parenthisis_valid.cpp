// 921. Minimum Add to Make Parentheses Valid leetcode medium level question 

//first approch without stack 
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int left = 0 , right = 0;
//         for(int i=0 ; i<s.size(); i++){
//            if(s[i]=='('){
//             left++;
//            }else{
//             if(left>0){
//                 left--;
//             }else{
//                 right++;
//             }
//            }
//         }

//         return left + right;

        
//     }
// };


//with stack 
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//        stack<char>st;
//        int count = 0;
//        for(int i=0; i<s.size() ; i++){
//          if(s[i]=='('){//left
//             st.push(s[i]);
//          }else{ //right parentheisi
//             if(st.empty()){
//                 count++; //not there left then count+
//             }else{
//                 st.pop();//there then pop
//             }
//          }
//        }

//        return count + st.size();//count + left present in the stack
//     }
// };