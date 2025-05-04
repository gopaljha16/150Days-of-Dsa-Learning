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

Node *CreateLinkedList(int arr[], int index, int size)
{
    // base case
    if (index == size)
        return NULL;

    // create node
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);

    return temp;
}

// delete first node.
int main()
{
    Node *Head;
    Head = NULL;

    int arr[] = {2, 3, 4, 5, 6};
    Head = CreateLinkedList(arr, 0, 5);

    // Delete an Paticular Node.
    int x = 3;
    if (x == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }
    else
    {
        x--;
        Node *curr = Head;
        Node *prev = NULL;
        while (x--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }


//   printing
Node *temp;
temp = Head;
while (temp != NULL)
{
    cout << temp->data << " ";
    temp = temp->next;
}
}