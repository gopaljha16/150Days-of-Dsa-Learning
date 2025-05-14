#include <iostream>
using namespace std;


class Node{
      public:
     int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

Node* createDDL(int arr[] , int index , int size , Node *back){
    //base case
    if(index==size)
     return NULL;

     //create node
     Node *temp = new Node(arr[index]);

     //prev address assining
     temp->prev = back;

     //function call sending back hai temp
     temp->next = createDDL(arr , index+1 , size , temp);
     // returining the temp address to the temp-Next;
     return temp;
}


int main(){


    int arr[] = {1,2,3,4};
    Node *head = NULL;
    head = createDDL(arr , 0 , 4 , NULL);

    // printing
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}