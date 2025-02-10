// Search in a sorted Matrix row and col..(gfg medium question)

 // Function to search a given number in row-column sorted matrix.
//  bool searchMatrix(vector<vector<int>> &mat, int x) {
//     int n=mat.size();
//     int m=mat[0].size();
//     int i=0,j=m-1;
//     while(i<n && j>=0){
//         if(mat[i][j]==x)
//         return 1;
//         else if(mat[i][j]<x)
//         i++;
//         else
//         j--;
//     }
// return 0;
// }