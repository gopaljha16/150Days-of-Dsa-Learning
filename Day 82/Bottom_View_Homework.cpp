//Bottom View of binary tree gfg medium level question 
//method-1
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

// class Solution {
//   public:
  
//      void findPos(Node *root , int pos , int&left , int &right){
//          //base case
//          if(!root)
//           return;
          
//           left = min(pos , left);
//           right = max(pos , right);
          
//           findPos(root->left , pos-1 , left , right);
//           findPos(root->right , pos+1 , left , right);
//      }
  
//     vector<int> bottomView(Node *root) {
        
//         int leftMost = 0 , rightMost = 0;
//        findPos(root , 0 , leftMost , rightMost); //find the level position
//        //edge case
       
//       int size = rightMost - leftMost +1;
//        vector<int>ans(size);
       
//        if(!root)
//         return ans;
        
//       queue<Node*>q;
//       queue<int>index;
//       q.push(root);
//       index.push(-leftMost);
      
//       while(!q.empty()){ //till queue empty
//           Node *temp = q.front();
//           q.pop();
          
//           int pos = index.front();
//           index.pop();
          
//           ans[pos] = temp->data;
          
//           if(temp->left){
//               q.push(temp->left);
//               index.push(pos-1); //pos updating
//           }
          
//           if(temp->right){
//               q.push(temp->right);
//               index.push(pos+1);
//           }
//       }
    
//     return ans;
       
        
//     }
// };

//Method 2 using recursion 

// class Solution {
//   public:
  
//      void findPos(Node *root , int pos , int&left , int &right){
//          //base case
//          if(!root)
//           return;
          
//           left = min(pos , left);
//           right = max(pos , right);
          
//           findPos(root->left , pos-1 , left , right);
//           findPos(root->right , pos+1 , left , right);
//      }
     
//      void bottomV(Node *root , int pos , vector<int>&ans , vector<int>&level , int l){
//          if(!root)
//           return;
         
//          //if the value level is less then insert into the ans
//         if(level[pos]<=l){ //level position
//             ans[pos] = root->data; //insert the data
//             level[pos] = l; // l is nothing but current level
//         } 
         
//         bottomV(root->left , pos-1 , ans , level , l+1);
//         bottomV(root->right , pos+1 , ans , level , l+1);
//      }
  
//     vector<int> bottomView(Node *root) {
        
//         int leftMost = 0 , rightMost = 0;
//        findPos(root , 0 , leftMost , rightMost); //find the level position
//        //edge case
       
//       int size = rightMost - leftMost +1;
//        vector<int>ans(size);
       
//        if(!root)
//         return ans;
        
//     vector<int>level(size , INT_MIN);
//     bottomV(root , -1*leftMost , ans , level , 0);
      
    
//     return ans;
       
        
//     }
// };