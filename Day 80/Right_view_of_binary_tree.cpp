// Right view of binary tree gfg easy level question 

// class Solution {
//   public:
//     // Function to return list containing elements of right view of binary tree.
//     vector<int> rightView(Node *root) {
//         vector<int>ans;
//         if(!root)
//         return ans;
        
//         queue<Node*>q;
//         q.push(root);
        
        
//         while(!q.empty()){
//             ans.push_back(q.front()->data);
//             int n = q.size();
            
//             while(n--){
//                 Node *temp = q.front();
//                 q.pop();
                
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
                
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//             }
//         }
//          return ans;
        
//     }
// };

// recursive code

// class Solution {
//   public:
  
//    void right(Node *root , int level , vector<int>&ans){
//        if(!root)
//         return;
        
//         if(level==ans.size()){
//             ans.push_back(root->data);
//         }
        
//         right(root->right , level+1 , ans);
//         right(root->left , level+1 , ans);
//    }
  
//     // Function to return list containing elements of right view of binary tree.
//     vector<int> rightView(Node *root) {
//         vector<int>ans;
//         if(!root)
//         return ans;
        
//        right(root , 0 , ans);
//          return ans;
        
//     }
// };