#include <iostream>
using namespace std;

class Dequeue
{
    int front, rear, size;
    int *arr;

public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // operations
    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    // push front
    void push_front(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            cout << "Pusshed " << x << " into the front of queue" << endl;
            arr[0] = x;
            return;
        }
        else if (isFull())
        {
            cout << "Dequeue Overflow" << endl;
            return;
        }
        else
        {
            front = (front - 1 + size) % size;
            cout << "Pusshed " << x << " into the front of queue" << endl;
            arr[front] = x;
            return;
        }
    }

    // push back
    void push_back(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            cout << "Pushed " << x << " into back of the queue" << endl;
            arr[0] = x;
            return;
        }
        else if (isFull())
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            cout << "Pushed " << x << " into back of the queue" << endl;
            arr[rear] = x;
            return;
        }
    }

    //pop operation
    void pop_front(){
        if(isEmpty()){
            return;
        }else{
            if(front==rear){
                cout<<"Qeueu Underflow"<<endl;
                front = rear = -1;
            }else{
                cout<<"Popped "<<arr[front]<<" from the front of queue "<<endl;
                front = (front+1)%size;
                return;
            }
        }
    }

    void pop_back(){
        if(isEmpty()){
            return;
        }else{
            if(front==rear){
                cout<<"Queue Underflow"<<endl;
                front = rear =-1;
            }else{
                cout<<"Popped "<<arr[rear]<<" from the front of queue "<<endl;
                rear = (rear-1+size)%size;
                return;
            }
        }
    }

    int start(){
        if(isEmpty()){
            return-1;
        }else{
            return arr[front];
        }
    }

    int end(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[rear];
        }
    }
};

int main()
{
 Dequeue d(5);
 d.push_front(10);
 d.push_back(20);
 d.push_back(30);
 d.push_back(40);
 d.pop_front();
 d.pop_front();
 cout<<d.start()<<endl;
 cout<<d.end()<<endl;
}