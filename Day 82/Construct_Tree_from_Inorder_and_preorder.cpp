// Construct Tree from Inorder & Preorder gfg medium level question 

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
  
//    Node* Tree(vector<int>& in, vector<int>& pre, int inStart, int inEnd, int& index){
//        //base case
//        if(inStart>inEnd){
//            return NULL;
//        }
       
//        //create the node
//        Node *root = new Node(pre[index]);
//        index++;
//        int pos = findPos(in , root->data , inStart , inEnd);//find the position in inorder
       
//        //left 
//        root->left = Tree(in , pre , inStart , pos-1 , index);
//        //right
//        root->right = Tree(in , pre , pos+1 , inEnd  , index);
       
//        return root;
//    }
  
//     // Function to build the tree from given inorder and preorder traversals
//     Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
//         int index=0;
//         int n = inorder.size();
//        return Tree(inorder , preorder , 0 , n-1 , index);
        
        
//     }
// };