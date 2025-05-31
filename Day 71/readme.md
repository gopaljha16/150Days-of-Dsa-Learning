# Day 71: Queue Data Structure - Complete Guide

## What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. Elements are added at one end (rear) and removed from the other end (front).

**Real-life analogy**: Think of a line at a movie theater - the first person in line gets the ticket first.

## Key Operations

1. **Push/Enqueue**: Add element to the rear
2. **Pop/Dequeue**: Remove element from the front  
3. **Front**: Get the front element without removing
4. **isEmpty**: Check if queue is empty
5. **isFull**: Check if queue is full (for array implementation)

---

## Implementation 1: Linear Array-Based Queue (Commented Code)

```cpp
class Queue{
    int *arr;           // Dynamic array to store elements
    int front, rear;    // Pointers to track front and rear positions
    int size;          // Maximum capacity of queue

    public:
    // Constructor - Initialize empty queue
    Queue(int n){
        arr = new int[n];    // Allocate memory for n elements
        front = -1;          // Initially no elements, so front = -1
        rear = -1;           // Initially no elements, so rear = -1
        size = n;            // Store maximum capacity
    }

    // Check if queue is empty
    bool isEmpty(){
        return front == -1;  // If front is -1, queue is empty
    }

    // Check if queue is full
    bool isFull(){
        return rear == size-1;  // If rear reaches last index, queue is full
    }

    // Add element to queue
    void push(int x){
        if(isEmpty()){              // First element case
            front = rear = 0;       // Both pointers start at index 0
            arr[0] = x;            // Store element at index 0
        }
        else if(isFull()){         // Queue overflow case
            cout << "Queue Overflow";
            return;
        }
        else{                      // Normal case
            rear = rear + 1;       // Move rear pointer forward
            arr[rear] = x;         // Store element at new rear position
        }
    }

    // Remove element from queue
    void pop(){
        if(isEmpty()){             // Queue underflow case
            cout << "Queue Underflow";
            return;
        }
        else{
            if(front == rear){     // Only one element left
                front = -1;        // Reset to empty state
                rear = -1;
            }
            else{                  // Multiple elements present
                front = front + 1; // Move front pointer forward
            }
        }
    }

    // Get front element
    int startele(){
        if(isEmpty()){
            return -1;             // No element to return
        }
        else{
            return arr[front];     // Return front element
        }
    }
};
```

### Pseudocode for Linear Queue:
```
ALGORITHM LinearQueue:

CONSTRUCTOR(n):
    1. Allocate array of size n
    2. Set front = -1, rear = -1
    3. Set size = n

PUSH(x):
    1. IF isEmpty() THEN
        - Set front = rear = 0
        - arr[0] = x
    2. ELSE IF isFull() THEN
        - Print "Queue Overflow"
    3. ELSE
        - Increment rear
        - arr[rear] = x

POP():
    1. IF isEmpty() THEN
        - Print "Queue Underflow"
    2. ELSE IF front == rear THEN
        - Set front = rear = -1
    3. ELSE
        - Increment front
```

### Problem with Linear Queue:
Once elements are popped, the front spaces become unusable, leading to **false overflow** even when the queue has empty spaces at the beginning.

---

## Implementation 2: Circular Array-Based Queue (Main Implementation)

```cpp
class Queue{
    int *arr;           // Dynamic array
    int front, rear;    // Circular pointers
    int size;          // Maximum capacity

    public:
    // Constructor - Same as linear queue
    Queue(int n){
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    // Check if empty - Same as linear
    bool isEmpty(){
        return front == -1;
    }

    // Check if full - CIRCULAR LOGIC
    bool isFull(){
        return (rear + 1) % size == front;  // Next position of rear equals front
    }

    // Push operation - CIRCULAR LOGIC
    void push(int x){
        if(isEmpty()){
            front = rear = 0;          // First element
            arr[0] = x;
        }
        else if(isFull()){
            cout << "Queue Overflow";
            return;
        }
        else{
            rear = (rear + 1) % size;  // CIRCULAR increment
            arr[rear] = x;
        }
    }

    // Pop operation - CIRCULAR LOGIC
    void pop(){
        if(isEmpty()){
            cout << "Queue Underflow";
            return;
        }
        else{
            if(front == rear){         // Last element
                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1) % size;  // CIRCULAR increment
            }
        }
    }

    // Get front element - Same as linear
    int startele(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
};
```

### Pseudocode for Circular Queue:
```
ALGORITHM CircularQueue:

ISFULL():
    RETURN (rear + 1) % size == front

PUSH(x):
    1. IF isEmpty() THEN
        - Set front = rear = 0
        - arr[0] = x
    2. ELSE IF isFull() THEN
        - Print "Queue Overflow"
    3. ELSE
        - rear = (rear + 1) % size
        - arr[rear] = x

POP():
    1. IF isEmpty() THEN
        - Print "Queue Underflow"
    2. ELSE IF front == rear THEN
        - Set front = rear = -1
    3. ELSE
        - front = (front + 1) % size
```

### Circular Queue Advantage:
Utilizes all array positions efficiently by wrapping around when reaching the end.

### Main Function Flow Analysis:
```cpp
int main(){
    Queue q1(5);                    // Create queue of size 5
    
    // Push operations - Fill the queue
    q1.push(10);    // rear=0, arr=[10, _, _, _, _]
    q1.push(22);    // rear=1, arr=[10, 22, _, _, _]
    q1.push(22);    // rear=2, arr=[10, 22, 22, _, _]
    q1.push(22);    // rear=3, arr=[10, 22, 22, 22, _]
    q1.push(22);    // rear=4, arr=[10, 22, 22, 22, 22] - FULL
    
    // Pop operation
    q1.pop();       // front=1, arr=[_, 22, 22, 22, 22]
    
    // Push after pop - Demonstrates circular nature
    q1.push(30);    // rear=0 (wraps around), arr=[30, 22, 22, 22, 22]
    
    // Check front element
    int x = q1.startele();  // Returns 22 (element at front=1)
    
    // Status checks
    cout << q1.isEmpty();   // Returns 0 (false)
    cout << q1.isFull();    // Returns 1 (true)
}
```

