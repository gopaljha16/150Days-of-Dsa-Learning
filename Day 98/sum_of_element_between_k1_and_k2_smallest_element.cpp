// Sum of elements between k1'th and k2'th smallest elements gfg easy level question 

// class Solution {
//   public:
//     long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
//         //maxheap 
//         priority_queue<int>p1; //for storing k1 smallest element
//         priority_queue<int>p2; //for k2-1 smallest elements
        
//         //inserting element k1
//         for(long long i=0 ; i<K1; i++){
//             p1.push(A[i]);
//         }
        
//         //inserting k2 element
//         for(long long i=0; i<K2-1; i++){
//             p2.push(A[i]);
//         }
        
//         // element from k1 to n compare and push in p1
//         for(long long i=K1 ;i<N ; i++){
//             if(A[i]<p1.top()){
//                 p1.pop();
//                 p1.push(A[i]);
//             }
//         }
        
//         //element from k2-1 to n compare and push in p2
//          for(long long i=K2-1 ;i<N ; i++){
//             if(A[i]<p2.top()){
//                 p2.pop();
//                 p2.push(A[i]);
//             }
//         }
        
//         // now we have got the queue 
//         long long sum1 = 0 , sum2 = 0;
//         //p1 sum
//         while(!p1.empty()){
//             sum1+=p1.top();
//             p1.pop();
//         }
        
//         //p2 sum
//            while(!p2.empty()){
//             sum2+=p2.top();
//             p2.pop();
//         }

//         return sum2-sum1;
        
//     }
// };