// Knight Walk gfg medium level question 

// class Solution {
//   public:
//   int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
//    int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};
  
//   bool valid(int i , int j , int n){
//       return i>=0 && j>=0 && i<n && j<n;
//   }
//     int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
       
//         //0based indexing 
//         KnightPos[0]--;
//         KnightPos[1]--;
//         TargetPos[0]--;
//         TargetPos[1]--;
//         // base case if it's on that position 
//         if(TargetPos[0]==KnightPos[0] && TargetPos[1]==KnightPos[1])
//          return 0; //on that step only we got
         
//         queue<pair<int,int>>q; //bfs
//         vector<vector<bool>>chess(N , vector<bool>(N,0));
//         q.push({KnightPos[0] , KnightPos[1]}); //initally 0
//         chess[KnightPos[0]][KnightPos[1]] = 1;
        
//         int step = 0;
//         while(!q.empty()){
//             int count = q.size(); //till the size level order traversal
        
//             while(count--){
//                 int i = q.front().first; ///row 
//                 int j = q.front().second; // col
//                 q.pop();
                
//                 //all possible position 
//                 for(int k=0 ; k<8 ; k++){
//                     int new_i = i+row[k];
//                     int new_j = j+col[k];
                    
//                     if(valid(new_i , new_j , N) && !chess[new_i][new_j]){
                       
//                     //   if it reaches to the target then step return 
//                        if(new_i == TargetPos[0] && new_j == TargetPos[1]){
//                            return step+1;
//                        }
                       
//                         chess[new_i][new_j] = 1; //mark it visited
//                         q.push({new_i , new_j});
//                     }
//                 }
                
               
//             }
            
//              step++; //increase the step
            
              
//         }
        
//          return -1; //if can't reach to the target  
//     }
// };