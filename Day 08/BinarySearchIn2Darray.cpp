// Binary Search in 2D array leetcode meduim level question

// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n=matrix.size();
//     int m=matrix[0].size();
//     int start=0,mid,end=n*m-1 , row_index , col_index;
//     //binary search
//     while(start<=end){
//         mid = (start+end)/2;
//         row_index = mid / m;
//         col_index = mid % m;
        
//         if(matrix[row_index][col_index]==target)
//         return 1;
//         else if(matrix[row_index][col_index]>target)
//         end = mid-1;
//         else
//         start = mid+1;
//     }

//     return 0;
// }
