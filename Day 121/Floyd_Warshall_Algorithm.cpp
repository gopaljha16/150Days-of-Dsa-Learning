// Floyd Warshall gfg medium level question 

// class Solution {
//   public:
//     void floydWarshall(vector<vector<int>> &dist) {
//        int n = dist.size();

//         for(int k=0; k<n; k++){
//             for(int j =0; j<n; j++){
//                 for(int i=0; i<n; i++){
//                     if(dist[j][k] != 1e8 && dist[k][i] != 1e8)
//                     dist[j][i] = min(dist[j][i], dist[j][k]+dist[k][i]);
//                 }
//             }
//         }
//     }
// };