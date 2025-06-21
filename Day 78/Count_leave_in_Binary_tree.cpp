// Count Leaves in Binary Tree gfg quesition basic

// class Solution {
//   public:
  
//   void countLeaf(Node *root , int &count){
//       if(root==NULL){
//           return;
//       }
      
//       if(!root->left && !root->right){
//           count++;
//           return;
//       }
      
//       countLeaf(root->left , count);
//       countLeaf(root->right , count);
      
//   }
  
//   // Function to count the number of leaf nodes in a binary tree.
//     int countLeaves(Node* root) {
//         // write code here
//         int count = 0;
//         countLeaf(root , count);  
//         return count;
        
//     }
// };

// //method 02 class Solution {
//   public:
  

//   // Function to count the number of leaf nodes in a binary tree.
//     int countLeaves(Node* root) {
//         // write code here
//          if(!root)
//          return 0;
         
//          if(!root->left && !root->right){
//              return 1;
//          }
         
//          return countLeaves(root->left)+ countLeaves(root->right);
    
//     }
// };