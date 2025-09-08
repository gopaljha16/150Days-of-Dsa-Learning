// Dijkstra Algorithm gfg medium level question

//using priority queue Min heap for more good time complexitiy
// // User Function Template
// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//         //adj create
//         vector<vector<pair<int,int>>> adj(V);  // {node, weight}
//         for (auto &edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2]; // weight of edge

//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w}); // if graph is undirected
//         }

//         vector<bool> explored(V, 0);
//         vector<int> dist(V , INT_MAX);
//         dist[src] = 0; 
        
//         //priority_queue min heap
//        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
//         p.push({0,src});//pusing the element in the queue means here minimun will be in the first
       
//         while(!p.empty()){ // until queue empty
//             int node = p.top().second; //node
//             p.pop();
            
//             //if already explored then skip iteratiom
//             if(explored[node]==1)
//              continue;
//         //not explored 
//              explored[node] =1;
        
//             //relax the edges
//             for(int j=0 ; j<adj[node].size() ; j++){
//                 int neighbour = adj[node][j].first;
//                 int weight = adj[node][j].second;
            
//                 //check that if dist[node] is valid and dist[node] + weight is smaller than neighbour then update
//                 if (dist[node] != INT_MAX && dist[node] + weight < dist[neighbour]) {
//                     dist[neighbour] = dist[node] + weight;
//                     p.push({dist[neighbour]  , neighbour});
//                 }   
//             }  
        
//         }
        

      
//         return dist; 
//     }
// };
