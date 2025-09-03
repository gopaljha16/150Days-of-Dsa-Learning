// Covid Spread gfg medium level question solved using the bfs

// // User function Template for C++

// class Solution {
//   public:
//   int r,c;
//   int row[4] = {-1,1,0,0};
//   int col[4] = {0,0,-1,1};
  
//   bool valid(int i , int j){
//       return i>=0&&i<r&&j>=0&&j<c;
//   }
  
//     int helpaterp(vector<vector<int>> hospital) {
      
//       r = hospital.size(); //row
//       c = hospital[0].size(); //col
      
//       //bfs using so queue
//       queue<pair<int,int>>q; //row and col
      
//      //inser the covid patient into the queue
//      for(int i=0 ; i<r ; i++)
//       for(int j=0 ; j<c ; j++)
//       if(hospital[i][j]==2)
//         q.push(make_pair(i,j));
      
//       int timer = 0; //timer that we will return 
//       while(!q.empty()){
//           timer++; 
//           int curr_patient = q.size(); //for that timer section only
          
//           while(curr_patient--){
//               int i = q.front().first;
//               int j = q.front().second;
//               q.pop();
//               ///for all top , left , right , down
//               for(int k=0 ; k<4 ; k++){
//                   if(valid(i+row[k] , j+col[k]) && hospital[i+row[k]][j+col[k]] ==1){
//                       //now spread 
//                      hospital[i+row[k]][j+col[k]] = 2;
//                      q.push(make_pair(i+row[k] , j+col[k]));
//                   }
//               }
              
//           }
//       }
      
//       //check all the patient is infected or not
//        for(int i=0 ; i<r ; i++)
//       for(int j=0 ; j<c ; j++)
//       if(hospital[i][j]==1)
//        return -1; // not infected return -1
       
//     //edge case
//      if (timer == 0) return 0;
//        //or else 
//        return timer-1; 
//     }
// };
