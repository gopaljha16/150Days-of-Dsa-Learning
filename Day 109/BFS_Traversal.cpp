//  Bfs traveral gfg easy level question 

// class Solution {
//   public:
//     // Function to return Breadth First Traversal of given graph.
//     vector<int> bfs(vector<vector<int>> &adj) { 
//         queue<int>q;
//         int v = adj.size();
//         vector<bool>visited(v,0); // visisted elemented initially 0
//         //starting from
//         q.push(0);
//         visited[0] = 1; // visited updating 0 to 1
        
//         vector<int>ans; //for returning the answer
//         int node;
//         //now the traversing
//         while(!q.empty()){ // traversing till queue is empty
//             node = q.front(); //front element
//             q.pop(); // popping from the queue
//             ans.push_back(node); // pushing the front element into the answer
           
//            //now we have to visited the neighbour if not visited add into queue
//            //here we have to traverse the adj vector which has the edges
//            for(int i=0 ; i<adj[node].size() ; i++){
//                if(!visited[adj[node][i]]){ // unvisited
//                 visited[adj[node][i]] = 1; //make it visited
//                 q.push(adj[node][i]); //push into the queue
//                }
//            }
//         }
        
//         return ans;
//     }
// };