// Rotate by 90 degree 
// first approach is clock wise 270 degree done by 90+90+90 then solution 

// 1st approach code
// void rotateby90(vector<vector<int>>& mat) {
   
//     int n = mat.size();
//     for(int i=0;i<3;i++){
//          for(int i=0;i<n-1;i++){
//            for(int j=i+1;j<n;j++){
//                swap(mat[i][j] , mat[j][i]);
//            }
//        }

//        // reverse the matrix
//        for(int i=0;i<n;i++){
//            int start=0, end = n-1;
//            while(start<end){
//                swap(mat[i][start] , mat[i][end]);
//                start++;
//                end--;
//            }
//        }
//     }
       
//    }


// 2bd approach is 
// transpose and then col-wise reverse then solution in 3 step...
// void rotateby90(vector<vector<int>>& mat) {
   
//     int n = mat.size();
//     //transpose
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             swap(mat[i][j] , mat[j][i]);
//         }
//     }
    
//     //col-wise reverse
//     for(int j=0;j<n;j++){
//         int start=0,end=n-1;
//         while(start<end){
//             swap(mat[start][j] , mat[end][j]);
//             start++;
//             end--;
//         }
//     }
       
//    }




//another approach 
// row-wise reverse then transpose the matrix
// void rotateby90(vector<vector<int>>& mat) {
   
//     int n = mat.size();
    
//     //row-wise reverse
//     for(int i=0;i<n;i++){
//            int start=0,end=n-1;
//            while(start<end){
//                swap(mat[i][start] , mat[i][end]);
//                start++;
//                end--;
//            }
//        }
    
    
    
//     //transpose
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             swap(mat[i][j] , mat[j][i]);
//         }
//     }
    
   
       
//    }