// Next Greater Element in Circular Array gfg medium level question

//with doulbearry...

// class Solution {
//   public:
//     vector<int> nextLargerElement(vector<int> &arr) {
//         int n = arr.size();
//         vector<int>ans(n , -1);
//         stack<int>st;
//         vector<int>doubleArr(2*n);
        
//         for(int i=0 ; i<n ; i++){
//             doubleArr[i] = arr[i]; //orginal copy
//             doubleArr[i+n] = arr[i]; //then copy
//         }
        

//         for(int i=0 ; i<2*n ; i++){
            
//             while(!st.empty() && doubleArr[i]>arr[st.top()]){
//                 ans[st.top()] = doubleArr[i];
//                 st.pop();
//             }
            
//             // Push only the first pass (original array indices) 
//             if(i<n){
//             st.push(i);
//             }
         
//         }
        
//         return ans;
        
//     }
// };

// without double array i%N

// class Solution {
//   public:
//     vector<int> nextLargerElement(vector<int> &arr) {
//         int n = arr.size();
//         vector<int>ans(n , -1);
//         stack<int>st;

//         for(int i=0 ; i<2*n ; i++){
            
//             // if not empty
//             // i%n becuase it can check 2 time if the value is there.
//             while(!st.empty() && arr[i%n]>arr[st.top()]){
//                 ans[st.top()] = arr[i%n];
//                 st.pop();
//             }
            
//             //stack empty then enter check  i%n
//             st.push(i%n);
         
//         }
        
//         return ans;
        
//     }
// };