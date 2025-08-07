#include <iostream>
using namespace std;

class Node {
    public:
    int data , height;
    Node *left , *right; 


    Node(int val){
      data=val;
      height=1;
      left=right=NULL;
    }
};

int getHeight(Node *root){
    //null
    if(!root)
     return 0;
    
    //exists
    return root->height;
}


int getBalance(Node *root){
    return getHeight(root->left)-getHeight(root->right);
}

Node *rightRotation(Node *root){
  Node *child = root->left;
  Node *childRight = child->right;

  //update
  child->right = root;
  root->left = childRight;

  //update height
  root->height = 1+max(getHeight(root->left),getHeight(root->right));
  child->height = 1+max(getHeight(child->left) , getHeight(child->right));

  return child;
}

Node *leftRotation(Node *root){
    Node *child = root->right;
    Node *childLeft = child->left;

    //update
    child->left = root;
    root->right = childLeft;

    //update height
      root->height = 1+max(getHeight(root->left),getHeight(root->right));
      child->height = 1+max(getHeight(child->left) , getHeight(child->right));

  return child;

}

Node * insert(Node *root , int key){
    //null root doesn't exists
    if(!root)
     return new Node(key);

     //exists then comparision
     //left side
     if(key<root->data){
        root->left = insert(root->left , key);
     }
     else if(key>root->data){
        root->right = insert(root->right , key);
     }else{
        //no duplicate
        return root;
     }


     //update height
     root->height = 1+max(getHeight(root->left),getHeight(root->right));

     //balancing 
     int balance = getBalance(root);

    //unbalanced
    //left left case
    if(balance>1 && key<root->left->data){
        return rightRotation(root);
    }
    //right right case
    else if(balance<-1 && root->right->data<key){
        return leftRotation(root);
    }
    //left right
    else if(balance>1 && key>root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right left case 
    else if(balance<-1 && root->right->data>key){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }else{
        //no rotation 
        return root;
    }
}

void preorder(Node *root){
    if(!root)
     return;

     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}

void inorder(Node *root){
    if(!root)
     return;

     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}

int main(){
  
    Node *root = NULL;

    //no duplicate val
   root = insert(root, 10);
   root =  insert(root, 20);
   root =  insert(root, 9);
   root =  insert(root, 6);
   root =  insert(root, 12);
   root =  insert(root, 25);
   root =  insert(root, 90);
   root =  insert(root, 3);

    cout<<"Pre order: "<<endl;
     preorder(root);

      cout<<"in order: "<<endl;
    inorder(root);

}