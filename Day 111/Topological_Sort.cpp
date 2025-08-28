// Topological sort gfg medium level question 
//solving using the dfs 
// class Solution {
//   public:
  
//      void DFS(int node , vector<vector<int>>&adj , vector<bool>&visited , stack<int>s){
//          //first element we have to mark it visited 
//          visited[node] = 1;
         
//          //now look all the neighbours one by one 
//          for(int i=0 ; i<adj[node].size() ; i++){
//              //check if not visitd then call the function 
//              if(!visited[adj[node][i]])
//               DFS(adj[node][i] , adj , visited , s);
//          }
         
//          s.push(node); //after the function call then push
//      }
     
  
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//       //adj 
//         vector<vector<int>> adj(V);
//         for (auto& e : edges) {
//           int u = e[0];
//           int v = e[1];
//           adj[u].push_back(v); 
//       }
      
//       vector<bool>visited(V ,0); // initally all 0
//       stack<int>s; //for answer
//       for(int i = 0 ; i<V ; i++){ // for all if the vertices are not visited then visiting to all 
//           if(!visited[i])  
//            DFS(i , adj , visited , s);
//       }
        
//       //now from stack element push into the answer
//       vector<int>ans; //for storing answer
//       while(!s.empty()){ // loop break till stack is empty
//           ans.push_back(s.top());
//           s.pop(); // pop 
//       }
      
//       return ans;
//     }
// };

// Solving using the bfs (Kahn's Alogorithm)
// class Solution {
//   public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//        //Khan's Algorithm
//       ///for edges pushed into the adj
//       vector<vector<int>>adj(V);
//       for(auto e:edges){
//           int u = e[0];
//           int v = e[1];
//           adj[u].push_back(v);
//       }
      
      
//       vector<int>ans; //for pushing answer
//       vector<int>inDegree(V , 0); // storing the indegree of every vertex
      
//       //now calculate the indegree of the all vertexs
//       for(int i=0 ; i<V  ; i++){
//           for(int j = 0 ; j<adj[i].size() ; j++){
//               inDegree[adj[i][j]]++; // here the indegree incoming will be calculaed
//           }
//       }
      
//       //so now if the indegree is 0 then push to the queue
//       queue<int>q;
//       for(int i=0 ; i<V; i++){
//           if(!inDegree[i]) //if the degree value is 0 then push that elemement
//            q.push(i); // push that element to the queue
//       }
//       int node;
//       //now from the queue pop and indegree decrease by 1
//       while(!q.empty()){ // till queue is empty
//          node = q.front(); //first element from queue
//          q.pop(); // pop from the queue
//          ans.push_back(node); //push that ele to answer
         
//          //now neighbour should be decrease by 1 
//          for(int j=0 ; j<adj[node].size() ;j++){
//              inDegree[adj[node][j]]--; //decrease by 1
//              //now the element which is decreased by if it becomes 0 then push into the queue
//             if(inDegree[adj[node][j]]==0)
//              q.push(adj[node][j]); //pushed that element into the queue
//          }
//       }
      
//       return ans;
//     }
// };