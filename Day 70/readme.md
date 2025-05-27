# Day 70: Multiple Stacks in Array - DSA Study Notes

## 📋 Problems Covered

1. **Two Stacks in One Array** (GFG Medium)
2. **N Stacks in One Array** (Coding Ninjas Hard)

---

# Problem 1: Two Stacks in One Array

## 🎯 Problem Statement

Implement two stacks using a single array. Both stacks should support standard operations:
- `push1(x)` - Push element to stack 1
- `push2(x)` - Push element to stack 2  
- `pop1()` - Pop from stack 1
- `pop2()` - Pop from stack 2

### Key Challenge: Efficient space utilization

---

## 🚀 Solution Approach

### Strategy:
- **Stack 1**: Grows from **left to right** (index 0 onwards)
- **Stack 2**: Grows from **right to left** (index n-1 backwards)
- **Full Condition**: When both stacks meet each other

### Visual Representation:
```
Array: [_ _ _ _ _ _ _ _]
        ↑           ↑
      Stack1      Stack2
      (top1)      (top2)
      
Stack1 grows →    ← Stack2 grows
```

---

## 💻 Code Implementation with Detailed Comments

```cpp
class twoStacks {
public:
    int *arr;        // Main array to store both stacks
    int top1, top2;  // Top pointers for both stacks
    int size;        // Total size of the array
    
    // Constructor: Initialize the two stacks
    twoStacks(int n = 100) {
        size = n;                    // Store array size
        arr = new int[n];           // Allocate memory for array
        top1 = -1;                  // Stack1 starts before index 0
        top2 = n;                   // Stack2 starts after last index
    }

    // Function to push an integer into stack1
    void push1(int x) {
        // Check if array is full (stacks have met)
        if(top1 + 1 == top2) {     // If next position of top1 meets top2
            return;                 // Array is full, cannot push
        } else {                   // Space is available
            top1++;                // Move top1 to next position
            arr[top1] = x;         // Store element at new top1 position
        }
    }

    // Function to push an integer into stack2  
    void push2(int x) {
        // Check if array is full (stacks have met)
        if(top2 - 1 == top1) {    // If previous position of top2 meets top1
            return;               // Array is full, cannot push
        } else {                  // Space is available
            top2--;               // Move top2 to previous position
            arr[top2] = x;        // Store element at new top2 position
        }
    }

    // Function to remove an element from top of stack1
    int pop1() {
        if(top1 == -1) {          // Check if stack1 is empty
            return -1;            // Return -1 for empty stack
        } else {                  // Stack1 has elements
            int num = arr[top1];  // Get top element
            top1--;               // Move top1 pointer back
            return num;           // Return the popped element
        }
    }

    // Function to remove an element from top of stack2
    int pop2() {
        if(top2 == size) {        // Check if stack2 is empty
            return -1;            // Return -1 for empty stack  
        } else {                  // Stack2 has elements
            int num = arr[top2];  // Get top element
            top2++;               // Move top2 pointer forward
            return num;           // Return the popped element
        }
    }
};
```

---

## 🔍 Detailed Dry Run

### Example Operations:
`twoStacks(8)`, `push1(1)`, `push1(2)`, `push2(10)`, `push2(20)`, `pop1()`, `pop2()`

### Initial State:
```
Array: [_ _ _ _ _ _ _ _]  (size = 8)
        0 1 2 3 4 5 6 7
top1 = -1, top2 = 8

Visual:
         top1(-1)    top2(8)
            ↓           ↓
Array: [_ _ _ _ _ _ _ _]
        ← Stack1    Stack2 →
```

### Step 1: `push1(1)`
```cpp
// Check: top1 + 1 == top2? → -1 + 1 == 8? → 0 == 8? → false
// Space available, proceed
top1++;          // top1 = 0
arr[top1] = 1;   // arr[0] = 1

Result:
Array: [1 _ _ _ _ _ _ _]
        ↑           ↑
      top1(0)    top2(8)
```

### Step 2: `push1(2)`  
```cpp
// Check: top1 + 1 == top2? → 0 + 1 == 8? → 1 == 8? → false
// Space available, proceed
top1++;          // top1 = 1  
arr[top1] = 2;   // arr[1] = 2

Result:
Array: [1 2 _ _ _ _ _ _]
          ↑         ↑
        top1(1)  top2(8)
```

