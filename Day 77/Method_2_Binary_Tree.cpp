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


int main(){
   cout<<"Enter the root Node : ";
   Node *root;
   root = BinaryTree();
}