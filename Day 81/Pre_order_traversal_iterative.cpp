// Preorder traversal (Iterative) gfg medium level question 

// class Solution {
//   public:
//     vector<int> preOrder(Node* root) {
//        stack<Node*>st;
//        vector<int>ans;
//        st.push(root);
       
//        while(!st.empty()){
//           Node *temp = st.top();
//           st.pop();
          
//           ans.push_back(temp->data);
          
//           //first right then left
//           if(temp->right){
//               st.push(temp->right);
//           }
//           if(temp->left){
//               st.push(temp->left);
//           }
//        }
       
//        return ans;
        
//     }
// };