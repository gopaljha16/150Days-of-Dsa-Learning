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
    // Insert at start Doubly Linked List;
    Node *head = NULL;

    //if linked list doesn't exisits
    if(head==NULL){
        head = new Node(5);
    }
    // if linked list exisits
    else{
        Node *temp = new Node(5);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // traversal printing
    Node *trav = head;
    while(trav){
        cout<<trav->data<<" ";
        trav = trav->next;
    }
}