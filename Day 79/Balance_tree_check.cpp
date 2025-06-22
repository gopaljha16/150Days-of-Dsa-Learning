// Balanced Tree Check gfg easy level question 

// class Solution {
//   public:
  
//    int height(Node *root , bool &valid){
//         //base case
//         if(!root)
//          return 0;
         
//         //left right
//         int l = height(root->left , valid);
//         int r = height(root->right , valid);
        
//         //check balance condition
//         if(abs(l-r)>1){
//             valid = 0;
//         }
        
//         //return condtion means height finding and returing 
//         return 1+max(l,r);
//    }
    
//     bool isBalanced(Node* root) {
//         bool valid = 1; //for returning that the tree is balance
//         height(root , valid); //function
//         return valid; //valid return
        
//     }
// };


//more optimized and time saving 
// class Solution {
//   public:
  
//    int height(Node *root , bool &valid){
//         //base case
//         if(!root)
//          return 0;
         
//         //left right
//         int l = height(root->left , valid);
        
        
//         //if valid is 1 then only going to the right part
//         if(valid){
//             int r = height(root->right , valid);
        
//         //check balance condition
//         if(abs(l-r)>1){
//             valid = 0;
//         }
        
//         //return condtion means height finding and returing 
//         return 1+max(l,r);
//         }
        
//         return -1;
        
//    }
    
//     bool isBalanced(Node* root) {
//         bool valid = 1; //for returning that the tree is balance
//         height(root , valid); //function
//         return valid; //valid return
        
//     }
// };