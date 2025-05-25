// Smaller of Left gfg medium level question 

//backwards
// class Solution {
//   public:
//     vector<int> leftSmaller(vector<int> arr) {
     
//         int n = arr.size();
//         stack<int>st;
//         vector<int>ans(n,-1);
        
//         for(int i= n-1 ; i>=0 ; i--){
             
//              //stack not empty
//             while(!st.empty() && arr[st.top()]>arr[i]){
//                 ans[st.top()] = arr[i];
//                 st.pop();
//             }
            
//             st.push(i);
//         }
        
//         return ans;
//     }
// };