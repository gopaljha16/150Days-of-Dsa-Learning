// Check wether BST is Dead end gfg medium level question 


/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

// class Solution {
//   public:
   
//     bool Dead(Node *root , int lower , int upper){
//         // base case
//         if(!root) // not root
//          return 0;
         
//         //leaf node
//         if(!root->left && !root->right){
//             if(root->data-lower==1 && upper-root->data==1){
//                 return 1; //dead end
//             }else{
//                 return 0; //not an dead end
//             }
//         }
//         // move left and right
//         return Dead(root->left , lower , root->data ) || Dead(root->right , root->data , upper);
//     }
    
//     bool isDeadEnd(Node *root) {
   
//       return Dead(root , 0 , INT_MAX);
        
//     }
// };