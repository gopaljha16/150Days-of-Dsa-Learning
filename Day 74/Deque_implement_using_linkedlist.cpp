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

class Dequeue
{

    Node *front, *rear;

public:
    Dequeue()
    {
        front = rear = NULL;
    }

    // push front
    void push_front(int x)
    {
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << x << " Pushed into the front dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = new Node(x);
            cout << x << " Pushed into the front dequeue" << endl;
            temp->next = front;
            front->prev = temp;
            front = temp;
            return;
        }
    }

    // push_back
    void push_back(int x)
    {
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << x << " Pushed into the back dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = new Node(x);
            cout << x << " Pushed into the back dequeue" << endl;
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            return;
        }
    }

    //pop_front
    void pop_front(){
        if(front==NULL){
            cout<<"Deque Underflow"<<endl;
            return;
        }else{
            Node *temp = front;
            front = front->next;
            cout<<temp->data<<" Popped from front"<<endl;
            delete temp;
            //edge case only one single element exisits
            if(front){
                front->prev = NULL;
            }else{
                rear = NULL;
            }
        }
    }

    void pop_back(){
        if(front==NULL){
            cout<<"Deque Underflow"<<endl;
            return;
        }else{
            Node *temp = rear;
            cout<<temp->data<<" Popped from back"<<endl;
            rear = rear->prev;
            delete temp;
            if(rear){
                rear->next = NULL;
            }else{
                front  = NULL;
            }
        }
    }

    //start
    int start(){
        if(front==NULL){
            return -1;
        }else{
            return front->data;
        }
    }
    //end
    int end (){
        if(front==NULL){
            return -1;
        }else{
            return rear->data;
        }
    }
};

int main()
{
    Dequeue d;
    d.push_front(10);
    d.push_front(20);
    d.push_back(30);
    d.push_back(40);
    d.pop_front();
    d.pop_back();
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;
}