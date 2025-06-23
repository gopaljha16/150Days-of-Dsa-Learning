// post order traversal gfg medium level question 

// class Solution {
//   public:
//     vector<int> postOrder(Node* root) {
//          stack<Node *>st;
//          vector<int>ans;
//          st.push(root);
//          //doing with the nrl and reversing
//          while(!st.empty()){
//              Node *temp = st.top();
//              st.pop();
             
//              ans.push_back(temp->data);
             
//               if(temp->left){
//                  st.push(temp->left);
//              }
           
//              if(temp->right){
//                  st.push(temp->right);
//              }
              
//          }
         
//          reverse(ans.begin() , ans.end());
//          return ans;
        
//     }
// };