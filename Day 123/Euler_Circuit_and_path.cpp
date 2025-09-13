// Euler circuit and Path gfg medium level question 

// class Solution {
//   public:
  
//     void DFS(int node , vector<int>adj[] , vector<bool>&visited){
//         //visited mark
//         visited[node] = 1;
        
//         // for all the edges
//         for(int i=0 ; i<adj[node].size() ; i++){
//             if(!visited[adj[node][i]])
//              DFS(adj[node][i] , adj , visited);
//         }
//     }
  
//     int isEulerCircuit(int V, vector<int> adj[]) {
//     //   Eulerian circuit : 2
//     // Indegree calculate
//     vector<int>Deg(V,0);
//     // odd nodes calculate
//     int odd_deg = 0;
//     for(int i=0 ; i<V ; i++){
//         Deg[i] = adj[i].size(); //edges size means 2 
        
//         // for odd degree cal
//         if(Deg[i]%2)
//          odd_deg++; //increase odd
//     }
    
//     // non of node gaving the odd degree
//     if(odd_deg!=2 && odd_deg!=0)  //if the deg is 1,3,5,6,7 means here we can say the there would be not ec and ep
//       return 0;
        
//     // all non zero degre node should be connected
//     vector<bool>visited(V,0);
//     for(int i=0 ; i<V ; i++){
//         if(Deg[i]){ // degree exists
//             DFS(i , adj , visited);
//             break; //dfs exists then break
//         }
//     }
    
//     // //now nodes comes  
//     // uf non zero degree is still not visited and an edge is 0 and it;s degree is zero
    
//     for(int i=0 ; i<V ; i++){
//         if(Deg[i]&&!visited[i]) // degress exisits but not visited then it is non ec and ep
//          return 0;
//     }
    
//     // euler circuit : 2
//     // eulter path :3
//     if(odd_deg==0)
//      return 2;
//     else
//      return 1;
        
//     }
// };