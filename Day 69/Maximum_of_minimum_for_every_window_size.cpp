// Max of min for every window size gfg hard level question.

// method 1 : Time Limit Exceeded

// class Solution {
//   public:
//     vector<int> maxOfMins(vector<int>& arr) {
//         int n= arr.size();
//         vector<int>ans(n, 0);
        
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<n-i ; j++){
//                 int num = INT_MAX;
//                 for(int k=j ; k<i+1+j ; k++){
//                     num = min(arr[k], num);
//                 }
                
//                 ans[i] = max(ans[i] , num);
//             }
//         }
        
        
//         return ans;
//     }
// };


// 0(n) approch
// class Solution {
//   public:
//     vector<int> maxOfMins(vector<int>& arr) {
//      int n = arr.size();
//      vector<int>ans(n,0);//ans inially 0;
//      stack<int>st;
     
//      //array iterating
//      for(int i=0 ; i<n; i++){
         
//          //not empty top is small pop and inseting doinging max and inserting into the ans
//          while(!st.empty() && arr[st.top()]>arr[i]){
//              int index = st.top();
//              st.pop();
//              //i next smallest right
//              //index then next smallest left 
//              if(st.empty()){ //if stack is empty
//                 int range = i;
//                  ans[range-1] = max(ans[range-1], arr[index]);
//              }else{ //stack is not empty
//                  int range = i-st.top()-1; //max window size.
//                  ans[range-1] = max(ans[range-1],arr[index]);
//              }
//          }
         
//          //if while breaks
//          st.push(i);
//      }
     
//      //it the stack is empty
//      while(!st.empty()){
//          int index = st.top();
//          st.pop();
         
//          if(st.empty()){ // stack is empty
//              int range = n;
//              ans[range-1] = max(ans[range-1], arr[index]);
//          }else{ //stack is not empty
//             int range = n-st.top()-1;
//              ans[range-1] = max(ans[range-1] , arr[index]);
//          }
//      }
     
//      ////if some values afre not updated so max of that 
//      for(int i=n-2 ; i>=0 ; i--){
//          ans[i] = max(ans[i] ,ans[i+1]);
//      }
     
//      //now we can return ans;
//      return ans;
     
//     }
// };