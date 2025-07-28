// Kth largest element in BST gfg easy level question
// class Solution {
//   public:
  
//    void kLargest(Node *root , int &ans , int &k){
       
//        //base case
//        if(!root)
//         return;
        
//     //right 
//     kLargest(root->right , ans , k);
//     //decrease the k
//     k--;
//     //value
//     if(k==0)
//      ans = root->data;
    
//     //return 
//     if(k<=0)
//     return ;
    
//     //left
//     kLargest(root->left , ans , k);
//    }
    
//     int kthLargest(Node *root, int k) {
//         int ans;
//         kLargest(root, ans , k);
//         return ans;
        
//     }
// };