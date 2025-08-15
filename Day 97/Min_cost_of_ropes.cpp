// Min cost of the ropes gfg easy level question 

// class Solution {
//   public:
//     int minCost(vector<int>& arr) {
//         int n = arr.size();
        
//         //priority queue min heap
//         priority_queue<int,vector<int>,greater<int>>p;
        
//         //insert all element in the priority queue
//         for(int i=0; i<n; i++){
//             p.push(arr[i]);
//         }
        
//         //now cost calculation 
//         int cost = 0;
        
//         while(p.size()>1){ //break when it's size is only 1 element
//             int rope = p.top(); //first smallest element
//             p.pop();
//             rope+=p.top();//second smallest element
//             p.pop();
//             cost+=rope; //added to cost
//             p.push(rope);//pushed to queue
//         }
        
//         return cost;
        
//     }
// };