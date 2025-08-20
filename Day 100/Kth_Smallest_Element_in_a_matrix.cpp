// Kth smallest element in a Matrix gfg medium level question..

// class Solution {
//   public:
//     int kthSmallest(vector<vector<int>> &mat, int k) {
        
//         int n = mat.size();
        
//         //create min heap with 0(n) tc
//         priority_queue<
//         pair<int,pair<int,int>>,
//         vector<pair<int,pair<int,int>>>,
//         greater<pair<int,pair<int,int>>>>p;
        
//          for(int i=0 ; i<n ; i++){
//             p.push(make_pair(mat[i][0] , make_pair(i,0)));
//         }

//         int ans = -1;
//         pair<int,pair<int , int>>element;
//         int i , j; // for row and column
//         while(k--){
//             element = p.top();
//             p.pop();
//             ans = element.first; //value..
//             i = element.second.first; //row
//             j = element.second.second; //col
         
//          // push element in queue
//          if(j+1<n){ //j should be not greater than the col created.
//               p.push(make_pair(mat[i][j+1] , make_pair(i,j+1)));
//          }
//         }
        
//         return ans;
//     }
// };

