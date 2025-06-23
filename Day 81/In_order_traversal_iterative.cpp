// Iterative Inorder without using recursion gfg medium level question 
// class Solution {
//   public:
//     vector<int> inOrder(Node* root) {
//       stack<Node*>st;
//       stack<bool>visited;
//       st.push(root);
//       visited.push(0);
//       vector<int>ans;
      
//       while(!st.empty()){
//           Node *temp = st.top();
//           st.pop();
          
//           bool flag = visited.top();
//           visited.pop();
          
//           //flag doesnt exists = 0 
//           if(!flag){ //first time visited
              
//              //right left
//              if(temp->right){
//                  st.push(temp->right);
//                  visited.push(0);
//              }
             
//              //update the stack node
//              st.push(temp);
//              visited.push(1);
             
//               //left size
//               if(temp->left){
//                   st.push(temp->left);
//                   visited.push(0);
//               }
//           }else{ //already visited now just update
//               ans.push_back(temp->data);
//           }
//       }
      
//       return ans;
        
//     }
// };