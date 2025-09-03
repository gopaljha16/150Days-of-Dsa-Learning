//  Replace O's with X's gfg medium level question 


// User function Template for C++

// class Solution {
//   public:
//   int r , c; // row and col
//   int row[4] = {-1 , 1 , 0 , 0};
//   int col[4] = {0 , 0 , -1 , 1};
 
//   //for valid checking
//   bool valid(int i , int j){
//       return i>=0 && i<r && j>=0 && j<c;
//   }

//   vector<vector<char>> fill(vector<vector<char>>& mat) {
//       int n = mat.size();
//       int m = mat[0].size();
      
//       r = n;
//       c = m;
      
//       // applying the bfs operation from the border
//       queue<pair<int , int>> q;
      
//       // first row
//       for(int j=0 ; j<c ; j++){
//           if(mat[0][j]=='O'){
//               q.push({0,j});
//               mat[0][j] = 'T';
//           }
//       }
      
//       // first col
//       for(int i=0 ; i<r ; i++){
//           if(mat[i][0]=='O'){
//               q.push({i,0});
//               mat[i][0] = 'T';
//           }
//       }
      
//       // last row 
//       for(int j=0 ; j<c ; j++){
//           if(mat[r-1][j]=='O'){
//               q.push({r-1,j});
//               mat[r-1][j] = 'T';
//           }
//       }
      
//       // last col
//       for(int i=0 ; i<r ; i++){
//           if(mat[i][c-1]=='O'){
//               q.push({i,c-1});
//               mat[i][c-1] = 'T';
//           }
//       }
      
//       // bfs apply
//       while(!q.empty()){
//           int i = q.front().first;
//           int j = q.front().second;
//           q.pop();
          
//           for(int k=0 ; k<4 ; k++){
//               int ni = i + row[k];
//               int nj = j + col[k];
              
//               if(valid(ni , nj) && mat[ni][nj]=='O'){
//                   mat[ni][nj] ='T';
//                   q.push({ni, nj});
//               }
//           }
//       }
      
//       // replace all O with X and T with O
//       for(int i=0  ; i<r ; i++){
//           for(int j=0 ; j<c ; j++){
//               if(mat[i][j]=='O')
//                   mat[i][j]='X';
//               else if(mat[i][j]=='T')
//                   mat[i][j]='O';
//           }
//       }
      
//       return mat;
//   }
// };
