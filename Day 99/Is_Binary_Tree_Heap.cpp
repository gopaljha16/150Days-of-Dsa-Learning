//  Is Binary Tree Heap gfg medium level question

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// class Solution {
//   public:
  
  
//    int count(Node *root){
//        if(!root)
//         return 0;
        
//         return 1+count(root->left)+count(root->right);
//    }
   
//    bool CBT(Node *root , int index , int nodes){
//        //base case
//        if(!root){ //leaf nodes
//            return 1;
//        }
       
//        if(index>=nodes) // the condition is if the index is greater then nodes then return 0 it's not an cbt
//         return 0;
        
//        //left and right side checking cbt
//        return CBT(root->left , 2*index+1,nodes) && CBT(root->right , 2*index+2,nodes);
       
//    }
   
   
//    bool MaxHeap(Node *root){
//        //left checking because here node exisits
//        if(root->left){ //if nodes exisits
//         if(root->data <root->left->data) //root parent data is less than root left data then it's not maxHeap
//            return 0;
           
//          //move to left side
//          if(!MaxHeap(root->left)) //if in left side there the no maxheap then it will be returing 0;
//           return 0;
//        }
       
//        //right side
//        if(root->right){
//            if(root->data < root->right->data) //checking the data is less than the right then return 0 becuase it's not an maxHeap
//             return 0;
            
//             return MaxHeap(root->right); //here the right side there will be no left and right so direct reutrning 
//        }
       
//        return 1; //if there is no left and right
//    }
   
    
  
//     bool isHeap(Node* tree) {
//        //count Node 
//        int num = count(tree);
       
//        //checking the tree is cbt or not
//        bool ans = CBT(tree , 0 , num); //passing tree , index , num of nodes
       
//        if(ans==0)
//         return 0;
        
//     // max heap checking parent=>child
//     return  MaxHeap(tree);
//     }
// };