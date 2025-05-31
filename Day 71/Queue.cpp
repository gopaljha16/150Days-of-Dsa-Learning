#include <iostream>
using namespace std;
// queue
// class Queue{

//      int *arr;
//      int front , rear;
//      int size;

//      public:
//      //constructor
//      Queue(int n){
//         arr = new int[n];
//         front = -1;
//         rear = -1;
//         size = n;
//      }

//      //isempty
//      bool isEmpty(){
//         return front==-1;
//      }

//      //isFull
//      bool isFull(){
//         return rear==size-1;
//      }

//      //push operation 
//      void push(int x){
//         // is empty first check
//         if(isEmpty()){
//             front = rear = 0;
//             arr[0] = x;
//             cout<<"Pushed Element "<<x<<" Into the Queue"<<endl;
//         }else if(isFull()){ //checks the queue is full or not
//             cout<<"Queue Overflow";
//             return ;
//         }else{ // queue is not empty 
//              rear = rear+1;
//              cout<<"Pushed Element "<<x<<" Into the Queue"<<endl;
//              arr[rear] = x;

//         }
//      }

//      //pop operation 
//      void pop(){
//         //check is is empty or not
//         if(isEmpty()){
//             cout<<"Queue Underflow"<<endl;
//             return;
//         }else{
//             if(front==rear){ //if both are in the same position and delete is that we can make them into -1
//                 front = -1;
//                 rear = -1;
//             }else{ //element is there then front element deleted
//                 cout<<"Popped Element "<<arr[front]<<" from the queue"<<endl;
//                 front = front+1;
                
//             }
//         }
//      }

//      ////start / front
//      int startele(){
//         if(isEmpty()){ ///queue is empty
//             cout<<"Queue is Empty"<<endl;
//             return -1;
//         }else{ //not empty
//             return arr[front];
//         }
//      }


// };


// circular queue. circular array implementation
class Queue{

     int *arr;
     int front , rear;
     int size;

     public:
     //constructor
     Queue(int n){
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
     }

     //isempty
     bool isEmpty(){
        return front==-1;
     }

     //isFull
     bool isFull(){
        return (rear+1)%size==front;
     }

     //push operation 
     void push(int x){
        // is empty first check
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            cout<<"Pushed Element "<<x<<" Into the Queue"<<endl;
        }else if(isFull()){ //checks the queue is full or not
            cout<<"Queue Overflow";
            return ;
        }else{ // queue is not empty 
             rear = (rear+1)%size;
             cout<<"Pushed Element "<<x<<" Into the Queue"<<endl;
             arr[rear] = x;

        }
     }

     //pop operation 
     void pop(){
        //check is is empty or not
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }else{
            if(front==rear){ //if both are in the same position and delete is that we can make them into -1
                front = -1;
                rear = -1;
            }else{ //element is there then front element deleted
                cout<<"Popped Element "<<arr[front]<<" from the queue"<<endl;
                front = (front+1)%size;
                
            }
        }
     }

     ////start / front
     int startele(){
        if(isEmpty()){ ///queue is empty
            cout<<"Queue is Empty"<<endl;
            return -1;
        }else{ //not empty
            return arr[front];
        }
     }


};
int main(){
    Queue q1(5);
    cout<<"--------------------Push-----------------------"<<endl;
    q1.push(10);
    q1.push(22);
    q1.push(22);
    q1.push(22);
    q1.push(22);
  cout<<"-------------------pop------------------------"<<endl;
    q1.pop();
 q1.push(30);


    cout<<"-----------------start element---------------"<<endl;
   int x = q1.startele();
   if(!q1.isEmpty())
   cout<<x<<endl;
    cout<<"-------------------isEmpty----------------------"<<endl;
      cout<<q1.isEmpty()<<endl;
    cout<<"-------------------isfull--------------------------"<<endl;
    cout<<q1.isFull()<<endl;

    
}
