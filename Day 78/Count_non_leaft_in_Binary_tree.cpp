//Count Non Leaf Node in Binary Tree. gfg basic question 
//method 1 
// class Solution {
//   public:
  
//   void countleaf(Node *root , int &count){
//       if(root==NULL)
//        return;
       
//        if(!root->left &&  !root->right){
//            return;
//        }
       
//        count++;
//        countleaf(root->left , count);
//        countleaf(root->right , count);
//   }
   
//     int countNonLeafNodes(Node* root) {
         
//          int count = 0;
//          countleaf(root, count);
//          return count;
//     }
// };


//method -2 
// class Solution {
//   public:
  
 
   
//     int countNonLeafNodes(Node* root) {
         
//          if(!root)
//          return 0;
         
//          if(!root->left && !root->right)
//          return 0;
         
//          return 1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right);
//     }
// };