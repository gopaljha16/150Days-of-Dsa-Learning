// Kth Smallest Elelement gfg medium level question
// User function template for C++

// class Solution {
//   public:
//     // arr : given array
//     // k : find kth smallest element and return using this function
//     int kthSmallest(vector<int> &arr, int k) {
//       priority_queue<int>p; //max heap
//       //inserting element in max heap
//       for(int i=0 ; i<k ; i++){
//           p.push(arr[i]);
//       }
      
//       //now from k to array end comparing and inserting.
//       for(int i=k ; i<arr.size() ; i++){
//           if(arr[i]<p.top()){ //hereiif the current element is small then pop the elemenmt and small element push to queue 
//               p.pop();
//               p.push(arr[i]);
//           }
//       }
      
//       return p.top(); //now top kth element is maximum
//     }
// };