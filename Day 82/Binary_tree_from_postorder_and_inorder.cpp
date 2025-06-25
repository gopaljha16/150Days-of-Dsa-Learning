// Binary Tree from Inorder and Postorder gfg medium level question 


// class Solution {
//   public:
  
  
//     int findPos(vector<int>&in , int target , int start  , int end){
        
//         //iterating in loop and finding the target
//         for(int i=start ; i<=end ; i++){
//             if(in[i]==target){
//                 return i; //returning index.
//             }
//         }
        
//         return -1;
//     }
  
//    Node* Tree(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& index){
//        //base case
//        if(inStart>inEnd){
//            return NULL;
//        }
       
//        //create the node
//        Node *root = new Node(post[index]);
//        index--;
//        int pos = findPos(in , root->data , inStart , inEnd);//find the position in inorder
       
        
//        root->right = Tree(in , post , pos+1 , inEnd  ,index);
//        root->left = Tree(in , post , inStart , pos-1 , index);
     
       
//        return root;
//    }

//     // Function to return a tree created from postorder and inoreder traversals.
//     Node* buildTree(vector<int> inorder, vector<int> postorder) {
//       int n = postorder.size();
//       int index = n-1;
//       return Tree(inorder , postorder , 0 ,n-1 , index );
        
//     }
// };