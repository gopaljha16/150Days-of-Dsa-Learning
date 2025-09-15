// Minimum Spanning Tree gfg medium level question 

// class Solution {
//   public:
//     int spanningTree(int V, vector<vector<int>>& edges) {
        
//         //creating adj 
//         int n = edges.size();
//         vector<pair<int,int>>adj[V];
//         for(int i=0 ; i<n ; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int wt = edges[i][2];
            
//             adj[u].push_back({v , wt});
//             adj[v].push_back({u , wt});
//         }
        
//         // prirorty queue 
//         // pair<int,pair<int,int>> wt , node , parent
//         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>p;
        
//         vector<bool>IsMST(V ,0);
//         vector<int>parent(V); //temporary
//         int cost = 0;
//         // initally push 
//         p.push({0,{0,-1}});
//         while(!p.empty()){
//             int wt = p.top().first;
//             int node = p.top().second.first;
//             int par = p.top().second.second;
//             p.pop();
            
//             if(!IsMST[node]){ //if the node doesn't exisits in the mst
//             IsMST[node] = 1; //mark is visited
//             cost+=wt; //weight added
//             parent[node] = par; //update parent
            
//             // now edges 
//             for(int j=0 ; j<adj[node].size() ; j++){
//                 if(!IsMST[adj[node][j].first]){ //if node doesn't exists in hte mst then push to the queue
//                     p.push({adj[node][j].second , {adj[node][j].first , node}}); /// pushing weight newnode  , node
//                 }
//             }
//             }
//         }
        
//         return cost;
//     }
// };