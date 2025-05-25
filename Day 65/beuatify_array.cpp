// Make the array beautiful gfg question easy level 


// class Solution {
//   public:
//     vector<int> makeBeautiful(vector<int> arr) {
//         stack<int>s;
//         //push arr element into the stack and do the comparision 
//         for(int i=0 ; i<arr.size() ; i++){
//             //if stack is empty 
//             if(s.empty()){
//                 s.push(arr[i]);
//             }else if(arr[i]>=0){ //non negative then push or else pop(both non negative)
//                 if(s.top()>=0){
//                     s.push(arr[i]);
//                 }else{
//                     s.pop();
//                 }
//             }else{//both negative then push if one negative and postive then pop
//                 if(s.top()<0){
//                     s.push(arr[i]);
//                 }else{
//                     s.pop();
//                 }
//             }
//         }
 
    
//     //now add the final answer from the stack to new vector
//     vector<int>ans(s.size());
//     int i = s.size()-1;
//     while(!s.empty()){
//         ans[i] = s.top();
//         i--;
//         s.pop();
//     }
    
//     return ans;
    
//     }
// };