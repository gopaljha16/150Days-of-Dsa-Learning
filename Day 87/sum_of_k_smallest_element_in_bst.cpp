//  Sum of k smallest elements in BST gfg easy level question 


//   void ksum(Node *root , int &sum , int &k){
//       //base case
//       if(!root)
//        return;
       
//        //left 
//        ksum(root->left , sum , k);
//        //decrease k
//        k--;
//        if(k>=0)
//        sum+=root->data;
       
//        if(k<=0)
//        return;
       
//        //right
//        ksum(root->right , sum  , k);
//   }

// int sum(Node* root, int k) {

//      int sum = 0;
//      ksum(root , sum , k);
//      return sum;
    
// }