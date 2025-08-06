// Largest BST gfg medium level question 

/* Tree node structure  used in the program
//Method -1
// struct Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };*/

// class Solution {
//   public:
  
//   class Box{
//       public:
//       bool BST;
//       int size;
//       int min,max;
      
//       //constructor
//       Box(int val){
//           BST=1;
//           size=1;
//           min=val;
//           max=val;
//       }
//   };
  
//   Box *find(Node *root , int &totalSize){
//     //lef node
//     if(!root->left && !root->right){
//         totalSize = max(totalSize , 1);
//         return new Box(root->data);
//     }
//     // only right side exisits
//     else if(!root->left && root->right){
//         Box *head = find(root->right , totalSize); // right side 
        
//         //if it's BST and min is is greater than data
//         if(head->BST && head->min>root->data){
//             head->size++;
//             head->min = root->data;
//             totalSize = max(totalSize , head->size);
//             return head;
//         }else{
//             // bst doesn't exists
//             head->BST = 0;
//             return head;
//         }
//     }
//     // only left side exisits
//     else if(root->left  && !root->right){
//         Box *head = find(root->left , totalSize);
        
//         if(head->BST && head->max<root->data){
//             head->size++;
//             head->max = root->data;
//             totalSize = max(totalSize , head->size);
//             return head;
//         }else{
//             //bst doesn't exists
//             head->BST = 0;
//             return head;
//         }
//     }else{ // both left and right exisits
//     Box *leftHead = find(root->left , totalSize);
//     Box *rightHead = find(root->right , totalSize);
    
//     //bst exisits
//     if(leftHead->BST && rightHead->BST && leftHead->max<root->data && rightHead->min>root->data){
//         Box *head = new Box(root->data);
//         head->size+=leftHead->size+rightHead->size;
//         head->min = leftHead->min;
//         head->max = rightHead->max;
//         totalSize = max(totalSize , head->size);
//         return head;
//     }
//     else{
//          //bst doens't exists
//          leftHead->BST = 0;
//          return leftHead;
//     }
//     }
    
//   }
  
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     int largestBst(Node *root) {
//       int totalSize = 0;
//       find(root, totalSize);
//       return totalSize;
        
//     }
// };

//Method -2
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// class Box{
//     public:
//     bool BST;
//     int size;
//     int min , max;
    
//     Box(){
//       BST=1;
//       size = 0;
//       min = INT_MAX;
//       max = INT_MIN;
//     }
// };

// class Solution {
//   public:
  
//    Box *find(Node *root , int &totalSize){
//        //root doesn't exists
//        if(!root){
//            return new Box();
//        }
       
//        //root exists
       
//        Box *leftHead = find(root->left , totalSize);
//        Box *rightHead = find(root->right , totalSize);
       
//        //bst exisits
//        if(leftHead->BST && rightHead->BST && leftHead->max<root->data && rightHead->min>root->data){
//            Box *head = new Box(); //--Box
//            head->size = 1+leftHead->size+rightHead->size;
//            head->min = min(root->data , leftHead->min);
//            head->max = max(root->data , rightHead->max);
//            totalSize = max(totalSize , head->size);
//            return head;
//        }else{
//            leftHead->BST = 0;
//            return leftHead;
//        }
//    }
  
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     int largestBst(Node *root) {  
        
//         int totalSize = 0;
//         find(root , totalSize);
//         return totalSize;
        
//     }
// };