// Shortest path in Directed Acyclic Graph gfg medium level question 

// User function Template for C++
// class Solution {
//   public:
    
//     void DFS(int node , vector<pair<int, int>>adj[] , stack<int>&s , vector<bool>&visited){
//         //update visited
//         visited[node] = 1;
        
//         //look at all the neigbours
//         for(int j=0 ; j<adj[node].size() ; j++){
            
//             //if not visited then dfs
//             if(!visited[adj[node][j].first])
//               DFS(adj[node][j].first , adj , s , visited);
//         }
        
//         //after all the negihbours looking
//         s.push(node); //then push to the node
//     }
  
//     vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
         
//         // adjacency create 
//         vector<pair<int, int>>adj[V];
        
//         for(int i=0 ; i<E ; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int weight = edges[i][2];
//             adj[u].push_back(make_pair(v , weight));
//         }
        
//         //topological sort(DFS)
//         stack<int>s1;
//         vector<bool>visited(V,0);
//         DFS(0 , adj , s1 , visited);
        
//         //distance 
//         vector<int>dist(V , INT_MAX);
//         //src 
//         dist[0] = 0;
//         //stack empty
//         while(!s1.empty()){
//             int node = s1.top();
//             s1.pop();
            
//             //look at the negative
//             for(int j=0 ; j<adj[node].size() ; j++){
//                 int neighbour = adj[node][j].first; //this is the neighbour
//                 int weight = adj[node][j].second; //weight
//                 // the formula distance
//                 dist[neighbour] = min( dist[neighbour] , weight+dist[node]);
//             }
//         }
        
//         // unvisited 
//         for(int i=0 ; i<V ; i++){
//             if(dist[i]==INT_MAX)
//              dist[i] = -1;
//         }
        
//         return dist;
        
//     }
// };
