#include <iostream>
using namespace std;

class Node {
   public:
   int data;
   Node *next;

   Node(int value){
    data = value;
    next = NULL;
   }
};

class Stack{
   Node *top;
   int size; //actual size of stack

   public:
   Stack(){
    top = NULL;
    size = 0;
   }

   //pushing element
   void push(int value){
     Node *temp = new Node(value);
     if(temp==NULL){
        cout<<"Stack Overflow"<<endl;
        return;
     }else{
     temp->next = top;
     top = temp;
     size++;
     cout<<"Pushed "<<temp->data<<" in stack "<<endl;
     }
   }

   
//deleted
   void pop(){
    if(top==NULL){
        cout<<"Stack is Underflow";
        return;
    }else{
        Node *temp = top;
         cout<<"Popped "<<temp->data<<" from the stack "<<endl;
        top = top->next;
        delete temp;
        size--;
    }
   }

//    value pointing is printed
   int peek(){
     if(top==NULL){
        cout<<"Stack is empty\n";
        return -1;
     }else{
        return top->data;
     }
   }

   //ismepty
   bool isEmpty(){
     return top==NULL;
   }
   //issize
   int IsSize(){
    return size;
   }
};

int main(){
   Stack S;
   S.push(10);
   S.push(20);
   S.push(30);
   S.pop();
   cout<<S.peek()<<endl;
   cout<<S.IsSize()<<endl;
   cout<<S.isEmpty()<<endl;
}