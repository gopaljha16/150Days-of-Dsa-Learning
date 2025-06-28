// Burning Tree Gfg hard level question 


// class Solution {
//   public:
  
//    int Height(Node*root){
//        ///base case
//        if(!root)
//         return 0;
        
//         //calculate the height
//        return 1+max(Height(root->left) , Height(root->right));
//    }
   
//    int Burn(Node *root , int &timer, int target){
       
//         //doesn't exisits
//         //base case
//         if(!root)
//         return 0;
        
//         //exists //burining 
//         if(root->data==target){
//         int lh = Height(root->left);
//         int rh = Height(root->right);
//          timer = max(timer, max(lh, rh));  // include downward fire
//       return -1;

//         }
       
        
//         //left and right;
//        int left = Burn(root->left , timer , target);
//         int right = Burn(root->right , timer , target);
        
//         //burining condtion 
//         if(left<0){
//             timer = max(timer , abs(left)+right);
//             return left-1;
//         }
        
//         if(right<0){
//             timer = max(timer , left+abs(right));
//             return right-1;
//         }
        
//         //normal both gives hight return
//         return 1+max(left , right);
//    }

   
  
  
//     int minTime(Node* root, int target) {
        
//        int timer = 0;
//        Burn(root , timer , target);
    
//        return timer ;
//     }
// };