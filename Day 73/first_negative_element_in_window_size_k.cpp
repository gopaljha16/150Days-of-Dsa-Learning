// First negative in every window of size k gfg medium level question 
//approch 1 TLE o(nk) time complexitiy
// class Solution {
//   public:
  
//     int  printNegative(queue<int>q){
//         while(!q.empty()){
//             if(q.front()<0)
//              return q.front();
            
//             q.pop();
//         }
//         return 0; // no element then print.0
//     }
//     vector<int> firstNegInt(vector<int>& arr, int k) {
//         queue<int>q;
//         vector<int>ans;
        
//         //push k-1 element
//         int n = arr.size();
//         for(int i=0 ; i<k-1 ; i++){
//            q.push(arr[i]);
//         }
        
//         for(int i=k-1 ; i<n ; i++){
//             q.push(arr[i]);
//             (q);
//             q.pop();
//         }
        
//         return ans;
        
//     }
// };

//approch 2 o(n) time complexity
// class Solution {
//   public:
//     vector<int> firstNegInt(vector<int>& arr, int k) {
//         int n = arr.size();
//         queue<int>q;
//         vector<int>ans;
        
//         //push the negative ele k-1
//         for(int i=0 ; i<k-1 ; i++){
//             if(arr[i]<0){ //if the ele is negative then push index.
//                 q.push(i);
//             }
//         }
        
//         //element slide.
//         for(int i=k-1 ; i<n ; i++){
//             if(arr[i]<0){ //negative value index push in queue.
//                 q.push(i);
//             }
            
//             if(q.empty()){ //if queue is empty then push 0
//                 ans.push_back(0);
//             }else{
//                 //pop first index element which is outside  of the window
//                 if(q.front()<=i-k){
//                     q.pop();
//                 }
                
//                 //printing
//                 if(q.empty()){ //queue is empty
//                     ans.push_back(0);
//                 }else{ //element present
//                     ans.push_back(arr[q.front()]);
//                 }
//             }
//         }
        
//         return ans;
        
//     }
// };