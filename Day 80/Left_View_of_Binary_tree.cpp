// Left View of Binary Tree

// Method 1 USING The the queue
// class Solution {
//   public:
//     vector<int> leftView(Node *root) {
//        queue<Node *>q; //queue for level order traversel
//        vector<int>ans; //left element storing
       
//        if(!root)
//         return ans;
       
//        q.push(root);
  
       
//        while(!q.empty()){ //level order traversing
//          ans.push_back(q.front()->data);
//           int n = q.size();
        
//           while(n--){
//               Node *temp = q.front();
//               q.pop();
              
//               if(temp->left){
//                   q.push(temp->left);
//               }
              
//               if(temp->right){
//                   q.push(temp->right);
//               }
              
//           }
//        }
//         return ans;
//     }
// };


//Method 2 Using without queue using recrusion
// class Solution {
//   public:
  
//    void left(Node *root , int level , vector<int>&ans){
        
//         if(!root)
//          return;
         
//          //if level == ans size then insert
//          if(level == ans.size()){
//              ans.push_back(root->data);
//          }
         
//          left(root->left , level+1 , ans);
//          left(root->right , level+1 , ans);
//    }
    
//     vector<int> leftView(Node *root) {
//       vector<int>ans;
//       if(!root)
//       return ans;
      
//       left(root , 0 , ans);
      
//       return ans;
//     }
// };
