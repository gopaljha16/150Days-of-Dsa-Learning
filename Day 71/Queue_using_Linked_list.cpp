#include <iostream>
using namespace std;
// Node
class Node{
  public:
  int data;
  Node *next;

  //constructor 
  Node(int value){
    data = value;
    next = NULL;
  }
};

// Queue
class Queue{
  Node *front , *rear;

  //construtor
  public:
  Queue(){
    front = rear = NULL;
  }

  //is empty
  bool isEmpty(){
    return front==NULL;
  }

  //PUSH
  void push (int x){
    if(isEmpty()){
        cout<<"Pushed Value "<<x<<" in queue"<<endl;
        front = new Node(x);
        rear = front;
        return;
    }else{
         cout<<"Pushed Value "<<x<<" in queue"<<endl;
        rear->next = new Node(x);
        if(rear->next==NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        rear = rear->next;
    }
  }

  //pop
  void pop(){
    if(isEmpty()){
      cout<<"Queue underflow"<<endl;
      return;
    }else{
         cout<<"Popped Value "<<front->data<<" from  queue"<<endl;
        Node *temp = front;
        front = front->next;
        delete temp;
    }
  }

  //start
  int start(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else{
        return front->data;
    }
  }

};


int main(){
   Queue q;
   q.push(10);
   q.push(20);

   q.pop();
   q.pop();
   q.pop();
  int x = q.start();
  if(!q.isEmpty())
  cout<<x<<endl;;

}


//gfg queue linked list

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

// // Function to push an element into the queue.
// void MyQueue::push(int x) {
//     if(front==NULL){
//         front = new QueueNode(x);
//         rear = front;
        
//     }else{
//         rear->next = new QueueNode(x);
//         rear = rear->next;
//     }
// }

// // Function to pop front element from the queue.
// int MyQueue ::pop() {
//  if(front==NULL){
//      return -1;
//  }else{
//      int val = front->data;
//      QueueNode *temp = front;
//      front = front->next;
//      delete temp;
//      return val;
     
//  }
// }