// Gfg easy level question level order traversal


// class Solution {
//   public:
//     vector<vector<int>> levelOrder(Node *root) {
       
//        vector<vector<int>>ans;
//        queue<Node *>q;
//        q.push(root);
//        Node *temp;
       
//        while(!q.empty()){
          
//           int levelSize = q.size();
//           vector<int>level;
          
          
//           for(int i=0 ; i<levelSize ; i++){
              
//            temp = q.front();
//            q.pop();
           
//            level.push_back(temp->data);
           
//            if(temp->left)
//             q.push(temp->left);
            
//            if(temp->right)
//             q.push(temp->right);
//           }
          
//           ans.push_back(level);
           
//        }
        
//         return ans;
//     }
// };