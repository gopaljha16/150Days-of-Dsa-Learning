// Next greater Element gfg medium level question

//time limit exceeded because it is expecting the o(n) 
// // class Solution {
//   public:
//     vector<int> nextLargerElement(vector<int>& arr) {
//           int n = arr.size();
//         vector<int>ans(n , -1);
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1 ; j<n ; j++){
//                 if(arr[j]>arr[i]){
//                     ans[i] = arr[j];
//                     break;
//                 }
//             }
//         }
        
//         return ans;
        
//     }
// };

//method 2. by using stack.. o(n) time complexity
// class Solution {
//   public:
//     vector<int> nextLargerElement(vector<int>& arr) {
//         stack<int>st;
//         int n = arr.size();
//         vector<int>ans(n, -1);
        
//         for(int i=0 ; i<n ; i++){
            
//             while(!st.empty() && arr[st.top()]<arr[i]){
//                 ans[st.top()] = arr[i];
//                 st.pop();
//             }
            
//             st.push(i);
//         }
        
//         return ans;
//     }
// };


//another method 

// class Solution {
//   public:
//     vector<int> nextLargerElement(vector<int>& arr) {
//         stack<int>st;
//         int n = arr.size();
//         vector<int>ans(n, -1);
        
//         for(int i=n-1 ; i>=0 ; i--){
           
//            //here if the stack is not empty and st.top is less than array then stack pop 
//            while(!st.empty() && arr[st.top()]<=arr[i]){
//                st.pop();
//            }  
           
//            //again check stack is empty of not
//            if(!st.empty()){//if not empty top element enter to the ans
//                ans[i] = arr[st.top()];
//            }
           
//            // add to the stack condition doesn't follow 
//            st.push(i);
          
//         }
        
//         return ans;
//     }
// };