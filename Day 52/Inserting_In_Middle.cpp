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

// Recursive Function for creating linked list and adding node via end
Node *CreateLinkedList(int arr[], int index, int size)
{
    // base case
    if (index == size)
    {
        return NULL;
    }

    // node creating;
    Node *temp;
    temp = new Node(arr[index]);                         // creating the node.
    temp->next = CreateLinkedList(arr, index + 1, size); // this will return the next node address to temp-next

    return temp; // it returns
}

int main()
{
    Node *Head;
    Head = NULL;

    int arr[] = {2, 3, 4, 5, 6};

    //    sotring the first node it returns via recursive function to the head
    Head = CreateLinkedList(arr, 0, 5); /// the 2 address will be stored in the head

    // inserting an node middle code
    int x = 3; // position to insert
    int value = 10;
    Node *temp = Head; // pointing to the head temp.
    x--; // x-- doing
    
    while(x--){ // decreasing the x until reaches the postion
        temp = temp->next;
    }

    // insert
    Node *temp2 = new Node(value);  // creating the node and insering the value
    temp2->next = temp->next;  // next pointing first to the temp->next
    temp->next = temp2; //then pointing to the temp2;


    //    printing the linked list.
    temp = Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}