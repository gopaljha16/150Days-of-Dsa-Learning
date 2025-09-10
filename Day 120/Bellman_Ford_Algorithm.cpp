
// Bellman-Ford gfg medium level question graph..


// class Solution {
//   public:
//     vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

//         vector<int>dist(V , 1e8); //1e8 is 10^8 
//         dist[src] = 0; //source 
//         int e = edges.size(); //number of edges 
        
//         //v-1 time it should iterate
//         for(int i=0 ; i<V-1 ; i++){
//             //relax alll the edges
//             bool flag = 0; //for the optmizing the approch means the iteration count if there is no change in the distance then return the dist
            
//             for(int j=0 ; j<e ; j++){
//                 int u = edges[j][0];
//                 int v = edges[j][1];
//                 int wt = edges[j][2]; //weight
                
//                  //edge casee if there it can't reach to that and 10^8 is there 
//                  if(dist[u]==1e8)
//                   continue;// then skip the iteration 
                
//                 //now update ditance if possible
//                 if(dist[u]+wt<dist[v]){
//                     dist[v] = dist[u]+wt; //update the distance if it's smaller
//                     flag = 1;
                    
//                 }
                
                
//             }
            
//             if(!flag) //the optmized if the distance is not updating return the dist
//              return dist;
//         }
        
        
//         //one more time for detecting the cycle is present
//          for(int j=0 ; j<e ; j++){
//                 int u = edges[j][0];
//                 int v = edges[j][1];
//                 int wt = edges[j][2]; //weight
                
//                  //edge casee if there it can't reach to that and 10^8 is there 
//                  if(dist[u]==1e8)
//                   continue;// then skip the iteration 
                
//                 //here updated then we have to provide the array as-1
//                 if(dist[u]+wt<dist[v]){
//                     vector<int>ans;
//                     ans.push_back(-1);
//                     return ans;
//                 }
//             }

//         return dist;
//     }
// };
