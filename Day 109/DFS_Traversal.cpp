// DFS traversal gfg easy level question 

// class Solution {
//   public:
  
//     void DFS(int node ,vector<vector<int>>& adj , vector<int>&ans , vector<bool>&visited){
         
//         visited[node] = 1; //value make it 1 for that the element is visited
//         ans.push_back(node);
        
//         //now all the edges are should be visited one by one 
//         for(int i=0 ; i<adj[node].size() ; i++){
//             //check the edge is not visited
//             if(!visited[adj[node][i]]){
//                 DFS(adj[node][i] , adj , ans , visited); // then call again dfs function
//             }
//         }
//     }
  
//     vector<int> dfs(vector<vector<int>>& adj) {
      
//        int v = adj.size();
//        vector<bool>visited(v , 0); // all the vertex is initialized by 0
//        vector<int>ans; //for returing
       
//        //function call 
//        DFS(0 , adj , ans , visited);
//        // 0th vertex in question is written so passing 0th vertex
//        return ans;
//     }
// };