// Sum of Binary Tree basic gfg question 
// class Solution {
//   public:
   
//    void totalSum(Node *root , int &sum){
//        //base case
//        if(root==NULL)
//        return;
       
//        sum+=root->data;
//        totalSum(root->left , sum);
//        totalSum(root->right , sum);
//    }
  
//     int sumBT(Node* root) {
//         int sum=0;
//         totalSum(root , sum);
//         return sum;
        
//     }
// };

// method 2 

// class Solution {
//   public:
   
//    int totalSum(Node *root){
//        //base case
//        if(root==NULL)
//        return 0;
   
//        return (root->data+totalSum(root->left)+totalSum(root->right));
//    }
  
//     int sumBT(Node* root) {
       
//        int  total =  totalSum(root );
//         return total;
        
//     }
// };