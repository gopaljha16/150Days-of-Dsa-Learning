#include <iostream>
using namespace std;

class Node{
   public:
   int data;
   Node *next;
   
   Node(int value){
     data=  value;
     next = NULL;
   }
};


Node* CreateLinkedList(int arr[] , int index , int size ){
    // base case
    if(index==size)
    return NULL;

    // create node
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr ,index+1 , size);
    
    return temp;
}



// delete first node.
int main(){
  Node *Head;
  Head = NULL;

  int arr[] = {2,3,4,5,6};
  Head = CreateLinkedList(arr , 0 , 5);

// Delete an Node at end
  if(Head!=NULL){
    if(Head->next==NULL){
        Node *temp = Head;
        Head = NULL;
        delete temp;
    }else{
        Node *prev = NULL;
        Node *curr = Head;
        while(curr->next!=NULL){ // run until curr is not null 
            prev = curr;
            curr = curr->next;
        }
        // if null curr delete
        delete curr;
        prev->next = NULL; // then prev make it null
    }
  }

//   printing
  Node  *temp;
  temp  = Head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}