// Two  Trees are identical gfg easy level question 
// class Solution {
//   public:
//     // Function to check if two trees are identical.
//     bool isIdentical(Node *r1, Node *r2) {
//         //base case
//         if(r1==NULL && r2==NULL)
//          return 1;
         
//         if((!r1 && r2) || (r1 && !r2))
//          return 0;
        
//         if(r1->data != r2->data) //element which are not equal then return 0
//          return 0;
         
//         //from here equal then 
//         return isIdentical(r1->left , r2->left)&& isIdentical(r1->right , r2->right); 
        
//     }
// };