### Step 3: `push2(10)`
```cpp
// Check: top2 - 1 == top1? → 8 - 1 == 1? → 7 == 1? → false
// Space available, proceed
top2--;          // top2 = 7
arr[top2] = 10;  // arr[7] = 10

Result:
Array: [1 2 _ _ _ _ _ 10]
          ↑         ↑
        top1(1)  top2(7)
```

### Step 4: `push2(20)`
```cpp
// Check: top2 - 1 == top1? → 7 - 1 == 1? → 6 == 1? → false  
// Space available, proceed
top2--;          // top2 = 6
arr[top2] = 20;  // arr[6] = 20

Result:
Array: [1 2 _ _ _ _ 20 10]
          ↑       ↑
        top1(1) top2(6)
```

### Step 5: `pop1()`
```cpp
// Check: top1 == -1? → 1 == -1? → false
// Stack1 not empty, proceed
int num = arr[top1];  // num = arr[1] = 2
top1--;               // top1 = 0
return num;           // return 2

Result:
Array: [1 2 _ _ _ _ 20 10]  (arr[1] still contains 2, but logically removed)
        ↑         ↑
      top1(0)  top2(6)
```

### Step 6: `pop2()`
```cpp
// Check: top2 == size? → 6 == 8? → false
// Stack2 not empty, proceed  
int num = arr[top2];  // num = arr[6] = 20
top2++;               // top2 = 7
return num;           // return 20

Result:
Array: [1 2 _ _ _ _ 20 10]  (arr[6] still contains 20, but logically removed)
        ↑           ↑
      top1(0)    top2(7)
```

### Final State:
```
Stack1: [1] (bottom to top)
Stack2: [10] (bottom to top)
Available space: indices 2, 3, 4, 5
```

---

## 📊 Space Utilization Analysis

### Maximum Efficiency:
```
Best Case: One stack uses entire array
Array: [1 2 3 4 5 6 7 8] - Stack1 full, Stack2 empty
or     [_ _ _ _ _ 8 7 6] - Stack2 full, Stack1 empty

Worst Case: Both stacks meet in middle
Array: [1 2 3 4 _ _ 8 7] - Both stacks have equal elements
```

---

# Problem 2: N Stacks in One Array

## 🎯 Problem Statement

Implement N stacks using a single array with efficient space utilization.

### Challenge: 
- Fixed partitioning wastes space
- Need dynamic space allocation between stacks

---

## 🚀 Solution Approach

### Key Components:
1. **Main Array**: Stores all stack elements
2. **Top Array**: Stores head of linked list for each stack  
3. **Free Space Stack**: Manages available indices
4. **Linked List Nodes**: Chain elements of same stack

### Data Structure Design:
```
arr[]:     [val1, val2, val3, ...]     // Main storage
Top[]:     [Node*, Node*, ...]         // Head pointers for each stack
Free Stack: [0, 1, 2, 3, ...]         // Available indices
```

---

## 💻 Code Implementation with Detailed Comments

