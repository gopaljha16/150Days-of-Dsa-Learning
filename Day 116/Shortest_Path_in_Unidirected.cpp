// Shortest path in unidirected graph gfg medium level question 
//using bfs methods
// class Solution {
//   public:
//     // Function to find the shortest path from source to all other nodes
//     vector<int> shortestPath(vector<vector<int>>& adj, int src) {
//           int n = adj.size();
//           int m  = adj[0].size();
          
//           vector<int>dist(n , -1);
//           vector<int>visited(n , 0);
          
//           //now create the quueue
//           queue<int>q;
//           //src it should be starting 
//           q.push(src);
//           dist[src] = 0; //from source to source distance
//           visited[src] = 1; // distance update
          
//           while(!q.empty()){
//               int node = q.front();
//               q.pop();
              
//               //check all the adj and update the visited and distance
//               for(int j = 0 ; j<adj[node].size() ; j++){
                 
//                  //if already visited
//                  if(visited[adj[node][j]])
//                   continue;
                  
//                  //not visited then update that
//                  visited[adj[node][j]] = 1;
                 
//                  //now push tha node to queue
//                  q.push(adj[node][j]);
                 
//                  //distance update
//                  dist[adj[node][j]] = dist[node]+1;
//               }
//           }
          
          
//         return dist;
        
//     }
// };


