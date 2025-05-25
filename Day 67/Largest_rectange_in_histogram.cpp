// Largest Rectangle in histogram leetcode hard level question

// method 1
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int>right(n);
//         vector<int>left(n);
//         stack<int>st;

//         //Next smallest right 
//         for(int i=0 ; i<n ; i++){
//             //stack exisits
//             while(!st.empty() && heights[st.top()]>heights[i]){
//                 right[st.top()] = i;
//                 st.pop();
//             }
//             //add into stack 
//             st.push(i);
//         }
//         //if im the stack element exisits
//         while(!st.empty()){
//             right[st.top()] = n;
//             st.pop();
//         }

//         //Next smallest left
//         for(int i=n-1; i>=0 ; i--){
//             while(!st.empty() && heights[st.top()]>heights[i]){
//                 left[st.top()] = i;
//                 st.pop();
//             }
//             st.push(i);
//         }

//         //if element exisits
//         while(!st.empty()){
//             left[st.top()] = -1;
//             st.pop();
//         }

//         //now left and right we have got we have to get answer
//         int ans = 0;
//         for(int i=0 ; i<n ; i++){
//             ans = max(ans , heights[i]*(right[i]-left[i]-1));
//         }

//         return ans;
//     }
// };


//method 2 in only one passs.
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int ans = 0;
//         int index;
//         stack<int>st;
   
//      //code
//         for(int i=0 ; i<n ; i++){
            
//             //not empty
//             while(!st.empty() && heights[st.top()]>heights[i]){
//                 index = st.top();
//                 st.pop();
//             //    after popping not empty
//                 if(!st.empty()){
//                     ans = max(ans , heights[index]*(i-st.top()-1));
//                 }else{ //if stack is empty
//                     ans = max(ans , heights[index]*i);
//                 }
//             }

//             //enter to stack 
//             st.push(i);
//         } 

//         //if the stack is not empty 
//         while(!st.empty()){
//             index = st.top();
//             st.pop();

//             //if stack is not empty
//             if(!st.empty()){
//                 ans = max(ans , heights[index]*(n-st.top()-1));
//             }else{ //if empty
//                 ans = max(ans , heights[index]*n);
//             }
//         }

//         return ans;
//     }
// };