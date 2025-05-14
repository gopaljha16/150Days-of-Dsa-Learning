#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{

    Node *head = NULL; // an pointier which has value null
    Node *tail = NULL;
    int arr[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        // if linked list doesn't exisit
        if (head == NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        else
        { // linked list exisits
            Node *temp = new Node(arr[i]);
            tail->prev = temp;
            temp->next = tail;
            tail = temp;
            head = temp;
        }
    }

    // printing 
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}