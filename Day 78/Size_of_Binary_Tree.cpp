// gfg size of binary tree basic question 

//method -1 preorder using and counting
// class Solution {
//   public:
  
//     void total(Node *root , int &count){
//         //base case
//         if(root==NULL)
//          return;
         
//          count++;
//          total(root->left, count);
//          total(root->right , count);
//     } 
  
//     int getSize(Node* node) {
//         int count = 0;
//         total(node , count);
//         return count;
//     }
// };

//Method 2 (1+totalNodein left side + totalNodein right side);
// class Solution {
//   public:
  
//     int totalNode(Node *root ){
//         //base case
//         if(root==NULL)
//          return 0;
         
//          return (1+totalNode(root->left) + totalNode(root->right));
//     } 
  
//     int getSize(Node* node) {
//       return  totalNode(node);
//     }
// };