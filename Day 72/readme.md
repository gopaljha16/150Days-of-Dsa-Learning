# Day 72: Advanced Queue Operations & Problems - Complete Guide

## 📚 Table of Contents
1. [Printing Queue Elements - 3 Approaches](#printing-queue-elements)
2. [Queue Reversal Techniques](#queue-reversal)
3. [Reverse First K Elements](#reverse-first-k-elements)
4. [LeetCode Problems Solutions](#leetcode-problems)
5. [Visual Diagrams & Flow Charts](#visual-diagrams)
6. [Time & Space Complexity Analysis](#complexity-analysis)

---

## 🖨️ Printing Queue Elements - 3 Approaches

### Problem: Print all elements of a queue without permanently modifying it

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(20);
    q.push(40);
    q.push(30);
    q.push(60);
    q.push(70);
    // Queue: [20, 40, 30, 60, 70] (front to rear)
}
```

### 🔹 Approach 1: Simple Print (Destructive)
**Time Complexity: O(n) | Space Complexity: O(1)**

```cpp
// Approach 1: O(n) time, O(1) space - DESTROYS the queue
while(!q.empty()){
    cout << q.front() << " ";  // Print front element
    q.pop();                    // Remove front element
}
```

**Pseudocode:**
```
ALGORITHM PrintQueue_Destructive:
1. WHILE queue is not empty:
   a. Print front element
   b. Remove front element
2. END
```

**Flow Diagram:**
```
Initial: [20, 40, 30, 60, 70]
Step 1:  [40, 30, 60, 70]     → Print: 20
Step 2:  [30, 60, 70]         → Print: 40
Step 3:  [60, 70]             → Print: 30
Step 4:  [70]                 → Print: 60
Step 5:  []                   → Print: 70
Result:  Empty queue
```

### 🔹 Approach 2: Using Vector (Non-Destructive)
**Time Complexity: O(n) | Space Complexity: O(n)**

```cpp
// Approach 2: O(n) space - Preserves original queue
vector<int> ans;                    // Temporary storage
while(!q.empty()){
    ans.push_back(q.front());      // Store element in vector
    cout << q.front() << " ";      // Print element
    q.pop();                       // Remove from queue
}

// Restore queue from vector
for(int i = 0; i < ans.size(); i++){
    q.push(ans[i]);                // Push back to queue
}
```

**Pseudocode:**
```
ALGORITHM PrintQueue_Vector:
1. Create empty vector 'ans'
2. WHILE queue is not empty:
   a. Add front element to vector
   b. Print front element
   c. Remove front element
3. FOR each element in vector:
   a. Push element back to queue
4. END
```

**Visual Flow:**
```
Queue:  [20, 40, 30, 60, 70]
Vector: []

Step 1: Queue: [40, 30, 60, 70], Vector: [20]     → Print: 20
Step 2: Queue: [30, 60, 70],     Vector: [20, 40] → Print: 40
Step 3: Queue: [60, 70],         Vector: [20, 40, 30] → Print: 30
Step 4: Queue: [70],             Vector: [20, 40, 30, 60] → Print: 60
Step 5: Queue: [],               Vector: [20, 40, 30, 60, 70] → Print: 70

Restore: Queue: [20, 40, 30, 60, 70] (Original restored)
```

### 🔹 Approach 3: Circular Printing (Optimal)
**Time Complexity: O(n) | Space Complexity: O(1)**

```cpp
// Approach 3: O(1) space - Circular technique
int n = q.size();                   // Store original size
while(n--){                         // Loop n times
    cout << q.front() << " ";       // Print front element
    q.push(q.front());              // Push front to rear
    q.pop();                        // Remove original front
}
```

**Pseudocode:**
```
ALGORITHM PrintQueue_Circular:
1. Store original size 'n' of queue
2. REPEAT n times:
   a. Print front element
   b. Push front element to rear
   c. Remove front element
3. END (Queue remains unchanged)
```

**Detailed Visual Flow:**
```
Initial: [20, 40, 30, 60, 70] (size = 5)

Step 1: Print 20, Push 20 to rear, Pop front
        [40, 30, 60, 70, 20]

Step 2: Print 40, Push 40 to rear, Pop front  
        [30, 60, 70, 20, 40]

Step 3: Print 30, Push 30 to rear, Pop front
        [60, 70, 20, 40, 30]

Step 4: Print 60, Push 60 to rear, Pop front
        [70, 20, 40, 30, 60]

Step 5: Print 70, Push 70 to rear, Pop front
        [20, 40, 30, 60, 70] (Original order restored!)

Output: 20 40 30 60 70
```

---

## 🔄 Queue Reversal Techniques

### Problem: Reverse all elements in a queue

### 🔹 Approach 1: Using Vector

```cpp
vector<int> ans;                    // Temporary storage
queue<int> q;
q.push(10); q.push(20); q.push(30); q.push(40); q.push(50);

// Step 1: Transfer queue to vector
while(!q.empty()){
    ans.push_back(q.front());       // Store: [10, 20, 30, 40, 50]
    q.pop();
}

// Step 2: Push from vector in reverse order
for(int i = ans.size()-1; i >= 0; i--){
    q.push(ans[i]);                 // Result: [50, 40, 30, 20, 10]
}
```

**Pseudocode:**
```
ALGORITHM ReverseQueue_Vector:
1. Create empty vector
2. Transfer all elements from queue to vector
3. Push elements from vector to queue in reverse order
4. END
```

**Visual Representation:**
```
Original Queue: [10, 20, 30, 40, 50]
                     ↓
Vector:        [10, 20, 30, 40, 50]
                     ↓ (reverse iteration)
Reversed Queue: [50, 40, 30, 20, 10]
```

### 🔹 Approach 2: Using Stack (GeeksforGeeks Solution)

```cpp
class Solution {
public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st;              // Stack for reversal
        
        // Step 1: Transfer queue elements to stack
        while(!q.empty()){
            st.push(q.front());     // Stack: LIFO property
            q.pop();
        }
        
        // Step 2: Transfer stack elements back to queue
        while(!st.empty()){
            q.push(st.top());       // Reversed order due to LIFO
            st.pop();
        }
        
        return q;
    }
};
```

**Stack-based Reversal Flow:**
```
Queue → Stack → Queue (Reversed)

Original: [10, 20, 30, 40, 50]
          ↓
Stack:    [50]  ← 50 (top)
          [40]
          [30]
          [20]
          [10]  ← 10 (bottom)
          ↓
Reversed: [50, 40, 30, 20, 10]
```

---

## 🔢 Reverse First K Elements

### Problem: Reverse only the first K elements of a queue

```cpp
class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        stack<int> st;
        int n = q.size();                    // Original size
        int actualK = min(n, k);             // Handle edge cases
        
        // Step 1: Push first K elements to stack
        for(int i = 0; i < actualK; i++){
            st.push(q.front());
            q.pop();
        }
        
        // Step 2: Push stack elements back to queue (reversed)
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        // Step 3: Move remaining elements to maintain order
        for(int i = 0; i < n - actualK; i++){
            q.push(q.front());               // Circular rotation
            q.pop();
        }
        
        return q;
    }
};
```

**Pseudocode:**
```
ALGORITHM ReverseFirstK:
1. Initialize stack and calculate actualK = min(n, k)
2. Push first actualK elements from queue to stack
3. Push all stack elements back to queue
4. Rotate remaining (n - actualK) elements to maintain order
5. RETURN modified queue
```

**Step-by-Step Example (K=3):**
```
Original: [1, 2, 3, 4, 5] (n=5, k=3)

Step 1: Remove first 3 elements to stack
Queue: [4, 5]
Stack: [3, 2, 1] (top to bottom)

Step 2: Push stack to queue
Queue: [4, 5, 3, 2, 1]

Step 3: Rotate remaining 2 elements
Move 4: [5, 3, 2, 1, 4]
Move 5: [3, 2, 1, 4, 5]

Final: [3, 2, 1, 4, 5] ✓
```

---

## 🎫 LeetCode Problems Solutions

### 🔹 Problem 1: Time Needed to Buy Tickets

**Problem Statement:** People in a queue want to buy tickets. Each person needs `tickets[i]` tickets. Find time needed for person at index `k` to finish buying.

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;                        // Queue of indices
        int n = tickets.size();
        
        // Push all indices to queue
        for(int i = 0; i < n; i++){
            q.push(i);
        }
        
        int time = 0;                        // Total time counter
        
        // Continue until person k finishes buying
        while(tickets[k] != 0){
            tickets[q.front()]--;            // Person buys 1 ticket
            
            // If person still needs tickets, go back to queue
            if(tickets[q.front()])
                q.push(q.front());
            
            q.pop();                         // Remove from front
            time++;                          // Increment time
        }
        
        return time;
    }
};
```

**Algorithm Flow:**
```
ALGORITHM TicketTime:
1. Create queue with all person indices
2. Initialize time = 0
3. WHILE person k still needs tickets:
   a. Current person buys 1 ticket
   b. If person still needs tickets, rejoin queue
   c. Remove person from front
   d. Increment time
4. RETURN time
```

**Example Simulation:**
```
tickets = [2,3,2], k = 2
Initial queue: [0, 1, 2]
tickets: [2, 3, 2]

Time 1: Person 0 buys → tickets: [1, 3, 2], queue: [1, 2, 0]
Time 2: Person 1 buys → tickets: [1, 2, 2], queue: [2, 0, 1]  
Time 3: Person 2 buys → tickets: [1, 2, 1], queue: [0, 1, 2]
Time 4: Person 0 buys → tickets: [0, 2, 1], queue: [1, 2]
Time 5: Person 1 buys → tickets: [0, 1, 1], queue: [2, 1]
Time 6: Person 2 buys → tickets: [0, 1, 0], queue: [1]

Person 2 finished! Return time = 6
```

### 🔹 Problem 2: Implement Queue using Stack

**Key Insight:** Use two stacks to simulate queue's FIFO behavior

```cpp
class MyQueue {
    stack<int> st1;                          // Input stack
    stack<int> st2;                          // Output stack
    
public:
    MyQueue() {}
    
    bool empty() {
        return st1.empty() && st2.empty();   // Both stacks empty
    }
    
    void push(int x) {
        st1.push(x);                         // Always push to st1
    }
    
    int pop() {
        if(empty()) return 0;                // Edge case
        
        // If st2 has elements, pop from it
        if(!st2.empty()){
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        else {                               // st2 is empty
            // Transfer all from st1 to st2
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            
            int ele = st2.top();
            st2.pop();
            return ele;
        }
    }
    
    int peek() {
        if(empty()) return 0;
        
        if(!st2.empty()){
            return st2.top();                // Return top of st2
        }
        else {
            // Transfer all from st1 to st2
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};
```

**Two-Stack Queue Visualization:**
```
Push Operations (all go to st1):
push(1): st1=[1], st2=[]
push(2): st1=[2,1], st2=[]
push(3): st1=[3,2,1], st2=[]

First Pop Operation:
Transfer st1 to st2: st1=[], st2=[1,2,3]
Pop from st2: return 1, st2=[2,3]

Next Pop:
Pop from st2: return 2, st2=[3]

Push(4):
st1=[4], st2=[3]

Pop:
Pop from st2: return 3, st2=[]

Pop:
Transfer st1 to st2: st1=[], st2=[4]
Pop from st2: return 4
```

### 🔹 Problem 3: Implement Stack using Queue

**Key Insight:** Use two queues and transfer elements to maintain LIFO behavior

```cpp
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {}
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
    
    void push(int x) {
        if(empty()){
            q1.push(x);                      // First element goes to q1
        }
        else if(q1.empty()){                 // q2 has elements
            q2.push(x);
        }
        else {                               // q1 has elements
            q1.push(x);
        }
    }
    
    int pop() {
        if(empty()) return 0;
        
        if(q1.empty()){                      // Elements in q2
            // Move all but last to q1
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();            // Last element
            q2.pop();
            return ele;
        }
        else {                               // Elements in q1
            // Move all but last to q2
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();            // Last element
            q1.pop();
            return ele;
        }
    }
    
    int top() {
        if(empty()) return 0;
        else if(q1.empty()){
            return q2.back();                // Last added to q2
        }
        else {
            return q1.back();                // Last added to q1
        }
    }
};
```

**Two-Queue Stack Visualization:**
```
Push operations:
push(1): q1=[1], q2=[]
push(2): q1=[1,2], q2=[]
push(3): q1=[1,2,3], q2=[]

Pop operation (should return 3):
Move 1,2 to q2: q1=[3], q2=[1,2]
Pop 3 from q1: return 3, q1=[], q2=[1,2]

Push(4):
q1=[], q2=[1,2,4]

Pop operation (should return 4):
Move 1,2 to q1: q1=[1,2], q2=[4]
Pop 4 from q2: return 4, q1=[1,2], q2=[]
```

---

## 📊 Time & Space Complexity Analysis

### Printing Queue Elements
| Approach | Time | Space | Preserves Queue |
|----------|------|-------|----------------|
| Destructive | O(n) | O(1) | ❌ |
| Vector | O(n) | O(n) | ✅ |
| Circular | O(n) | O(1) | ✅ |

### Queue Reversal
| Method | Time | Space | Additional Structure |
|--------|------|-------|---------------------|
| Vector | O(n) | O(n) | Vector |
| Stack | O(n) | O(n) | Stack |

### Data Structure Implementations
| Operation | Queue using Stack | Stack using Queue |
|-----------|------------------|-------------------|
| Push | O(1) | O(1) |
| Pop | O(1) amortized* | O(n) |
| Peek/Top | O(1) amortized* | O(1) |

*Amortized: Occasionally O(n) when transferring between stacks

---

## 🎯 Key Takeaways

1. **Multiple Approaches**: Always consider trade-offs between time, space, and data preservation
2. **Circular Technique**: Efficient way to process queue elements without extra space
3. **Stack-Queue Duality**: Understanding how to implement one using the other
4. **Problem-Solving Patterns**: Queue problems often involve simulation and state management
5. **Optimization**: Choose approach based on specific requirements (space vs time vs preservation)

---
