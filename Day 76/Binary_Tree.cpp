#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
  int data;
  Node *left;
  Node *right;

  //construtor
  Node(int value){
      data = value;
      left = right = NULL;
  }
};

int main(){
   queue<Node*>q; //it is storing the address
   int x , first , second;
   cout<<"Enter the root Element: ";
   cin>>x;
   Node *root = new Node(x); //create the root node
   q.push(root); //push it's address

   //build the binary tree
   while(!q.empty()){ //until the queue is empty..
      //first access the root node then we have to insert the left child and right child
      Node *temp = q.front();
      q.pop(); //pop the front

      cout<<"Enter the left child of  "<<temp->data <<" : ";
      cin>>first;
      if(first!=-1){ //left child
        temp->left = new Node(first);
        q.push(temp->left);
      }

      cout<<"Enter the Right child of "<<temp->data<<" : ";
      cin>>second;
      if(second!=-1){
        temp->right = new Node(second);
        q.push(temp->right);
      }
   }
}