// Construct BST from the post order traversal gfg easy level question 

/*struct Node
{
    int data;
    Node *left, *right;
};*/
// Methdo range o(n) time and space complexity.
// Node * BST(int post[] , int &index , int lower , int upper){
//     //base case
//     if(index<0 || post[index]<lower || post[index]>upper){
//         return NULL;
//     }
    
//     //rever order so NRl
//     Node *root = new Node(post[index--]);
//     //right
//     root->right = BST(post , index , root->data , upper);
//     //right
//     root->left = BST(post , index , lower , root->data);
    
//     return root;
// }

// Node *constructTree(int post[], int size) {
//     // code here
//     int index = size-1;
//     return BST(post , index , INT_MIN , INT_MAX);
// }