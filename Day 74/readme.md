# Deque (Double-Ended Queue) - Complete Implementation Guide

## Table of Contents
1. [Introduction](#introduction)
2. [Definition and Properties](#definition-and-properties)
3. [Types of Implementation](#types-of-implementation)
4. [Linked List Implementation](#linked-list-implementation)
5. [Array Implementation](#array-implementation)
6. [STL Deque Implementation](#stl-deque-implementation)
7. [Time and Space Complexity](#time-and-space-complexity)
8. [Applications](#applications)
9. [Comparison with Other Data Structures](#comparison)

## Introduction

A **Deque** (pronounced "deck") is a linear data structure that allows insertion and deletion of elements from both ends - front and rear. It combines the features of both stack and queue, making it a versatile data structure.

## Definition and Properties

### What is a Deque?
- **Full Form**: Double-Ended Queue
- **Operations**: Insert/Delete from both front and rear ends
- **Access**: Elements can be accessed from both ends
- **Flexibility**: Can work as both stack and queue

### Key Properties:
- Dynamic size (in most implementations)
- Efficient insertion/deletion at both ends
- Random access (in array-based implementations)
- Memory efficient compared to separate stack and queue

### Visual Representation:
```
    Front                           Rear
      ↓                              ↓
   [elem1] ← [elem2] ← [elem3] ← [elem4]
      ↑                              ↑
   Insert/Delete              Insert/Delete
```

## Types of Implementation

### 1. Input Restricted Deque
- Input allowed only at one end
- Output allowed from both ends

### 2. Output Restricted Deque  
- Input allowed from both ends
- Output allowed only from one end

### 3. General Deque
- Both input and output allowed from both ends

## Linked List Implementation

### Structure Design:
```cpp
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
```

### Visual Representation:
```
NULL ← [prev|data|next] ↔ [prev|data|next] ↔ [prev|data|next] → NULL
       ↑                                                        ↑
     front                                                    rear
```

### Complete Implementation:

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DequeLinkedList {
    Node *front, *rear;

public:
    DequeLinkedList() {
        front = rear = NULL;
    }

    // Check if deque is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Push element to front
    void push_front(int x) {
        Node* newNode = new Node(x);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << x << " pushed to front" << endl;
    }

    // Push element to rear
    void push_back(int x) {
        Node* newNode = new Node(x);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << x << " pushed to rear" << endl;
    }

    // Pop element from front
    void pop_front() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }
        
        Node* temp = front;
        cout << temp->data << " popped from front" << endl;
        
        if (front == rear) {  // Only one element
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }
        
        delete temp;
    }

    // Pop element from rear
    void pop_back() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }
        
        Node* temp = rear;
        cout << temp->data << " popped from rear" << endl;
        
        if (front == rear) {  // Only one element
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }
        
        delete temp;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return rear->data;
    }

    // Display deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        
        Node* temp = front;
        cout << "Deque: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~DequeLinkedList() {
        while (!isEmpty()) {
            pop_front();
        }
    }
};
```

### Pseudocode for Linked List Operations:

#### Push Front:
```
ALGORITHM push_front(x):
1. CREATE newNode with data = x
2. IF deque is empty:
     SET front = rear = newNode
   ELSE:
     SET newNode.next = front
     SET front.prev = newNode
     SET front = newNode
3. END
```

#### Pop Front:
```
ALGORITHM pop_front():
1. IF deque is empty:
     PRINT "Underflow"
     RETURN
2. SET temp = front
3. IF only one element:
     SET front = rear = NULL
   ELSE:
     SET front = front.next
     SET front.prev = NULL
4. DELETE temp
5. END
```

## Array Implementation

### Circular Array Approach:
```
Index: 0   1   2   3   4
      [_] [_] [_] [_] [_]
       ↑               ↑
     front           rear
```

### Complete Implementation:

```cpp
#include <iostream>
using namespace std;

class DequeArray {
    int *arr;
    int front, rear, size, capacity;

public:
    DequeArray(int n) {
        capacity = n;
        arr = new int[n];
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void push_front(int x) {
        if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        
        arr[front] = x;
        size++;
        cout << x << " pushed to front" << endl;
    }

    void push_back(int x) {
        if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        
        arr[rear] = x;
        size++;
        cout << x << " pushed to rear" << endl;
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }

        cout << arr[front] << " popped from front" << endl;
        
        if (size == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        
        size--;
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }

        cout << arr[rear] << " popped from rear" << endl;
        
        if (size == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deque: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~DequeArray() {
        delete[] arr;
    }
};
```

### Circular Array Visualization:
```
Initial: front = rear = -1
After push_back(10): 
   Index: 0   1   2   3   4
         [10] [_] [_] [_] [_]
          ↑
    front=rear=0

After push_front(20):
   Index: 0   1   2   3   4
         [10] [_] [_] [_] [20]
          ↑               ↑
        rear=0         front=4
```

## STL Deque Implementation

### How STL Deque Works Internally:

The C++ STL deque is implemented using a **map of blocks** (not the map container, but an array of pointers to blocks).

#### Internal Structure:
```
Map (Array of Pointers):
[ptr0] [ptr1] [ptr2] [ptr3] [ptr4]
  ↓      ↓      ↓      ↓      ↓
Block0 Block1 Block2 Block3 Block4
[data] [data] [data] [data] [data]
[data] [data] [data] [data] [data]
[data] [data] [data] [data] [data]
[data] [data] [data] [data] [data]
```

#### Key Components:
1. **Map**: Array of pointers to blocks
2. **Blocks**: Fixed-size arrays containing actual data
3. **Iterators**: Complex iterators that can jump between blocks

#### Advantages of STL Implementation:
- O(1) insertion/deletion at both ends
- O(1) random access
- Memory efficient
- Dynamic resizing

### STL Deque Usage Examples:

```cpp
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    // Declaration
    deque<int> dq;
    
    // Basic operations
    dq.push_back(10);     // [10]
    dq.push_front(20);    // [20, 10]
    dq.push_back(30);     // [20, 10, 30]
    dq.push_front(40);    // [40, 20, 10, 30]
    
    // Access elements
    cout << "Front: " << dq.front() << endl;  // 40
    cout << "Back: " << dq.back() << endl;    // 30
    cout << "Size: " << dq.size() << endl;    // 4
    
    // Random access
    cout << "Element at index 2: " << dq[2] << endl;  // 10
    cout << "Element at index 1: " << dq.at(1) << endl; // 20
    
    // Iteration
    cout << "Elements: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Range-based for loop
    cout << "Elements (range-based): ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    
    // Pop operations
    dq.pop_front();  // Remove 40: [20, 10, 30]
    dq.pop_back();   // Remove 30: [20, 10]
    
    // Insert at specific position
    dq.insert(dq.begin() + 1, 25);  // [20, 25, 10]
    
    // Erase element
    dq.erase(dq.begin());  // [25, 10]
    
    // Clear all elements
    dq.clear();
    
    return 0;
}
```

### Advanced STL Deque Operations:

```cpp
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void demonstrateAdvancedOperations() {
    deque<int> dq = {1, 2, 3, 4, 5};
    
    // Resize deque
    dq.resize(8, 0);  // [1, 2, 3, 4, 5, 0, 0, 0]
    
    // Assign values
    deque<int> dq2;
    dq2.assign(5, 10);  // [10, 10, 10, 10, 10]
    
    // Insert multiple elements
    dq.insert(dq.begin() + 2, 3, 99);  // Insert 3 copies of 99 at index 2
    
    // Insert from another container
    vector<int> vec = {100, 200, 300};
    dq.insert(dq.end(), vec.begin(), vec.end());
    
    // Find and replace
    auto it = find(dq.begin(), dq.end(), 99);
    if (it != dq.end()) {
        *it = 999;
    }
    
    // Sort deque
    sort(dq.begin(), dq.end());
    
    // Reverse deque
    reverse(dq.begin(), dq.end());
    
    // Display
    cout << "Final deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
}
```

## Time and Space Complexity

### Linked List Implementation:
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| push_front() | O(1) | O(1) |
| push_back() | O(1) | O(1) |
| pop_front() | O(1) | O(1) |
| pop_back() | O(1) | O(1) |
| getFront() | O(1) | O(1) |
| getRear() | O(1) | O(1) |
| **Overall Space** | - | O(n) |

### Array Implementation:
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| push_front() | O(1) | O(1) |
| push_back() | O(1) | O(1) |
| pop_front() | O(1) | O(1) |
| pop_back() | O(1) | O(1) |
| Random Access | O(1) | O(1) |
| **Overall Space** | - | O(n) |

### STL Deque:
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| push_front() | O(1) amortized | O(1) |
| push_back() | O(1) amortized | O(1) |
| pop_front() | O(1) | O(1) |
| pop_back() | O(1) | O(1) |
| Random Access | O(1) | O(1) |
| insert() | O(n) | O(1) |
| erase() | O(n) | O(1) |



## Comparison with Other Data Structures {#comparison}

### Deque vs Vector:
| Feature | Deque | Vector |
|---------|-------|--------|
| Front insertion | O(1) | O(n) |
| Back insertion | O(1) amortized | O(1) amortized |
| Random access | O(1) | O(1) |
| Memory layout | Non-contiguous | Contiguous |
| Cache performance | Moderate | Better |

### Deque vs List:
| Feature | Deque | List |
|---------|-------|------|
| Random access | O(1) | O(n) |
| Front/Back ops | O(1) | O(1) |
| Middle insertion | O(n) | O(1) |
| Memory overhead | Moderate | Higher |

### Deque vs Queue/Stack:
| Feature | Deque | Queue | Stack |
|---------|-------|-------|-------|
| Front access | ✓ | ✓ | ✗ |
| Back access | ✓ | ✗ | ✓ |
| Both end ops | ✓ | ✗ | ✗ |
| Flexibility | High | Low | Low |

## Best Practices and Tips

### 1. When to Use Deque:
- Need insertion/deletion at both ends
- Require random access with good performance
- Want flexibility of both stack and queue
- Don't need guaranteed contiguous memory

