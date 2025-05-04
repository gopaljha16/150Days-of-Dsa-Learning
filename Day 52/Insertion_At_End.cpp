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

// Instertion at end program
int main()
{
    int arr[] = {2, 4, 5, 6, 7};
    Node *Head , *Tail;
    Head = NULL;
    Tail = NULL;
    for (int i=0 ; i<5 ; i++){
        if (Head == NULL)
        {   //if there is not linked list.
            Head = new Node(arr[i]);
            Tail = Head; //tail pointer will be pointing to the head
        }
        else // if linked list is present
        {
            // Node *tail;
            // tail = Head;
            // while (tail->next != NULL)
            // {
            //     tail = tail->next;
            // }
            // // then node creating 
            // Node *temp;
            // temp = new Node(arr[i]);
            // // then node next address giving.
            // tail->next = temp;

            // optimized code now it's pointing to the end we can add the new node and it's address storing to the tail pointer.
            Tail->next = new Node(arr[i]); //before's end node address storing in the tail next;
            Tail = Tail->next; //new tail address which is the end created new node.(means end pointing.)
        }
    }//now basically the code has more time complexity is so we have to add one new thing which that a point will be pointing only the end and we can add one node from end.

    // printing the linked list
    Node *temp;
    temp = Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
       
}
