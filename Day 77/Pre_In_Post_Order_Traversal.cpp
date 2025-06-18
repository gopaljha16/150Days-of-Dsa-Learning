#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    //constructor
    Node(int value){
        data = value;
        left = right = NULL;
    }
};

 Node* BinaryTree(){
    int x;
    cin>>x;

    //check the x is 1 or -1
    if(x==-1)
    return NULL;

    //not -1 then create node
    Node *temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" : ";
    temp->left = BinaryTree(); //first left create tree
    cout<<"Enter the Right child of "<<x<<" : ";
    temp->right = BinaryTree();  //then right create tree
    return temp; //address return
 }

 void preOrder(Node* root){
    //base case
    if(root==NULL){
        return;
    }

    //Node Left Right
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
 }

 void inOrder(Node *root){
    //base case
    if(root==NULL){
        return;
    }

    //Left Node Right
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
 }

 void postOrder(Node *root){
    //base case
    if(root==NULL){
        return;
    }

    //Left Rigth Node
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
 }


int main(){
   cout<<"Enter the root Node : ";
   Node *root;
   //Tree Created.
   root = BinaryTree();

   //preOrder
   cout<<"\n PreOrder : ";
   preOrder(root);

   //inOrder
   cout<<"\n InOrder : ";
   inOrder(root);

   //post Order
   cout<<"\n PostOrder : ";
   postOrder(root);

}