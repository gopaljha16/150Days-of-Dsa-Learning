//  Directed Graph Cycle gfg medium level question 

//using dfs method path and visited for optimizing
// class Solution {
//   public:
  
//     bool cycle(int node , vector<vector<int>>&adj , vector<bool>&path , vector<bool>&visited){
       
//        visited[node] = 1;
//        path[node] = 1;
       
//        //now neighbours check 
//        for(int i=0 ; i<adj[node].size() ; i++){
//            //check if pathh is exists then return1 
//            if(path[adj[node][i]])
//              return 1;
           
//            //if already visited then skip the iteration         
//            if(visited[adj[node][i]])
//             continue;
            
//            if(cycle(adj[node][i] , adj  , path , visited))
//             return 1;
//        }
       
       
//        //if there is not cycle then make it zero
//        path[node] = 0;
//        return 0; //no cycle detedted then return 0;
       
//     }
  
//     bool isCyclic(int V, vector<vector<int>> &edges) {
     
//        vector<vector<int>>adj(V); //for adj list
//        for(auto e : edges){
//           int u = e[0];
//           int v = e[1];
//           adj[u].push_back(v);
//        }
       
//        vector<bool>visited(V, 0);
//        vector<bool>path(V,0);
       
//        //for non conneted graph so here all vertiices should be visited
//        for(int i=0 ; i <V ; i++){
//            if(!visited[i] && cycle(i , adj , path , visited))
//              return 1;
//        }
       
//        return 0;
        
//     }
// };


//another method using kahn's algorithm 

// class Solution {
//   public:

  
//     bool isCyclic(int V, vector<vector<int>> &edges) {
     
//        vector<vector<int>>adj(V); //for adj list
//        for(auto e : edges){
//           int u = e[0];
//           int v = e[1];
//           adj[u].push_back(v);
//        }
       
//         vector<int>inDegree(V , 0);//initially 0
        
//         //now update the indgree
//         for(int i=0 ; i<V ; i++){
//             for(int j=0 ;j<adj[i].size() ; j++){ //for adjacement
//                 inDegree[adj[i][j]]++;
//             }
//         }
        
//         queue<int>q;
//         //now if the indegree value is  0 then push to the queue
//         for(int i=0 ; i<V ; i++){
//             if(!inDegree[i]) //if 0 then push to queue
//                q.push(i);
//         }
        
//         int count = 0; //for counting the element which was pushed to the answer
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             count++;
            
//             //nowyou popped then remove the indegree from there if it becomes zero and push to the quee
//             for(int i=0 ; i<adj[node].size() ; i++){
//                 inDegree[adj[node][i]]--; //decrease by 1
                
//                 //if degree becomes zero then push to the queue
//                 if(!inDegree[adj[node][i]])
//                  q.push(adj[node][i]);
//             }
//         }
        
//         return count!=V;
        
        
//     }
// };
