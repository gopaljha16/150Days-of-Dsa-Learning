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

Node *CreateDLL(int arr[], int index, int size, Node *back)
{
    // base case
    if (index == size)
        return NULL;

    //  Create node
    Node *temp = new Node(arr[index]);
    temp->prev = back;

    temp->next = CreateDLL(arr, index + 1, size, temp);
    return temp;
}

int main()
{

    Node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5};

    head = CreateDLL(arr, 0, 5, NULL);

    // insert the element in middle with edge cases solved
    int pos = 0; // position to insert the element

    // insert at start
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = new Node(5);
        }else
        { // linked list exisits
            Node *temp = new Node(5);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {
        Node *curr = head;
        //go to the Nodes after which i have to insert
        while(--pos){
            curr = curr->next;
        }
        // insert at end
        if(curr->next==NULL){
            Node *temp = new Node(5);
            temp->prev = curr;
            curr->next = temp;
        }else{ //insert at middle
               Node *temp = new Node(5);
               temp->next = curr->next;
               temp->prev = curr;
               curr->next = temp;
               temp->next->prev = temp;
        }
    }

    // printing
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}
