// // BST to max heap gfg medium level question 

// // User function Template for C++

// /*struct Node {
//     int data;
//     Node *left, *right;
// };*/

// class Solution {
//   public:
   
//    void inOrder(Node *root , vector<int>&ans){
//        if(!root)
//         return;
        
//        inOrder(root->left , ans);
//        ans.push_back(root->data);
//        inOrder(root->right , ans);
//    }
   
//    void postOrder(Node *root , vector<int>&ans , int &index){
//        if(!root)
//         return;
        
//         postOrder(root->left , ans , index);
//         postOrder(root->right , ans , index);
//         root->data = ans[index++];
//    }
  
//     void convertToMaxHeapUtil(Node* root) {
//         vector<int>ans;
//         //inorder
//         inOrder(root , ans);
//         //postorder
//         int index = 0;
//         postOrder(root , ans, index);
//     }
// };
