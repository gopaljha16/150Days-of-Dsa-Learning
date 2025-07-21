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

bool search(Node *root , int target){
    //base case
    if(!root)
     return 0;
    
     //if element found
     if(root->data==target)
      return 1;

    //if not found but could be present in left or right
    if(root->data > target){ //left side
        return search(root->left , target);
    }else{
        return search(root->right , target); //right side
    }
}


int main(){
    int arr[] = { 6,1,2,9,5,3,4,8,7 ,19};
    Node *root = NULL;

    for(int i=0 ; i<10 ; i++){
        root = insert(root , arr[i]);
    }

   // searching using the function 
  cout<<search(root , 99)<<endl;


}