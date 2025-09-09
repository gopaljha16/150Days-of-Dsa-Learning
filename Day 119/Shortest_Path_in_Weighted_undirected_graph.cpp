// Shortest Path in Weighted undirected graph gfg medium level question 
// Dijkstra algorithm used anad path returnred

// class Solution {
//   public:
//     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
//         //adj create
//         int V = n;
//         vector<pair<int , int>>adj[V+1];
//         for(int i=0 ; i<m ; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int weight = edges[i][2];
//             //undirected graph 
//            adj[v].push_back({u , weight});
//            adj[u].push_back({v , weight});
//         }
        
//         //dijkstra algorithm
//         vector<bool>explored(V+1 ,0);
//         vector<int>dist(V+1 , INT_MAX);
//         vector<int>parent(V+1 , -1);
        
//         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>p;
//         p.push({0,1}); // source is 1
//         dist[1] = 0;
        
//         while(!p.empty()){
//             int node = p.top().second;
//             p.pop();
            
//             if(explored[node]) //already explored
//              continue;
             
//             explored[node] = 1; //not explored
            
//         //look at all the nodes
//         for(int j=0 ; j<adj[node].size() ; j++){
//             int neighbour = adj[node][j].first;
//             int weight = adj[node][j].second;
            
//             if(!explored[neighbour] && dist[node]+weight<dist[neighbour]){
//                 dist[neighbour] = dist[node]+weight;
//                 p.push({dist[neighbour] , neighbour});
//                 parent[neighbour] = node; //parent upated
                
//             }
//         }
//         }
        
//         //now path update
//         vector<int>path;
//         // If can't reach my destination 
//         if(parent[V]==-1){
//             path.push_back(-1);
//             return path;
//         }
//         // if it can reach to my destination 
//         int dest = V;
//         while(dest!=-1){ //till test will reach to -1
//             path.push_back(dest);
//             dest = parent[dest]; //go to parent
//         }
        
//         //first value will be weight
//         path.push_back(dist[V]);
//         reverse(path.begin() , path.end());
//         return path;
//     }
// };