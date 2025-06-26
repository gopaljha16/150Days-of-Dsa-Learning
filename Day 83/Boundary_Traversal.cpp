// Tree Boundary Traversal gfg medium level question

// class Solution {
//   public:
  
//    void leftSub(Node *root , vector<int>&ans){
//        //base case
//        if(!root || (!root->left && !root->right))
//         return;  //here root is null and left and right is null return
       
//        //insert element
//        ans.push_back(root->data);
//        //if left exisit then go left or else right
//        if(root->left)
//         leftSub(root->left , ans);
//        else
//         leftSub(root->right , ans);
//    }
  
//   void leaf(Node *root , vector<int>&ans){
//       //base case
//       if(!root)
//        return;
       
//        //if root left and right is null then push element
//        if(!root->left && !root->right ){
//            ans.push_back(root->data);
//            return;
//        }
       
//        //move to left and right
//        leaf(root->left , ans);
//        leaf(root->right, ans);
       
//   }
  
//   void rightSub(Node *root , vector<int>&ans){
//       //base case
//       if(!root || (!root->left && !root->right))
//         return;
        
//       //here root right exist then move to right or else left side 
//       if(root->right)
//        rightSub(root->right , ans);
//       else //right side doesn't exisits then go to left side
//        rightSub(root->left , ans);
       
//        //now insert the element it will be returning as left side
//        ans.push_back(root->data);
//   }
  
//     vector<int> boundaryTraversal(Node *root) {
//        vector<int>ans;
//        //root node element push 
//        ans.push_back(root->data);
//        //left boundary element insert except leaf node
//        leftSub(root->left , ans);
//        //leaf node insert
//        if(root->left || root->right) //edge case if root left and right exisits then call leaf node
//        leaf(root , ans);
//        //right boundary element insert except leaf node in reverse order
//        rightSub(root->right , ans);
       
//        return ans;
        
//     }
// };