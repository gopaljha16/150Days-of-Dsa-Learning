#include <iostream>
using namespace std;


class  Node{
    public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

int main(){
//   static linked list
// Node A1(4); // creates and node with the data and next node.
// cout<<A1.data<<endl;
// cout<<A1.next<<endl;

// dynamic way linked list creating
Node *Head;
Head = new Node(10);
cout<<Head->data<<endl;
cout<<Head->next<<endl;

}