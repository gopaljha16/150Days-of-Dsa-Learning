//Mirror Tree gfg easy level question 


// class Solution {
//   public:
//     // Function to convert a binary tree into its mirror tree.
//     void mirror(Node* root) {
//         //base case
//         if(root==NULL)
//          return;
         
//         //swapping the left to right and right to left
//         Node *temp = root->right;
//         root->right = root->left;
//         root->left = temp;
        
//         //now move down by again 
//         mirror(root->left); //move to left 
//         mirror(root->right); //move to right
        
//     }
// };