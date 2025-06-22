// // Check if two Nodes are Cousins gfg medium level question 

// class Solution {
//   public:
  
  
//    //parent check function 
//    bool checkParent(Node *root , int x , int y){
    
//        //base case
//        if(!root) //if root is null then three is not parent
//         return 0;
        
//     //check left and right exisit
//    if ((root->left && root->right) &&
//         ((root->left->data == x && root->right->data == y) ||
//          (root->left->data == y && root->right->data == x))) {
//         return 1;
//     }
//         //check the parent both side the its have or 0||1 left and right
//         return checkParent(root->left , x ,y) || checkParent(root->right , x ,y);
//    }
  
//     // Function to check if two nodes are cousins in a tree
//     bool isCousins(Node* root, int x, int y) {
        
           
//       if (!root || x == y)
//             return false;
        
//         queue<Node*>q;
//         q.push(root);
//         int l1 = -1 , l2 = -1; //for level of both x and y
//         int level  = 0; // for the level which level is the x and y is
//         //Find the level for the x and y and insert into means here leveling
//         while(!q.empty()){ //till the queue is empty
//              //the n size
//              int n = q.size();
             
//              while(n--){ //till n exisits
//              Node *temp = q.front();
//              q.pop();
             
//              //here comparing the temp data is equal to x and y
//              if(temp->data==x){
//                  l1 = level; //asign them their level
//              }
//              if(temp->data==y){
//                  l2 = level;
//              }
             
//              //normal left and right pushing to the queue
//              if(temp->left){
//                  q.push(temp->left);
//              }
             
//              if(temp->right){
//                  q.push(temp->right);
//              }
             
//              }
             
//               if (l1 != -1 && l2 != -1)
//                 break;
                
                
//              level++; //increase the level after n doesn't exists it become zero means we are in the next level
                
       
//         }
        
                
//         //Extra check to ensure both nodes exist
//         if (l1 == -1 || l2 == -1)
//             return 0;

        
//         //now parent checking if x and y and are in same level or not
//         return (l1==l2) && !checkParent(root , x , y);
         
//     }
// };