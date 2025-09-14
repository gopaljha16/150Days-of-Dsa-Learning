// Circle of string gfg hard level question 

// User function Template for C++

// class Solution {
//   public:
  
//     void DFS(int node , vector<int>adj[] , vector<bool>&visited){
//         visited[node] = 1;
        
//         // all neightbour cover
//         for(int i=0 ; i<adj[node].size() ; i++){
//             if(!visited[adj[node][i]])
//              DFS(adj[node][i] , adj , visited);
//         }
//     }
  
//     int isCircle(vector<string> &arr) {
//         // adjcancecy list create
//         int n = arr.size();
//         vector<int>adj[26]; //becaause it;s a-0 , b-2 number so on z-25
//         vector<int>Indeg(26,0);
//         vector<int>outDeg(26,0);
        
//         // calculate
//         for(int i=0 ; i<n ; i++){
//             string temp = arr[i];
//             int u = temp[0]-'a'; //first 
//             int v = temp[temp.size()-1]-'a'; //last
//             adj[u].push_back(v);
//             // indegree and outdegree calculate
//             outDeg[u]++;
//             Indeg[v]++;
//         }
        
//         // culerian circuit
//         //if indegree and outdegree is not equal then there is no cyucle is present
//         for(int i=0 ; i<26 ; i++){
//             if(Indeg[i]!=outDeg[i]) // not equal
//               return 0;
//         }
        
//         // so here non zero and two and here every node is conneted to the single component
//         vector<bool>visited(26,0);
//         int node = arr[0][0] -'a'; //for the first ele
//         DFS(node , adj  , visited);
        
//         // we got the information so here if the indegree exists but it's not visited then it's no ancycle or cicle of string
//         for(int i=0 ; i<26 ; i++){
//             if(Indeg[i]&&!visited[i])
//              return 0;
//         }
        
//         // so here all coveed and vertices
//         return 1;
        
//     }
// };