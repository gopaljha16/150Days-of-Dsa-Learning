// Diagonal Tree Traversal gfg medium level question 

// class Solution {
//   public:
  
//    void findPos(Node *root , int pos , int &leftMost){
//        //base case
//        if(!root)
//         return;
    
//        leftMost = max(pos , leftMost); //maximum size we needed so
       
//        //left then right
//        findPos(root->left , pos+1 , leftMost);
//        findPos(root->right , pos , leftMost);
//    }
   
//    void findDiagonal(Node *root , int pos , vector<vector<int>>&ans){
//        //base case
//        if(!root)
//         return;
        
//        //insert element to the 2d array 
//        //node 
//        ans[pos].push_back(root->data);
//        //left
//       findDiagonal(root->left , pos+1 , ans);
//        //right
//       findDiagonal(root->right , pos , ans);//not increasing pos becuase right side left does't increases
       
//    }
  
//     vector<int> diagonal(Node *root) {
//         //left most
//         int leftMost = 0;
//         findPos(root , 0 , leftMost);
        
//         //now 2d array
//         vector<vector<int>>ans(leftMost+1);//size leftmost
//         //recursion using 
//         findDiagonal(root , 0 , ans);
        
//         //create 1d and push the 2d array elements
//         vector<int>result;
        
//         //insert element 
//         for(int i=0 ; i<ans.size() ; i++){
//             for(int j=0 ; j<ans[i].size() ; j++){
//                 result.push_back(ans[i][j]);
//             }
//         }
        
//         return result;
//     }
// };