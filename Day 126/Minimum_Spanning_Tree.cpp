// Krushkal Algorithm -> Minimum Spanning Tree gfg medium level question 

// class Solution {
//   public:
  
// //   Krushkal algorithm (cisjoint set)
//     int FindParent(int u , vector<int>&parent){
//         if(u==parent[u]){ //base case
//             return u;
//         }
        
//         // by using this it will be implementing the path compression
//         return parent[u] = FindParent(parent[u] , parent);
//     }
    
//     void unionByRank(int u , int v , vector<int>&parent , vector<int>&rank){
//         // fidn the ultimate parent
//         int pu = FindParent(u , parent);
//         int pv = FindParent(v , parent);
        
//         //fidn  the rank and then merge it
//         if(rank[pu] >rank[pv]){ // u is greater then v
//             parent[pv] = pu;
//         }
//         else if(rank[pu]<rank[pv]){ //rank u is greater than v
//             parent[pu] = pv; 
//         }else{
//             //both are the same rank then anything and rank increase
//           parent[pv] = pu;
//          rank[pu]++;
//         }
//     }
  
//     int spanningTree(int V, vector<vector<int>>& edges) {
       
//          //creating adj 
//         int n = edges.size();
//         vector<pair<int,int>>adj[V];
//         for(int i=0 ; i<n ; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int wt = edges[i][2];
            
//             adj[u].push_back({v , wt});
//             adj[v].push_back({u , wt});
//         }
        
        
//         vector<int>parent(V);
//         vector<int>rank(V, 0);
        
//         for(int i=0 ; i<V ; i++){ //update all the parent
//             parent[i] = i;
//         }
        
//         //prioriry qeueu->heap
//       priority_queue<
//     pair<int, pair<int,int>>,
//     vector<pair<int, pair<int,int>>>,
//     greater<pair<int, pair<int,int>>>
// > p;
        
        
//         //push to the heap (minheap)
//         for(int i=0 ; i<V ; i++){
//             for(int j=0 ; j<adj[i].size() ; j++){
//                 p.push({adj[i][j].second , {i , adj[i][j].first}});
//             }
//         }
        
//         int cost = 0,edge = 0;
//         while(!p.empty()){
//             int wt = p.top().first;
//             int u =  p.top().second.first;
//             int v = p.top().second.second;
//             p.pop();
            
//             ///check if they are in the different set
//             if(FindParent(u,parent)!=FindParent(v, parent)){
//                 cost+=wt; //weight add
//                 unionByRank(u,v,parent,rank);
                //   edge++;
//             }
//             // for more optimization 
//             if(edge==V-1)
//             break;
//         }
//         return cost;
//     }
// };

// more optmization here for the best cases by sorting 


// class Solution {
//   public:
  
// //   Krushkal algorithm (cisjoint set)
//     int FindParent(int u , vector<int>&parent){
//         if(u==parent[u]){ //base case
//             return u;
//         }
        
//         // by using this it will be implementing the path compression
//         return parent[u] = FindParent(parent[u] , parent);
//     }
    
//     void unionByRank(int u , int v , vector<int>&parent , vector<int>&rank){
//         // fidn the ultimate parent
//         int pu = FindParent(u , parent);
//         int pv = FindParent(v , parent);
        
//         //fidn  the rank and then merge it
//         if(rank[pu] >rank[pv]){ // u is greater then v
//             parent[pv] = pu;
//         }
//         else if(rank[pu]<rank[pv]){ //rank u is greater than v
//             parent[pu] = pv; 
//         }else{
//             //both are the same rank then anything and rank increase
//           parent[pv] = pu;
//          rank[pu]++;
//         }
//     }
  
//     int spanningTree(int V, vector<vector<int>>& edges) {
       
//          //creating adj 
//         int n = edges.size();
//         vector<pair<int,int>>adj[V];
//         for(int i=0 ; i<n ; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int wt = edges[i][2];
            
//             adj[u].push_back({v , wt});
//             adj[v].push_back({u , wt});
//         }
        
        
//         vector<int>parent(V);
//         vector<int>rank(V, 0);
        
//         for(int i=0 ; i<V ; i++){ //update all the parent
//             parent[i] = i;
//         }
        
//         vector<pair<int, pair<int,int>>>temp;
        
//         //push to the temp (minheap)
//         for(int i=0 ; i<V ; i++){
//             for(int j=0 ; j<adj[i].size() ; j++){
//                 temp.push_back({adj[i][j].second , {i , adj[i][j].first}});
//             }
//         }
        
        
        
//         //prioriry qeueu->heap
//       priority_queue<
//     pair<int, pair<int,int>>,
//     vector<pair<int, pair<int,int>>>,
//     greater<pair<int, pair<int,int>>>
// > p(temp.begin() , temp.end());
        
        
        
//         int cost = 0,edge = 0;
//         while(!p.empty()){
//             int wt = p.top().first;
//             int u =  p.top().second.first;
//             int v = p.top().second.second;
//             p.pop();
            
//             ///check if they are in the different set
//             if(FindParent(u,parent)!=FindParent(v, parent)){
//                 cost+=wt; //weight add
//                 unionByRank(u,v,parent,rank);
//                 edge++;
//             }
//             // for more optimization 
//             if(edge==V-1)
//             break;
//         }
//         return cost;
//     }
// };