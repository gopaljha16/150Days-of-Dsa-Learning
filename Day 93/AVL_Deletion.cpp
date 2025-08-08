//gfg avl tree deletion hard level question


// /* Node is as follows:

// struct Node
// {
//     int data, height;
//     Node *left, *right;
//     Node(int x)
//     {
//         data = x;
//         height = 1;
//         left = right = NULL;
//     }
// };

// */


//   int getHeight(Node *root){
//     //null
//     if(!root)
//      return 0;
    
//     //exists
//     return root->height;
// }


// int getBalance(Node *root){
//     return getHeight(root->left)-getHeight(root->right);
// }

// Node *rightRotation(Node *root){
//   Node *child = root->left;
//   Node *childRight = child->right;

//   //update
//   child->right = root;
//   root->left = childRight;

//   //update height
//   root->height = 1+max(getHeight(root->left),getHeight(root->right));
//   child->height = 1+max(getHeight(child->left) , getHeight(child->right));

//   return child;
// }

// Node *leftRotation(Node *root){
//     Node *child = root->right;
//     Node *childLeft = child->left;

//     //update
//     child->left = root;
//     root->right = childLeft;

//     //update height
//       root->height = 1+max(getHeight(root->left),getHeight(root->right));
//       child->height = 1+max(getHeight(child->left) , getHeight(child->right));

//   return child;

// }

// Node* deleteNode(Node* root, int key) {
//     // root null 
//     if(!root){
//         return NULL;
//     }
    
    
//     // left side
//     if(key<root->data){
//     root->left = deleteNode(root->left , key);
//     }
//     //right suide
//     else if(key>root->data){
//         root->right = deleteNode(root->right , key);
//     }
//     //both side child
//     else{
//         //leaf node
//         if(!root->left  && !root->right){
//             delete root;
//             return NULL;
//         }
//         //only one child exists
//         else if(!root->right && root->left) // left child side eixists
//         {
//             Node *temp = root->left;
//             delete root;
//             return temp;
//         }else if(root->right && !root->left){ //right child side exists
//             Node *temp = root->right;
//             delete root;
//             return temp;
//         }else{ //both side child exists
//             //right side smallest element
//             Node *curr = root->right;
//             while(curr->left){
//                 curr = curr->left;
//             }
//             root->data = curr->data;
            
//             //delete 
//             root->right = deleteNode(root->right , curr->data);
//         }
//     }
    
    
//     //update thje height
//     root->height =  1+max(getHeight(root->left), getHeight(root->right));
    
//     //check the balance
//     int balance  = getBalance(root);
    
//     //left side
//     if(balance>1){
//         //left left
//        if(getBalance(root->left)>=0)
//          return rightRotation(root);
           
//      //left right
//      root->left = leftRotation(root->left);
//      return rightRotation(root);
//     }
//     else if(balance<-1){
//         //right right
//         if(getBalance(root->right)<=0)
//             return leftRotation(root);
        
//         //right left
//         root->right = rightRotation(root->right);
//         return leftRotation(root);
//     }else{
//         //no rotation
//         return root;
//     }

    
// };