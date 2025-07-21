#include <iostream>
using namespace std; 

class Node{
    public:
    int data;
    Node *left , *right;

    //contructor
    Node (int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

//insertion fucntion 
Node * insert(Node *root , int target){
    //base case
    if(!root){
        Node *temp = new Node(target);
        return temp;
    }

    //left then right subtree
    if(target <root->data){
        root->left = insert(root->left , target);
    }else{
        root->right = insert(root->right , target);
    }

    return root;
}

//inoreder traversal to print the BST
void inorder(Node *root){
    if(!root) 
    return;

    //left , node , right
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[] = { 6,1,2,9,5,3,4,8,7,7 ,19};
    Node *root = NULL;

    for(int i=0 ; i<10 ; i++){
        root = insert(root , arr[i]);
    }

    //for printing we can use inorder traversal
    cout << "Inorder Traversal of the BST: ";
   inorder(root);
}