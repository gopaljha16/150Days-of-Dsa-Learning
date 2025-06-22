// largest value in each level gfg easy question 

// class Solution {
//   public:
//     vector<int> largestValues(Node* root) {
//         // code here
//         vector<int>ans; //take ans vector return
        
//         if(!root)
//          return ans; //if root ==NULl;
         
         
//         queue<Node *>q; 
//         q.push(root); //first push
       
        
//         while(!q.empty()){ //now level vice
//             int levelSize = q.size(); //level wise iteration
//             int levelMax = INT_MIN; //level wise comparing
            
//             for(int i=0 ; i<levelSize ; i++){
//                 Node *temp = q.front(); //first front ele
//                 q.pop(); //popiing
//                 levelMax = max(levelMax , temp->data); //comparing the level max and temp->data
      
                
//                 if(temp->left) //exists  then push
//                  q.push(temp->left); 
                  
//                 if(temp->right) //exisits then push 
//                 q.push(temp->right);
//             }
            
//               ans.push_back(levelMax); //push the element which are max
//         }
        
//         return ans;
//     }
// };