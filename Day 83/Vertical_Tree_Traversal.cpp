// Vertical Tree Traversal gfg medium level question 

// class Solution {
//   public:
  
//    void findPos(Node *root , int pos , int&l , int&r){
//        //base case
//        if(!root)
//         return;
        
//        l = min(pos , l);
//        r = max(pos , r);
       
//        //left then right
//        findPos(root->left , pos-1 , l , r);
//        findPos(root->right , pos+1 , l , r);
//    }
   
   
//     vector<vector<int>> verticalOrder(Node *root) {
      
//       //leftmost and right most position 
//       int l  = 0 , r = 0;
//       findPos(root , 0 , l , r); //find the position
      
//       //2d vector for storing negative and positive value
//       vector<vector<int>>positive(r+1);
//       vector<vector<int>>negative(abs(l)+1);
      
//       //level order traversal start
//       //using 2 queues.
//       queue<Node*>q;
//       queue<int>index;
//       q.push(root);
//       index.push(0);
      
//       //traversal 
//       while(!q.empty()){
//           Node *temp = q.front();
//           q.pop();
          
//           int pos = index.front();
//           index.pop();
          
//           //value insert in to the 2d array 
//           if(pos>=0){ //value is positive then push to positive array 
//              positive[pos].push_back(temp->data);
//           }else{ //negative
//               negative[-pos].push_back(temp->data);
//           }
          
//           // push left and right
//           if(temp->left){
//               q.push(temp->left);
//               index.push(pos-1);
//           }
          
//           if(temp->right){
//               q.push(temp->right);
//               index.push(pos+1);
//           }
//       }
      
      
//     vector<vector<int>> ans;
      
//      // from negative
//       for (int i = negative.size() - 1; i >= 0; i--) {
//           if (!negative[i].empty()) {
//             ans.push_back(negative[i]);
//         }
//      }

//          // from positive
//        for (int i = 0; i < positive.size(); i++) {
//           if (!positive[i].empty()) {
//             ans.push_back(positive[i]);
//           }
//        }
      
//       return ans;
//     }
// };