```cpp
#include <bits/stdc++.h> 
#include <stack>

// Node class to create linked list for each stack
class Node {
public:
    int index;      // Index in main array where element is stored
    Node *next;     // Pointer to next element in same stack

    // Constructor to create new node
    Node(int x) {
        index = x;  // Store array index
        next = NULL; // Initialize next as NULL
    }
};

class NStack {
public: 
    int *arr;           // Main array to store all stack elements
    Node **Top;         // Array of pointers to top nodes of each stack
    stack<int> st;      // Stack to manage free/available indices

    // Constructor: Initialize N stacks with total size S
    NStack(int N, int S) {
        // Allocate main array of size S
        arr = new int[S];           
        
        // Allocate array of N pointers (one for each stack's top)
        Top = new Node*[N];         
        
        // Initialize all stack tops as NULL (empty stacks)
        for(int i = 0; i < N; i++) {
            Top[i] = NULL;          // Each stack is initially empty
        }        

        // Push all array indices to free space stack
        // This represents all available positions in main array
        for(int i = 0; i < S; i++) {
            st.push(i);             // All positions are initially free
        }
    }

    // Push element X into Mth stack (1-indexed)
    // Returns true if successful, false if array is full
    bool push(int x, int m) {
        // Check if any free space is available
        if(st.empty()) {            // No free indices available
            return false;           // Cannot push, array is full
        }

        // Get a free index from free space stack
        int freeIndex = st.top();   // Get top free index
        st.pop();                   // Remove it from free space
        
        // Store the element in main array at free index
        arr[freeIndex] = x;         
        
        // Create new node with this index
        Node *temp = new Node(freeIndex);
        
        // Link this node to current top of mth stack
        temp->next = Top[m-1];      // Point to previous top (m-1 for 0-indexed)
        
        // Update top of mth stack to this new node
        Top[m-1] = temp;            // New node becomes top
        
        return true;                // Successfully pushed
    }

    // Pop top element from Mth stack (1-indexed)  
    // Returns -1 if stack is empty, otherwise returns popped element
    int pop(int m) { 
        // Check if mth stack is empty
        if(Top[m-1] == NULL) {      // Stack is empty (m-1 for 0-indexed)
            return -1;              // Return -1 for empty stack
        }
        
        // Stack has elements, proceed with pop
        Node *topNode = Top[m-1];   // Get current top node
        
        // Get the element value from main array
        int element = arr[topNode->index];
        
        // Return the freed index to free space stack
        st.push(topNode->index);    // This index is now available
        
        // Update top pointer to next node in the chain
        Top[m-1] = topNode->next;   // Move top to next element
        
        // Free the memory of popped node
        delete topNode;             // Prevent memory leak
        
        return element;             // Return the popped element
    }
};
```

---

## 🔍 Detailed Dry Run for N Stacks

### Example: `NStack(3, 6)` - 3 stacks, array size 6

### Initial State:
```cpp
// After constructor execution:
arr = [_, _, _, _, _, _]        // Uninitialized array of size 6
Top = [NULL, NULL, NULL]       // 3 stack tops, all empty
st = [5, 4, 3, 2, 1, 0]       // Free indices (top to bottom)

Visual representation:
Stack 0: NULL
Stack 1: NULL  
Stack 2: NULL
Free indices: 0, 1, 2, 3, 4, 5 (all available)
```

### Step 1: `push(10, 1)` - Push 10 to Stack 1

```cpp
// Check if free space available
if(st.empty()) → false (st has elements)

// Get free index
int freeIndex = st.top(); → freeIndex = 5
st.pop(); → st = [4, 3, 2, 1, 0]

// Store element in array
arr[freeIndex] = x; → arr[5] = 10
// arr = [_, _, _, _, _, 10]

// Create new node
Node *temp = new Node(freeIndex); → temp = Node(index=5, next=NULL)

// Link to current top
temp->next = Top[m-1]; → temp->next = Top[0] = NULL

// Update top
Top[m-1] = temp; → Top[0] = temp

return true;
```

**Result:**
```
arr = [_, _, _, _, _, 10]
Top[0] → Node(index=5, next=NULL)
Top[1] → NULL
Top[2] → NULL
st = [4, 3, 2, 1, 0]

Stack 0: 10 (at index 5)
Stack 1: empty
Stack 2: empty
```

### Step 2: `push(20, 1)` - Push 20 to Stack 1

```cpp
// Get free index
freeIndex = st.top(); → freeIndex = 4
st.pop(); → st = [3, 2, 1, 0]

// Store element
arr[4] = 20
// arr = [_, _, _, _, 20, 10]

// Create and link node
Node *temp = new Node(4);
temp->next = Top[0]; → Points to Node(index=5)
Top[0] = temp; → Top[0] now points to Node(index=4)
```

**Result:**
```
arr = [_, _, _, _, 20, 10]
Top[0] → Node(index=4, next→Node(index=5, next=NULL))
st = [3, 2, 1, 0]

Stack 0: 20 → 10 (chain: index 4 → index 5)
```

### Step 3: `push(30, 2)` - Push 30 to Stack 2

