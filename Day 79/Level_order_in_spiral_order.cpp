// Level order in spiral order gfg easy level question 

// class Solution {
//   public:
//     vector<int> findSpiral(Node* root) {
        
//         stack<Node*>st1; //right to left
//         stack<Node*>st2; // left to right
//         st1.push(root); //first root push to stack1
//         vector<int>ans; //for returning ans;
        
//         while(!st1.empty() || !st2.empty()){ //till both the stack is empty loop should run
            
//             //right to left
//             if(!st1.empty()){ //if stack 1 the element are present
//                 while(!st1.empty()){ //run till stack 1 is empty
//                     Node *temp = st1.top(); //stack top eleement store in the temp
//                     st1.pop(); //pop stack
                    
//                     //then push the stack element to the ans
//                     ans.push_back(temp->data);
                    
//                     //now store the child of right and left to the another stack 2 
//                     //so here first right and then left
//                     if(temp->right){ //temp right exisit the push to stack 2
//                         st2.push(temp->right);
//                     }
//                     if(temp->left){ //temp left exist then push to stack2
//                         st2.push(temp->left);
//                     }
//                 }
//             }else{//left to right
//                 while(!st2.empty()){ //run loop till stack 2 is empty
//                     Node *temp = st2.top();
//                     st2.pop();
                    
//                     ans.push_back(temp->data);
                    
//                     //here left to right so here push the elemen to the stack1
//                     if(temp->left){ //the left exists then push to stack1
//                         st1.push(temp->left);
//                     }
//                     if(temp->right){ //the right exisits then push to stack1
//                         st1.push(temp->right);
//                     }
        
//                 }
//             }
//         }
        
//         return ans;
        
//     }
// };