// String Manipulation easy level question

// class Solution {
//   public:
//     int removeConsecutiveSame(vector<string>& arr) {
//        stack<string>s;
//        for(int i=0; i<arr.size() ; i++){
//            //empty stack
//            if(s.empty()){
//                s.push(arr[i]);
//            }else if(arr[i]==s.top()){
//               s.pop();
//            }else{
//                s.push(arr[i]);
//            }
//        }
       
//        return s.size();
//     }
// };