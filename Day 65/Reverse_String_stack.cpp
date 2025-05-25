// Reverse String leetcode question doing with the stack 

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         stack<char>st;
//         for(int i=0; i<s.size();i++){
//             st.push(s[i]); //inserted in the stack
//         }

//         //now remove from stack and insert in original array
//         int i=0;
//         while(!st.empty()){
//             s[i] = st.top(); //top element inserting into the vector
//             st.pop(); //popping element of stack which is inserted
//             i++; // increment i;
//         }
//     }
// };