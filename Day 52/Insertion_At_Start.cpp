#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    // Array to Linked List
    int arr[] = {2, 4, 6, 8,10};
    //  Inserting the Node in the begining/Starting.
    Node *Head;
    Head = NULL;
    for (int i = 0; i < 5; i++)
    {
        // condtion if linked list doesn't exists
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
        }
        else
        { // if linked list exisits then.
            Node *temp;
            temp = new Node(arr[i]); // new node creating.
            temp->next = Head;   // temp next giving head previous node address.
            Head = temp;         // starting of node so pointing head to temp;
        }
    }

    // Traversing the Linked list and printing 
    Node *temp = Head; // node temp pointing to the starting of linked list
    while(temp!=NULL){  //break condition is that if temp gets null then stop the loop
        cout<<temp->data<<" ";  //printing the data
        temp = temp->next;   //then storing the temp next to next value
    }

}