#include <iostream>
using namespace std;


class Node{
      public:
     int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

int main(){
     Node *head = NULL;
  
    //  if there is no linked list
     if(head==NULL){
        head = new Node(5);
     }else{  // insert at end;
        Node *curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }

        Node *temp = new Node(5);
        curr->next = temp ;
        temp->prev = curr;
     }

     //printing
     Node *temp = head;
     while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
     }
}