// class Solution {
//   public:
    
//      bool BFS(int vertex , vector<vector<int>>&adj , vector<bool>&visited){
//          queue<pair<int, int>>q; // for node and parent storing
//          visited[vertex] = 1; //first node making it visited
//          q.push(make_pair(vertex , -1)); // pushing the first node in the queue with parnt 
          
//          int node , parent;
//          //now cover all the neighbours
//          while(!q.empty()){ //till queue is empty
//            node = q.front().first; 
//            parent = q.front().second; 
//            q.pop();
//            //now all neighbours check cycle dected or not
//            for(int i=0 ; i<adj[node].size() ; i++){
//                //if parent == node i then skip the iteration
//                if(parent == adj[node][i])
//                 continue; 
              
//                //check if already visited then there cycle detected
//                if(visited[adj[node][i]])
//                  return 1;
            
//                //other marking that 1 and pushing into the quuee if not visted
//                visited[adj[node][i]] = 1;
//                q.push(make_pair(adj[node][i] , node));
//            }
//          }
         
//          return 0;
//      }
  
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         //using bfs
//         //adj
//          vector<vector<int>> adj(V);
//         for (auto &e : edges) {
//          int u = e[0];
//          int v = e[1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         }
        
//         vector<bool>visited(V ,0); // initially 0
//         for(int i=0 ; i<V ; i++){ //for not conneted graph checking all the vertices
//             if(!visited[i] && BFS(i , adj , visited))
//              return 1;
//         }
        
//         return 0;
        
//     }
// };