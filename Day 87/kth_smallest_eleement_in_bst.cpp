/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Interview Bit Solution medium level question
 
 
//    void  smallest(TreeNode *root , int &ans , int &k){
//      //base case 
//      if(!root)
//       return;
      
//       smallest(root->left , ans , k);
//       k--;
//       if(k==0)
//       ans = root->val;
      
//       if(k<=0)
//        return ;
     
//      smallest(root->right , ans , k);
//  }
 
// int Solution::kthsmallest(TreeNode* A, int B) {
//      int ans;
//      smallest(A , ans , B );
//      return ans;
// }
