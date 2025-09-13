// Shortest Source to Destination Path gfg medium level question 

// // User function Template for C++

// class Solution {
//   public:
    
//     int row[4] = {1,-1,0,0};
//     int col[4] = {0,0,1,-1};
    
//     bool valid(int i , int j , int n , int m){
//         return i>=0&&j>=0&&i<n&&j<m;
//     }
  
//     int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
          
//         //   edge cases
//         if(X==0 && Y==0) // if the src and destination are at 0 then 0th step
//          return 0;
         
//         if(!A[0][0]) //if the we move becuase source is 0 then return -1
//           return -1;
          
//         queue<pair<int,pair<int, int>>>q; // row , col , step
        
//         q.push({0 , {0,0}});
        
//         vector<vector<bool>>visited(N , vector<bool>(M,0));
//         visited[0][0] = 1; //src visited 1
        
//         while(!q.empty()){
//             int i = q.front().first;
//             int j = q.front().second.first; //col
//             int step = q.front().second.second; // step
//             q.pop();
            
//             // now up down , left right
//             for(int k=0 ; k<4 ; k++){
//                 int new_i = i+row[k];
//                 int new_j = j+col[k];
                
//                 if(valid(new_i , new_j , N , M) && A[new_i][new_j] && !visited[new_i][new_j]){
                    
//                     // if it's reaceeed to the destinatation then return the step
//                     if(new_i==X && new_j==Y)
//                       return step+1;
                    
//                     visited[new_i][new_j] = 1; //visted marked
//                     q.push({new_i,{new_j , step+1}});
//                 }
//             }
//         }
        
//         return -1; //if can't able to reach the destination 
//     }
// };

// Optimized approch without visited
// User function Template for C++

// class Solution {
//   public:
    
//     int row[4] = {1,-1,0,0};
//     int col[4] = {0,0,1,-1};
    
//     bool valid(int i , int j , int n , int m){
//         return i>=0&&j>=0&&i<n&&j<m;
//     }
  
//     int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
          
//         //   edge cases
//         if(X==0 && Y==0) // if the src and destination are at 0 then 0th step
//          return 0;
         
//         if(!A[0][0]) //if the we move becuase source is 0 then return -1
//           return -1;
          
//         queue<pair<int,pair<int, int>>>q; // row , col , step
        
//         q.push({0 , {0,0}});
        
//         A[0][0] = 0; //src visited 1
        
//         while(!q.empty()){
//             int i = q.front().first;
//             int j = q.front().second.first; //col
//             int step = q.front().second.second; // step
//             q.pop();
            
//             // now up down , left right
//             for(int k=0 ; k<4 ; k++){
//                 int new_i = i+row[k];
//                 int new_j = j+col[k];
                
//                 if(valid(new_i , new_j , N , M) && A[new_i][new_j]){
                    
//                     // if it's reaceeed to the destinatation then return the step
//                     if(new_i==X && new_j==Y)
//                       return step+1;
                    
//                     A[new_i][new_j] = 0; //visted marked
//                     q.push({new_i,{new_j , step+1}});
//                 }
//             }
//         }
        
//         return -1; //if can't able to reach the destination 
//     }
// };

// without step calcuation 

// User function Template for C++

// class Solution {
//   public:
    
//     int row[4] = {1,-1,0,0};
//     int col[4] = {0,0,1,-1};
    
//     bool valid(int i , int j , int n , int m){
//         return i>=0&&j>=0&&i<n&&j<m;
//     }
  
//     int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
          
//         //   edge cases
//         if(X==0 && Y==0) // if the src and destination are at 0 then 0th step
//          return 0;
         
//         if(!A[0][0]) //if the we move becuase source is 0 then return -1
//           return -1;
         
//         int step =0; 
//         queue<pair<int ,int>>q; // row , col
        
//         q.push({0 ,0});
        
//         A[0][0] = 0; //src visited 
        
//         while(!q.empty()){
//             int count = q.size();
//             while(count--){
                
//              int i = q.front().first; //row 
//             int j = q.front().second;  //col
//             q.pop();
            
//                // now up down , left right
//             for(int k=0 ; k<4 ; k++){
//                 int new_i = i+row[k];
//                 int new_j = j+col[k];
                
//                 if(valid(new_i , new_j , N , M) && A[new_i][new_j]){
                    
//                     // if it's reaceeed to the destinatation then return the step
//                     if(new_i==X && new_j==Y)
//                       return step+1;
                    
//                     A[new_i][new_j] = 0; //visted marked
//                     q.push({new_i,new_j});
//                 }
//             }
            
            
//             }
           
//            step++;
            
         
//         }
        
//         return -1; //if can't able to reach the destination 
//     }
// };