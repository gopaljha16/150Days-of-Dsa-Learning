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

Node *CreateLinkedList(int arr[], int index, int size, Node *prev)
{
    // base case
    if (index == size)
    {
        return prev;
    }

    // creating the node
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = prev;
    return CreateLinkedList(arr, index + 1, size, temp);
}

int main()
{

    Node *Head;
    Head = NULL;
    int arr[] = {2, 3, 4, 5, 6};

    Head = CreateLinkedList(arr, 0, 5, Head);

    //  printing
    Node *temp;
    temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        
    }
}