```cpp
// Get free index
freeIndex = st.top(); → freeIndex = 3
st.pop(); → st = [2, 1, 0]

// Store element
arr[3] = 30
// arr = [_, _, _, 30, 20, 10]

// Create and link node
Node *temp = new Node(3);
temp->next = Top[1]; → temp->next = NULL (Stack 2 was empty)
Top[1] = temp;
```

**Result:**
```
arr = [_, _, _, 30, 20, 10]
Top[0] → Node(index=4) → Node(index=5) → NULL
Top[1] → Node(index=3) → NULL  
Top[2] → NULL
st = [2, 1, 0]

Stack 0: 20 → 10
Stack 1: 30
Stack 2: empty
```

### Step 4: `pop(1)` - Pop from Stack 1

```cpp
// Check if stack is empty
if(Top[m-1] == NULL) → if(Top[0] == NULL) → false

// Get top node and element
Node *topNode = Top[0]; → Node(index=4)
int element = arr[topNode->index]; → element = arr[4] = 20

// Return freed index to free space
st.push(topNode->index); → st.push(4)
// st = [4, 2, 1, 0]

// Update top pointer
Top[0] = topNode->next; → Top[0] = Node(index=5)

// Free memory
delete topNode;

return element; → return 20
```

**Result:**
```
arr = [_, _, _, 30, 20, 10]  (arr[4] still contains 20, but logically removed)
Top[0] → Node(index=5) → NULL
Top[1] → Node(index=3) → NULL
st = [4, 2, 1, 0]

Stack 0: 10 (only element remaining)
Stack 1: 30
Available indices: 0, 1, 2, 4
```

---

## 🎨 Visual Flow Diagram

### Push Operation Flow:
```
START
  ↓
Check if free space available
  ↓ (Yes)
Get free index from free stack
  ↓
Store element in main array[index]
  ↓
Create new node with this index
  ↓
Link node to current stack top
  ↓
Update stack top to new node
  ↓
Return success
```

### Pop Operation Flow:
```
START
  ↓
Check if stack is empty
  ↓ (No)
Get element from array[top->index]
  ↓
Return freed index to free stack
  ↓
Update stack top to next node
  ↓
Delete current top node
  ↓
Return element
```

---

## 📊 Complexity Analysis

### Two Stacks in Array:

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| push1/push2 | O(1) | O(1) |
| pop1/pop2 | O(1) | O(1) |
| Constructor | O(1) | O(n) |

### N Stacks in Array:

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| push | O(1) | O(1) |
| pop | O(1) | O(1) |
| Constructor | O(S) | O(N + S) |

**Space Breakdown for N Stacks:**
- Main array: O(S)
- Top pointers: O(N)  
- Nodes: O(S) in worst case
- Free stack: O(S)
- **Total: O(N + S)**

---

## 🐛 Common Debugging Points

### Two Stacks:
1. **Boundary Conditions**: 
   ```cpp
   // Wrong: top1 + 1 > top2
   // Correct: top1 + 1 == top2
   ```

2. **Pop from Empty Stack**:
   ```cpp
   // Always check: top1 == -1 and top2 == size
   ```

### N Stacks:
1. **Memory Leaks**:
   ```cpp
   // Always delete node after pop
   delete topNode;
   ```

2. **Index Confusion**:
   ```cpp
   // Remember: Stack numbers are 1-indexed, arrays are 0-indexed
   Top[m-1] // for mth stack
   ```

3. **Free Space Management**:
   ```cpp
   // Always return freed index to stack
   st.push(topNode->index);
   ```

---

## 🎓 Key Takeaways

### Design Patterns:
1. **Two-Pointer Technique**: Efficient for two stacks
2. **Linked List + Array**: Combines benefits of both structures
3. **Free Space Management**: Stack for available indices

### Space Optimization:
1. **Dynamic Allocation**: Better than fixed partitioning
2. **No Space Waste**: Every array position can be used by any stack
3. **Efficient Tracking**: Minimal overhead for management

### Problem-Solving Insights:
1. **Multiple Data Structures**: Sometimes combination works best
2. **Index Management**: Critical for array-based implementations
3. **Memory Management**: Important in dynamic allocation

---

