// Find whether path exist gfg medium level question

// class Solution {
//   public:
   
 
//    // Function to find whether a path exists from the source to destination.
 
//       int row[4] = {1,-1,0,0};
//       int col[4] = {0,0,1,-1};
      
//       bool valid(int i , int j , int n){
//           return i>=0&&j>=0&&i<n&&j<n;
//       }
//     bool is_Possible(vector<vector<int>>& grid) {
//        int n = grid.size();
       
//         int src_i = -1, src_j = -1;

//         // Find the source (cell with value 1)
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j] == 1){
//                     src_i = i;
//                     src_j = j;
//                     break;
//                 }
//             }
//         }
       
//        queue<pair<int,int>>q; //row and col 
//        q.push({src_i , src_j});
//        grid[src_i][src_j] = 0; //vvisted then mark it o
       
//        while(!q.empty()){
//            int i= q.front().first;
//            int j = q.front().second;
//            q.pop();
           
//            if(grid[i][j] == 2) return true;

           
//            for(int k=0 ; k<4 ; k++){
//                int new_i = i+row[k];
//                int new_j = j+col[k];
               
//                if(valid(new_i , new_j , n) && grid[new_i][new_j] !=0 ){
                   
//                    if(grid[new_i][new_j]==2)
//                      return true;
                   
//                    grid[new_i][new_j] = 0;
//                    q.push({new_i , new_j});
//                }
//             }
//        }
       
        
//         // if we didn't get the source
//         return false;
//     }
// };