---

## Implementation 3: Linked List-Based Queue

```cpp
// Node structure for linked list
class Node{
    public:
    int data;        // Data stored in node
    Node *next;      // Pointer to next node

    // Constructor
    Node(int value){
        data = value;
        next = NULL;  // Initialize next as NULL
    }
};

// Queue using linked list
class Queue{
    Node *front, *rear;  // Pointers to front and rear nodes

    public:
    // Constructor
    Queue(){
        front = rear = NULL;  // Initially empty queue
    }

    // Check if empty
    bool isEmpty(){
        return front == NULL;  // If front is NULL, queue is empty
    }

    // Push operation
    void push(int x){
        if(isEmpty()){
            front = new Node(x);      // Create first node
            rear = front;             // Both pointers point to same node
        }
        else{
            rear->next = new Node(x); // Create new node at rear
            if(rear->next == NULL){   // Memory allocation failed
                cout << "Queue Underflow";
                return;
            }
            rear = rear->next;        // Update rear pointer
        }
    }

    // Pop operation
    void pop(){
        if(isEmpty()){
            cout << "Queue underflow";
            return;
        }
        else{
            Node *temp = front;       // Store current front
            front = front->next;      // Move front to next node
            delete temp;              // Delete old front node
        }
    }

    // Get front element
    int start(){
        if(isEmpty()){
            return -1;
        }
        else{
            return front->data;       // Return data of front node
        }
    }
};
```

### Pseudocode for Linked List Queue:
```
ALGORITHM LinkedListQueue:

PUSH(x):
    1. Create newNode with data = x
    2. IF isEmpty() THEN
        - front = rear = newNode
    3. ELSE
        - rear->next = newNode
        - rear = newNode

POP():
    1. IF isEmpty() THEN
        - Print "Queue Underflow"
    2. ELSE
        - temp = front
        - front = front->next
        - Delete temp

START():
    1. IF isEmpty() THEN
        - RETURN -1
    2. ELSE
        - RETURN front->data
```

### Linked List Queue Advantages:
- Dynamic size (no fixed capacity)
- No memory wastage
- No overflow condition (only limited by available memory)

---

## Implementation 4: STL Queue (Standard Template Library)

```cpp
#include <queue>        // Include queue header

int main(){
    queue<int> q;       // Create STL queue of integers
    
    // Push operations
    q.push(10);         // Add 10 to rear
    q.push(20);         // Add 20 to rear
    q.push(30);         // Add 30 to rear
    q.push(80);         // Add 80 to rear
    // Queue: [10, 20, 30, 80] (front to rear)
    
    // Pop operation
    q.pop();            // Remove front element (10)
    // Queue: [20, 30, 80]
    
    // Access operations
    cout << q.front();  // Print front element: 20
    cout << q.back();   // Print rear element: 80
    
    // Status operations
    cout << q.size();   // Print size: 3
    cout << q.empty();  // Print 0 (false - not empty)
}
```

### STL Queue Operations:
```
push(x)     - Add element x to rear
pop()       - Remove front element (returns void)
front()     - Get front element
back()      - Get rear element
size()      - Get number of elements
empty()     - Check if queue is empty
```

---

## GeeksforGeeks Problem Solutions

### Array Implementation Solution:
```cpp
void MyQueue::push(int x) {
    if(rear < 100005){      // Check array bounds
        arr[rear] = x;      // Store element at rear
        rear++;             // Increment rear
    }
}

int MyQueue::pop() {
    if(front == rear){      // Queue is empty
        return -1;
    }
    int val = arr[front];   // Get front element
    front++;                // Move front forward
    return val;             // Return the element
}
```

### Linked List Implementation Solution:
```cpp
void MyQueue::push(int x) {
    if(front == NULL){              // First element
        front = new QueueNode(x);
        rear = front;
    }
    else{
        rear->next = new QueueNode(x);  // Add at rear
        rear = rear->next;              // Update rear
    }
}

int MyQueue::pop() {
    if(front == NULL){              // Empty queue
        return -1;
    }
    else{
        int val = front->data;      // Get front data
        QueueNode *temp = front;    // Store current front
        front = front->next;        // Move front
        delete temp;                // Delete old front
        return val;                 // Return the data
    }
}
```

---

## Time and Space Complexity Analysis

### Array-Based Queue:
- **Push**: O(1)
- **Pop**: O(1)
- **Front**: O(1)
- **Space**: O(n) where n is the maximum capacity

### Linked List-Based Queue:
- **Push**: O(1)
- **Pop**: O(1)
- **Front**: O(1)
- **Space**: O(m) where m is the current number of elements

### STL Queue:
- All operations: O(1)
- Internally uses deque (double-ended queue)

---

## Key Concepts Summary

1. **FIFO Principle**: First element added is the first to be removed
2. **Two Pointers**: Front (for removal) and Rear (for insertion)
3. **Circular Array**: Prevents false overflow by wrapping around
4. **Linked List**: Dynamic size, no overflow condition
5. **STL Queue**: Ready-to-use implementation with optimized operations

## Common Applications

- **Process Scheduling**: Operating systems use queues for process management
- **Breadth-First Search**: Graph traversal algorithm
- **Buffer**: Data streaming and handling requests
- **Print Queue**: Managing print jobs
- **Call Center Systems**: Managing incoming calls

