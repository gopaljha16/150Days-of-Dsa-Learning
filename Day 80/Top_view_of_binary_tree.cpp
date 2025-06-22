// Top view of binary tree gfg medium level question 
//method 1 level order traversing 
// class Solution {
//   public:
//     // Function to return a list of nodes visible from the top view
//     // from left to right in Binary Tree.
    
    
//     void findPos(Node *root , int pos , int &l , int &r){
//         //base case
//         if(!root)
//          return;
         
//         l = min(pos , l);
//         r = max(pos , r);
        
//         findPos(root->left , pos-1 , l , r);
//         findPos(root->right , pos+1 , l , r);
//     }
    
//     vector<int> topView(Node *root) {
       
//        int l=0 , r= 0; //initally left and right most is 0
//        findPos(root, 0 , l , r);
       
//        //now vector of ans and vector of filled
//        vector<int>ans(r-l+1);
//        vector<bool>filled(r-l+1, 0); //initaiased with the zero
       
//        //two queue for the iteration 
//        queue<Node*>q;
//        queue<int>index;
//        q.push(root);
//        index.push(-1*l);//for making the postion of index correct left most start with 0 and move on
        
//       //now level order iteration 
//       while(!q.empty()){
//           Node *temp  = q.front();
//           q.pop();
          
//           int pos = index.front();
//           index.pop();
          
//           //check the filled position  or not
//           if(!filled[pos]){
//               filled[pos] = 1;
//               ans[pos] = temp->data;
//           }
          
//           //left and right
//           if(temp->left){
//               q.push(temp->left);
//               index.push(pos-1); //with the pos updating
//           }
//           if(temp->right){
//               q.push(temp->right);
//               index.push(pos+1); 
//           }
//       }
      
//       return ans;
        
//     }
// };

//method 2 using recursion 
// class Solution {
//   public:
//     // Function to return a list of nodes visible from the top view
//     // from left to right in Binary Tree.
    
    
//     void findPos(Node *root , int pos , int &l , int &r){
//         //base case
//         if(!root)
//          return;
         
//         l = min(pos , l);
//         r = max(pos , r);
        
//         findPos(root->left , pos-1 , l , r);
//         findPos(root->right , pos+1 , l , r);
//     }
    
//     void topV(Node *root , int pos  , vector<int>&ans , vector<int>&level , int l){
//         //base case
//         if(!root)
//          return;
         
//         //if the value level is less then insert into the ans
//         if(level[pos]>l){ //level position
//             ans[pos] = root->data; //insert the data
//             level[pos] = l; // l is nothing but current level
//         }
        
//         //now left and right
//         topV(root->left , pos-1 , ans , level , l+1);
//         topV(root->right , pos+1 , ans , level , l+1);
//     }
    
//     vector<int> topView(Node *root) {
       
//        int l=0 , r= 0; //initally left and right most is 0
//        findPos(root, 0 , l , r);
       
//        //now vector of ans and vector of filled
//        vector<int>ans(r-l+1);
//        vector<int>level(r-l+1, INT_MAX);
//        topV(root , -1*l , ans , level , 0);
      
//       return ans;
        
//     }
// };