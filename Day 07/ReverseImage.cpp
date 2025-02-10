//  Reverse Image Leetcode Question medium level(48)

// void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
    
//     //transpose the matrix
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             swap(matrix[i][j] , matrix[j][i]);
//         }
//     }

//     // reverse the matrix
//     for(int i=0;i<n;i++){
//         int start=0, end = n-1;
//         while(start<end){
//             swap(matrix[i][start] , matrix[i][end]);
//             start++;
//             end--;
//         }
//     }
// }