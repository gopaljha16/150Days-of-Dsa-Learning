// Maximal Rectangle leetocode hard question 

// class Solution {
// public:


//    int largestRectangleArea(vector<int>& heights) {
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

//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         vector<int>heights(col , 0);//heights vectors with 0 initially
//         int ans;

//         for(int i=0 ; i<row ; i++){
//             for(int j=0 ; j<col ; j++){
//                 //zero match
//                 if(matrix[i][j]=='0')
//                 heights[j]=0;
//                 else //then it is 1
//                 heights[j]+=1;
//             }
//             ans = max(ans ,largestRectangleArea(heights));
//         }
//         return ans;
//     }
// };