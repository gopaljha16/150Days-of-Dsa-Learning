// Last Stone weight leetcode easy level question..

// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         priority_queue<int>p;

//         //insert stones
//         for(int i=0 ; i<stones.size();i++){
//             p.push(stones[i]);
//         }

//         while(p.size()>1){ // iteration until the size is 1
//          int weight = p.top(); // first largest
//          p.pop();
//          weight-=p.top(); //second largest se minus
//          p.pop();
//          if(weight){ //if weight exists
//             p.push(weight);
//          }
//         }

//         return p.empty() ? 0 : p.top();
//     }
// };