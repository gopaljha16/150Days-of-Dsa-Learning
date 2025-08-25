// Zero Sum Subarray gfg medium level question 

//map approch unordered approch. wwith prefix sum
// class Solution {
//   public:
//     int findSubarray(vector<int> &arr) {
      
//       int total = 0; //stores the total number of 0 which came..
//       //unordered map using
//       unordered_map<int , int>m; //it containes prefixSum , count;
//       int prefixSum = 0; // initially 0;
//       //initlizing the edge case 
//       m[0] =1; // if in end 0 comes so for that edge case we can use this..
      
//       //ooperation 
//       for(int i=0 ; i<arr.size() ; i++){
//           prefixSum+=arr[i]; //sum of array...
//           if(m.count(prefixSum)){ //if the count exists of the number then total increase and prefixSum increase
//               total+=m[prefixSum]; // total number of prefix sum
//               m[prefixSum]++; // incrementing
//           }else{; //if there is no prefixSum exisits
//               m[prefixSum] =1;
//           }
//       }
      
//       return total;
//     }
// };