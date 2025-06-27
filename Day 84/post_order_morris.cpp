// Morris Post Order traversal gfgmedim level question 


// class Solution {
//   public:
//     vector<int> postOrder(Node* root) {
//         vector<int>ans;
//       //until the root exisits
//       while(root){
//           //right part doesn't exisits
//           if(!root->right){ //doesn't exisits then insert in ans then move to right
//               ans.push_back(root->data);
//               root = root->left;
//           }
//           //right part exisits
//           else{
//               Node *curr = root->right; //rgiht exisits so iteration
//               //check the link already exisits or not
//               while(curr->left && curr->left!=root){
//                   curr = curr->left;
//               }
//               //right part subtree not travesed
//               if(curr->left==NULL){ 
//                  ans.push_back(root->data); //push the values
//                   curr->left = root;
//                   root = root->right; 
//               }else{ //right sub tree traversed
//                   curr->left = NULL; //then make it null 
//                   root = root->left; //move to right
//               }
//           }
//       }
      
//          reverse(ans.begin() , ans.end());
//          return ans;
        
//     }
// };