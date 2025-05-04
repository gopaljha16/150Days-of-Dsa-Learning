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

    //    printing the linked list.
    Node *temp;
    temp = Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}