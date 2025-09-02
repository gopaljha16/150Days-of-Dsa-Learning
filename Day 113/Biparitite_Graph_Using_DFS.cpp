// Bipartite Graph gfg medium level problem 
//  using DFS 
// class Solution {
//   public:
  
//    bool DFS(int node , vector<vector<int>>&adj , vector<int>&color){
//        //now all veritices check 
//       for(int j=0 ;j<adj[node].size() ; j++){
//           ///if the color is not assingned
//           if(color[adj[node][j]]==-1){
//               color[adj[node][j]] = (color[node]+1)%2;
              
//               //call again and check
//               if(!DFS(adj[node][j] , adj , color))
//                 return 0;
//           }else{
//               //color is already assigned
//               if(color[node]==color[adj[node][j]])
//                return 0;
//           }
//       }
//       return 1;
//    }
//     bool isBipartite(int V, vector<vector<int>> &edges) {

//         vector<vector<int>>adj(V);
//         for(auto e:edges){
//             int u = e[0];
//             int v = e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
        
//         vector<int>color(V , -1); //initialize with -1 
        
//         //for all the conneted and not connted graph 
//         for(int i=0 ; i<V ; i++){
//            if(color[i]==-1){
//                color[i] = 0;
//                if(!DFS(i , adj , color))
//                 return 0;
//            }
//         }
        
//         return 1;
//     }
    
// };