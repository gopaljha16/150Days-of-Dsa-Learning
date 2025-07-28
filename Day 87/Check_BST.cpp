// Gfg Check bst easy level question
//Method 1:using inorder traversal

// class Solution {
//   public:
  
//    void inorder(Node *root , vector<int>&ans){
//      if(!root)
//       return;
      
//       //left data right
//       inorder(root->left , ans);
//       ans.push_back(root->data);
//       inorder(root->right , ans);
//  }
//     // Function to check whether a Binary Tree is BST or not.
//     bool isBST(Node* root) {
     
//       vector<int>ans;
//       inorder(root , ans);
      
//       for(int i=1 ; i<ans.size() ; i++){
//           if(ans[i]<=ans[i-1])
//            return 0;
//       }
      
//       return 1;
      
        
//     }
// };


//method 2 using prev 
// class Solution {
//   public:
  
//   bool checkBst(Node *root , int &prev){
//        //base case
//        if(!root)
//         return 1;
        
//         //left side
//         if(!(checkBst(root->left , prev)))
//          return 0;
         
//         //data
//         if(root->data<=prev)
//         return 0;
        
//         //update prev if greater
//         prev = root->data;
        
//         //right side
//         return checkBst(root->right , prev);
//   }
 
//     // Function to check whether a Binary Tree is BST or not.
//     bool isBST(Node* root) {
     
//       int prev = INT_MIN;
//      return  checkBst(root , prev);
      
        
//     }
// };