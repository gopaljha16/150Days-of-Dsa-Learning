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
        next = prev = NULL;
    }
};

Node *createDDL(int arr[], int index, int size, Node *back)
{
    // base case
    if (index == size)
        return NULL;

    // create node
    Node *temp = new Node(arr[index]);

    // prev address assining
    temp->prev = back;

    // function call sending back hai temp
    temp->next = createDDL(arr, index + 1, size, temp);
    // returining the temp address to the temp-Next;
    return temp;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    Node *head = NULL;
    head = createDDL(arr, 0, 5, NULL);


    int pos = 5;
    // deletetion at start
    if (pos == 1)
    {
        if (head->next == NULL)
        { // only one node
            delete head;
            head = NULL;
        }
        else
        { // multiple nodes are there
            Node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }
    else
    {
        // go to that postion
        Node *curr = head;
        while (--pos)
            curr = curr->next;
        // deletion at end;
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;
            delete curr;
        }
        else
        { // delete at middle
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
    }

    // printing
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}