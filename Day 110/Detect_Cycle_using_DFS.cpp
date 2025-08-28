// Detect cycle in the undirected graph using dfs 

// class Solution {
//   public:
  
//      bool CycleDetect(int node , int parent , vector<vector<int>>&adj , vector<bool>&visited){
         
//          visited[node] = 1; //first visited the node
         
//          //then check the cycle if present then return 1  or else return 0
//          for(int i=0 ; i<adj[node].size() ; i++){
//              //first check parent node is not neighbour
//              if(parent==adj[node][i])
//               continue; // if parent is neighbout then skip the statement
             
//              // if already visited then that is cycle detected
//              if(visited[adj[node][i]]){ // already visted we came that and it's not parent then it's the cycle
//                  return 1;
//              }
             
//              if(CycleDetect(adj[node][i] , node , adj , visited)) //check all the node check there cycle is detected or not
//               return 1;
//          }
         
//          return 0;
//      }
  
     
//     bool isCycle(int V, vector<vector<int>>& edges) {
        
        
//          //build adj
//         vector<vector<int>> adj(V);
//         for (auto &e : edges) {
//             int u = e[0] ; 
//             int v = e[1] ;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        

        
//         vector<bool>visited(V , 0); // visited all marking as 0;
        
//         //now the univisted all node should be checked so for that we will be usign loo
//           for(int i=0 ; i<V ; i++){
//               if(!visited[i]&&CycleDetect(i , -1 , adj , visited))
//                return 1; // so here checking if all it's not visited visited them and check the cycle is not detected or not
               
//           }
          
//           return 0;
//     }
// };