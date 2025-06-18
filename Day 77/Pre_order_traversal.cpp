// /* A binary tree node has data, pointer to left child
//    and a pointer to right child

// /*
// struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node* right;

//     Node(int x){
//         data = x;
//         left = right = NULL;
//     }
// };
// */

//  void pre(Node *root , vector<int>&ans){
//      //base case
//      if(root==NULL)
//       return;
      
//       //Node Left Right
//       ans.push_back(root->data);
//       pre(root->left , ans);
//       pre(root->right , ans);
//  }
// class Solution {
//   public:

//     // Function to return a list containing the preorder traversal of the tree.
//     vector<int> preorder(Node* root) {
//         // write code here
//         vector<int>ans;
//         pre(root , ans);
//         return ans;
//     }
// };