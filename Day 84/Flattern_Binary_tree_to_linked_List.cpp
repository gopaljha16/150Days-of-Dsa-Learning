// Flatern Binary tree to linked list

// class Solution {
//   public:
//     void flatten(Node *root) {
      
//       while(root){ //till root exisits
//           //left part doesn't exisits
//          if(!root->left){
//              root = root->right; //go to right side
//          }
//           //left par exisits
//          else{
//              Node *curr = root->left;
//              while(curr->right){ //move it to right most till the right is null
//                  curr = curr->right;
//              }
             
//              curr->right = root->right; //connect to root right
//              root->right = root->left; // connect to root left side
//              root->left = NULL; //disconnct it make it null
//              //move to right side
//              root = root->right; //becuase we have linked all to right side
//          }
//       }
//     }
// };