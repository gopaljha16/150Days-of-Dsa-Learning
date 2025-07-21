// Delete a node from BST gfg medium level question 

// class Solution {
//   public:
//     // Function to delete a node from BST.
//     Node *deleteNode(Node *root, int X) {
//         //base case
//          if(!root){ // null 
//              return NULL; 
//          }
         
//          //left side  data is greater than root then left 
//          if(root->data>X){
//              root->left = deleteNode(root->left , X);
//              return root;
//          }
//          //right side data is smaller then right
//          else if(root->data<X){
//              root->right = deleteNode(root->right , X);
//              return root;
//          }
         
//          // now main deletetion code
//          else{ //data ==target
//              //leaf node delete
//              if(!root->left && !root->right){
//                  delete root;
//                  return NULL;
//              }
             
//              //one child exisits
//              else if(!root->right){ //right null then only left child exisits
//                  Node *temp = root->left;
//                  delete root;
//                  return temp;
//              }
//              else if(!root->left){ //left null then right child exisits
//                  Node *temp = root->right;
//                  delete root;
//                  return temp;
//              }
             
//              //two child exisits
//              else{
//                  //find the greatest element from left approch 
//                  Node *child = root->left;
//                  Node *parent = root;
                 
//                  //right most node we have to reach so the iteration
//                  while(child->right){ // run till the right exisits
//                      parent = child;
//                      child = child->right;
//                  } //reached the child now 
//                  //now two codition which is root == parent , and not equal to parent
//                  if(root!=parent){
//                      parent->right = child->left;
//                      child->left = root->left;
//                      child->right = root->right;
//                      delete root;
//                      return child;
//                  }else{ //root equal to parent 
//                  child->right = root->right;
//                  delete root;
//                  return child;
                     
//                  }
//              }
//          }
//     }
// };