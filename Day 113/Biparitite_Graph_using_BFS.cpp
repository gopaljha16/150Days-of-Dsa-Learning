// Bipartite Graph gfg medium level problem 

// class Solution {
//   public:
//     bool isBipartite(int V, vector<vector<int>> &edges) {

//         vector<vector<int>>adj(V);
//         for(auto e:edges){
//             int u = e[0];
//             int v = e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         vector<int>color(V , -1); //initialize with -1 
//         queue<int>q; 
        
//         //for all the conneted and not connted graph 
//         for(int i=0 ; i<V ; i++){
//             if(color[i]==-1){ //not coloured 
//                 q.push(i);
//                 color[i] = 0;
                
//             while(!q.empty()){
//                 int node = q.front();
//                 q.pop();
                
//                //all nodes adj
//                for(int i=0 ; i<adj[node].size() ; i++){
                   
//                     //neightbours colored is not assingend 
//                    if(color[adj[node][i]]==-1){
//                        color[adj[node][i]] = (color[node]+1)%2; //for the opposite number getting 0 and 1
//                        q.push(adj[node][i]); //push that to the queue
//                    }
//                    else{ // the negibours are already colors
//                       //already color and neghbour is also same color
//                       if(color[node]==color[adj[node][i]]){
//                           return 0; //then it's not an bipartite graph 
//                       }
                       
//                    }
//                }
//             }
            
            
//             }
//         }
        
//         return 1;
//     }
    
// };
