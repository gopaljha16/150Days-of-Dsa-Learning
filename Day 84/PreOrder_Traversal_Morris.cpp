// Preorder traversal morris Traversal.

//here time complexity is O(n ) and space complexity O(1);


// class Solution {
//   public:
//     vector<int> preOrder(Node* root) {
//        vector<int>ans;
//       //until the root exisits
//       while(root){
//           //left part doesn't exisits
//           if(!root->left){ //doesn't exisits then insert in ans then move to right
//               ans.push_back(root->data);
//               root = root->right;
//           }
//           //left part exisits
//           else{
//               Node *curr = root->left; //left exisits so iteration
//               //check the link already exisits or not
//               while(curr->right && curr->right!=root){
//                   curr = curr->right;
//               }
//               //left part subtree not travesed
//               if(curr->right==NULL){ 
//                  ans.push_back(root->data); //push the values
//                   curr->right = root;
//                   root = root->left; 
//               }else{ //left sub tree traversed
//                   curr->right = NULL; //then make it null 
//                   root = root->right; //move to right
//               }
//           }
//       }
      
//       return ans;
        
//     }
// };