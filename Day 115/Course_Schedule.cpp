// // Course Schedule gfg medium level question 
// class Solution {
//   public:
//     vector<int> findOrder(int N, vector<vector<int>> prerequisites) {
//        int P = prerequisites.size();
//        //create adjacency list and update the indegree also
//         vector<int>adj[N];
//         vector<int>Indegree(N , 0);
//         for(int i=0 ;i<P ; i++){
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             Indegree[prerequisites[i][0]]++;
//         }
        
//         //kahn's algorithm
//         queue<int>q;
//         vector<int>ans; //for returning the size and it wil be saying it's cycle is not graph\
        
//         for(int i=0 ; i<N ; i++){
//             if(!Indegree[i]) //if 0
//              q.push(i); // then push 0
//         }
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);
            
//             //now neigbout checking and decreasing with -1 and if 0 becomes then push
//             for(int j=0 ; j<adj[node].size() ; j++){
//                 Indegree[adj[node][j]]--; //decrease 
//                 if(!Indegree[adj[node][j]]){ //if it becomes 0
//                     //then push to the queue
//                     q.push(adj[node][j]);
//                 }
//             }
//         }
        
//         vector<int>temp;
//         return ans.size()==N ? ans : temp; //it will saying true and false 
//     }
// };
