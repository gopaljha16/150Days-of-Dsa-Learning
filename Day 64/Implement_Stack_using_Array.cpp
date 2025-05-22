#include <iostream>
using namespace std;

class Stack
{

    int *arr;
    int size;
    int top;
   

public:
 int flag;
    // constructor
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
        }

    // operations

    // push
    void push(int value)
    {
        // edge case
        if (top == size - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " Into the stack\n";
            flag = 0;
        }
    }
    // pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow\n";
        }
        else
        {
            cout << "Popped " << arr[top] << " from the stack\n";
            top--;
            if(top==-1)
             flag = 1;
        }
    }
    // peek
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        else
        {
            return arr[top]; // element will be printed
        }
    }
    // isEmpty
    bool isEmpty()
    {

        return top == -1;
    }
    // IsSize
    int IsSize()
    { // prints the element size
        return top + 1;
    }
};

int main()
{
    Stack S(5);
    //  S.push(-1);
     int value = S.peek();
     if(S.flag==0){
        cout<<value;
     }
     
   
}