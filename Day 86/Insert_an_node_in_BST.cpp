//Insertthe node in bst;

// class Solution {
//   public:
//     Node* insert(Node* root, int key) {
//       //base case if null then insert
//       if(!root){
//           Node *temp = new Node(key);
//           return temp;
//       }
      
//       //left 
//       if(key<root->data){
//        root->left = insert(root->left , key);
//       }else if(key>root->data){ //right side
//        root->right = insert(root->right , key);    
//       }
      
//       return root;
      
//     }
// };