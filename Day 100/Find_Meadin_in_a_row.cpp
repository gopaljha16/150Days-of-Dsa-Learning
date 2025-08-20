// Find median in a stream gfg hard level question..
// class Solution {
//   public:
//     vector<double> getMedian(vector<int> &arr) {
//         // code here
//         priority_queue<int>left;//max heap;
//         priority_queue<int , vector<int> , greater<int>>right; //min heap
//         vector<double>ans;
//         //insert element
//         for(int i=0 ; i<arr.size() ; i++){
            
//             //insert element into the heap 
//             if(left.empty()){
//                 left.push(arr[i]);
//                 ans.push_back(left.top());
//                 continue; // pehla element ka median set ho gaya
//             }
            
//             if(arr[i]>left.top()) //left element is greater than left top then push to right side
//              right.push(arr[i]);
//             else  //element is arr[i] is smallest then right ka top then push to left side..
//              left.push(arr[i]);
             
             
//             //balance the heap
//             //minheap(right) size should not be greater than the maxheap(left)
//             if(right.size()>left.size()){ //if right element is big then push to left side and pop
//                 left.push(right.top());
//                 right.pop();
//             }
//             else{ //left side elmeent are greater then tow or more so here we should push to right side
             
//              //difference 
//              if(right.size()<left.size()-1){
//                  right.push(left.top());
//                  left.pop();
//              }
//             }
            
            
//           //median logic
//             if(left.size()>right.size()){ //odd logic so here left is greater then the right 
//                 ans.push_back(left.top());
//             }else{ //even median
            
//              double num = (left.top() + right.top()) / 2.0;
//                ans.push_back(num);
//             }
            
//         }
//             return ans;
//     }
// };
