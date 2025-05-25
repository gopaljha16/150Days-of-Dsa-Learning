// Print Bracket Number gfg easy level question

// class Solution {
//   public:

//     vector<int> bracketNumbers(string str) {
       
//        int count=0;
//        stack<int>st;
//        vector<int>ans;
       
//        for(int i=0 ; i<str.size() ; i++){
//            //opening bracket
//            if(str[i]=='('){
//                count++;
//                st.push(count);
//                ans.push_back(count);
//            }
//            //closing bracket
//            else if(str[i]==')'){
//                ans.push_back(st.top());
//                st.pop();
//            }
//        }
       
//        return ans;
//     }
// };