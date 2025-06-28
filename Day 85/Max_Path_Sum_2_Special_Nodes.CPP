// Max Path Sum 2 Special Nodes GFG HARD question

// class Solution {
//   public:
  
//    int pathSum(Node *root , int &sum){
//        //if root left and right doesnt exisits
//        if(!root)
//         return 0;
        
//      //leaf node 
//      if(!root->left && !root->right){
//          return root->data;
//      }
     
//      ////left and right sum
//      int left = pathSum(root->left , sum);
//      int right = pathSum(root->right , sum);
     
//      //left and right both exisits then calculate the sum and return also which is maximum
//      if(root->left && root->right){
//          sum = max(sum , root->data+left+right);
//          return root->data+max(left , right);
//      }
     
//      //only left exisits
//      if(root->left){
//          return root->data+left;
//      }
     
//      //only right exists
//      if(root->right){
//          return root->data+right;
//      }
     
//    }
//     int maxPathSum(Node* root) {
    
//       int sum = INT_MIN;
//     int val= pathSum(root , sum); //finds the path sum
//     //before storing that node for the if the root node become the sepcial node so
//     //edge case
//     //if root left and right exisits then it will not be the sepcial node
//     if(root->left && root->right){
//         return sum;
//     }
    
//     return max(sum , val);//return if the root is special node
        
//     }
// };