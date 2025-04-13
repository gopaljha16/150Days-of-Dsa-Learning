// Generate parentheses Medium level question leetcode


// class Solution {
//     public:
    
//     void Parentheses(int n , int left , int right , vector<string >& ans , string & temp){
//         //base case
//         if(left+right==2*n){
//             ans.push_back(temp);
//             return;
//         }
//         //left Parentheses
//        if(left<n){
//         temp.push_back('(');
//         Parentheses(n , left+1 , right , ans , temp);
//         temp.pop_back();
//        }
//         //right Parentheses
//         if(right<left){
//             temp.push_back(')');
//             Parentheses(n , left , right+1 , ans , temp);
//             temp.pop_back();
//         }
//     }
//         vector<string> generateParenthesis(int n) {
//             vector<string>ans;
//             string temp;
//              Parentheses(n , 0 , 0 , ans , temp);
//              return ans;
//         }
//     };