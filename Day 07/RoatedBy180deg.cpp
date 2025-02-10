// Rotate a Matrix by 180 Counterclockwise gfg 
// 1st approach 90deg + 90deg

// 2nd approach is col-wise revers and row-wise reverse
// void rotateMatrix(vector<vector<int>>& mat) {
//     int n = mat.size();
//     // col-wise reverse
//     for(int j=0;j<n;j++){
//         int start =0,end=n-1;
//         while(start<end){
//             swap(mat[start][j] , mat[end][j]);
//             start++;
//             end--;
//         }
//     }
    
//     // row-wise reverse
//     for(int i=0;i<n;i++){
//         int start=0,end=n-1;
//         while(start<end){
//             swap(mat[i][start] , mat[i][end]);
//             start++;
//             end--;
//         }
//     }
// }