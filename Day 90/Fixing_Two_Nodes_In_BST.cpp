// Fixing two node in the bst gfg hard level question


/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/
// class Solution {
//   public:
//     void correctBST(Node* root) {
//     Node *curr = NULL;
//     Node *first = NULL , *second = NULL;
//     Node *last = NULL , *present = NULL;
    
//     //using morris traversal
//     while(root){
        
//         //if left doesn't exists
//         if(!root->left){
//             last = present;
//             present = root;
            
//             //Data issue 
//             if(last && last->data > present->data){
//                 if(!first){ //first issue
//                     first = last; 
//                 }
                
//                 second = present;
//             }
//             root = root->right;
//         }else{ //left exists
//              curr = root->left; 
//              while(curr->right && curr->right != root){ // rightmost and not equal to root
//                  curr = curr->right;
//              }
             
//              //left not traversed
//              if(curr->right == NULL){ // 
//                  curr->right = root;
//                  root = root->left;
//              }
//              else{ //left traversed
//                  curr->right = NULL;
//                  last = present;
//                  present = root;
                 
//                  if(last && last->data > present->data){
//                     if(!first){ //first issue
//                         first = last; 
//                     }
//                     second = present;
//                 }
//                 root = root->right;
//              }
//         }
//     }

//     int num = first->data;
//     first->data = second->data;
//     second->data = num; 
//     }
// };

    
    