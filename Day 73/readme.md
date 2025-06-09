# 🎯 Day 73: Queues with Sliding Window Problems


> **Master the art of sliding window technique using queues to solve complex array problems efficiently!**

## 📚 Table of Contents
- [🔍 Overview](#-overview)
- [🏗️ Basic Sliding Window Implementation](#️-basic-sliding-window-implementation)
- [🎯 Problem 1: First Negative in Every Window](#-problem-1-first-negative-in-every-window)
- [🔤 Problem 2: First Non-Repeating Character in Stream](#-problem-2-first-non-repeating-character-in-stream)
- [⚡ Time & Space Complexity](#-time--space-complexity)
- [🎨 Visual Flow Diagrams](#-visual-flow-diagrams)
- [🧠 Key Takeaways](#-key-takeaways)

---

## 🔍 Overview

The **Sliding Window** technique with queues is a powerful approach for processing arrays in fixed-size windows. It maintains optimal time complexity by avoiding redundant calculations and leveraging queue's FIFO property.

### 🎯 **Core Concept**
```
Array: [3, 6, 7, 8, 9, 3, 2]
Window Size: 3

Windows:
[3, 6, 7] → [6, 7, 8] → [7, 8, 9] → [8, 9, 3] → [9, 3, 2]
```

---

## 🏗️ Basic Sliding Window Implementation

### 💻 **Code Structure**

```cpp
#include <iostream>
#include <queue>
using namespace std;

void display(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    int arr[] = {3,6,7,8,9,3,2};
    int n = 7;
    int k = 3; // Window size
    queue<int>q;
    
    // 🔸 Phase 1: Pre-fill first k-1 elements
    for(int i=0 ; i<k-1 ; i++){
        q.push(arr[i]);
    }

    // 🔸 Phase 2: Slide the window
    for(int i=k-1 ; i<n ;i++){
        q.push(arr[i]);    // Add new element
        display(q);        // Process current window
        q.pop();          // Remove oldest element
    }
    return 0;
}
```

### 📊 **Execution Flow Diagram**

```
Array: [3, 6, 7, 8, 9, 3, 2]
       ↑  ↑  ↑  ↑  ↑  ↑  ↑
       0  1  2  3  4  5  6

Phase 1: Pre-fill (k-1 = 2 elements)
┌─────────────────────────────────┐
│ i=0: Queue = [3]                │
│ i=1: Queue = [3, 6]             │
└─────────────────────────────────┘

Phase 2: Sliding Window
┌─────────────────────────────────┐
│ i=2: Push(7) → [3,6,7] → Pop(3) │ ✅ Window: [3,6,7]
│ i=3: Push(8) → [6,7,8] → Pop(6) │ ✅ Window: [6,7,8]
│ i=4: Push(9) → [7,8,9] → Pop(7) │ ✅ Window: [7,8,9]
│ i=5: Push(3) → [8,9,3] → Pop(8) │ ✅ Window: [8,9,3]
│ i=6: Push(2) → [9,3,2] → Pop(9) │ ✅ Window: [9,3,2]
└─────────────────────────────────┘
```

### 🔍 **Pseudocode**
```
ALGORITHM: BasicSlidingWindow
INPUT: arr[], n, k
OUTPUT: All windows of size k

1. INITIALIZE queue q
2. FOR i = 0 to k-2:
   - PUSH arr[i] to q
3. FOR i = k-1 to n-1:
   - PUSH arr[i] to q
   - DISPLAY current window
   - POP front element from q
```

---

## 🎯 Problem 1: First Negative in Every Window

> **Problem**: Find the first negative number in every window of size k.

### 🚫 **Approach 1: Brute Force (TLE - O(nk))**

```cpp
class Solution {
public:
    int printNegative(queue<int>q){
        while(!q.empty()){
            if(q.front()<0)
                return q.front();
            q.pop();
        }
        return 0; // No negative element
    }
    
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int>q;
        vector<int>ans;
        int n = arr.size();
        
        // Pre-fill k-1 elements
        for(int i=0 ; i<k-1 ; i++){
           q.push(arr[i]);
        }
        
        // Slide window and find first negative
        for(int i=k-1 ; i<n ; i++){
            q.push(arr[i]);
            ans.push_back(printNegative(q)); // O(k) operation
            q.pop();
        }
        
        return ans;
    }
};
```

### ⚡ **Approach 2: Optimized (O(n))**

```cpp
class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        queue<int>q; // Store indices of negative numbers
        vector<int>ans;
        
        // 🔸 Phase 1: Pre-fill negative indices in first k-1 elements
        for(int i=0 ; i<k-1 ; i++){
            if(arr[i]<0){ 
                q.push(i); // Store index, not value
            }
        }
        
        // 🔸 Phase 2: Slide window
        for(int i=k-1 ; i<n ; i++){
            // Add current element if negative
            if(arr[i]<0){ 
                q.push(i);
            }
            
            // Remove indices outside current window
            if(!q.empty() && q.front() <= i-k){
                q.pop();
            }
            
            // Get result for current window
            if(q.empty()){ 
                ans.push_back(0); // No negative number
            }else{ 
                ans.push_back(arr[q.front()]); // First negative
            }
        }
        
        return ans;
    }
};
```

### 📊 **Visual Example**
```
Array: [-8, 2, 3, -6, 10], k=2

Window [0,1]: [-8, 2]  → First negative: -8 ✅
Window [1,2]: [2, 3]   → First negative: 0  ❌
Window [2,3]: [3, -6]  → First negative: -6 ✅
Window [3,4]: [-6, 10] → First negative: -6 ✅

Queue operations:
┌─────────────────────────────────────────┐
│ i=0: arr[-8]<0 → q=[0]                  │
│ i=1: arr[2]≥0 → q=[0] → ans=[-8]        │
│ i=2: arr[3]≥0 → q=[] → ans=[-8,0]       │
│ i=3: arr[-6]<0 → q=[3] → ans=[-8,0,-6]  │
│ i=4: arr[10]≥0 → q=[3] → ans=[-8,0,-6,-6]│
└─────────────────────────────────────────┘
```

### 🔍 **Pseudocode**
```
ALGORITHM: FirstNegativeInWindow
INPUT: arr[], k
OUTPUT: First negative in each window

1. INITIALIZE queue q (for indices), vector ans
2. FOR i = 0 to k-2:
   - IF arr[i] < 0: PUSH i to q
3. FOR i = k-1 to n-1:
   - IF arr[i] < 0: PUSH i to q
   - WHILE q not empty AND q.front() <= i-k:
     - POP from q
   - IF q empty: APPEND 0 to ans
   - ELSE: APPEND arr[q.front()] to ans
4. RETURN ans
```

---

## 🔤 Problem 2: First Non-Repeating Character in Stream

> **Problem**: For each character in a stream, find the first non-repeating character seen so far.

### 💻 **Implementation**

```cpp
string Solution::solve(string A) {
    string result = "";
    vector<int> frequency(26, 0); // Character frequency counter
    queue<char> q; // Queue for potential non-repeating chars
    
    for(int i = 0; i < A.size(); i++){
        char currentChar = A[i];
        
        // 🔸 Update frequency
        frequency[currentChar - 'a']++;
        
        // 🔸 Add to queue if first occurrence
        if(frequency[currentChar - 'a'] == 1){
            q.push(currentChar);
        }
        
        // 🔸 Remove repeating characters from front
        while(!q.empty() && frequency[q.front() - 'a'] > 1){
            q.pop();
        }
        
        // 🔸 Get first non-repeating character
        if(q.empty()){
            result += "#"; // No non-repeating character
        } else {
            result += q.front(); // First non-repeating
        }
    }
    
    return result;
}
```

### 📊 **Step-by-Step Example**
```
Input: "aabc"

Processing:
┌─────────────────────────────────────────────────────────┐
│ i=0: char='a', freq[a]=1, q=['a'], result="a"          │
│ i=1: char='a', freq[a]=2, q=[], result="a#"            │
│ i=2: char='b', freq[b]=1, q=['b'], result="a#b"        │
│ i=3: char='c', freq[c]=1, q=['b','c'], result="a#bb"   │
└─────────────────────────────────────────────────────────┘

Final Result: "a#bb"
```

### 🔄 **Flow Diagram**
```
Stream: a → a → b → c

Step 1: 'a' arrives
freq: [1,0,0,...] 
queue: [a] 
result: "a"

Step 2: 'a' arrives again  
freq: [2,0,0,...]
queue: [] (a removed as freq[a]>1)
result: "a#"

Step 3: 'b' arrives
freq: [2,1,0,...]
queue: [b]
result: "a#b"

Step 4: 'c' arrives  
freq: [2,1,1,...]
queue: [b,c]
result: "a#bb" (b is still first non-repeating)
```

### 🔍 **Pseudocode**
```
ALGORITHM: FirstNonRepeatingInStream
INPUT: string A
OUTPUT: string result

1. INITIALIZE result="", frequency[26]={0}, queue q
2. FOR each character c in A:
   - INCREMENT frequency[c]
   - IF frequency[c] == 1: PUSH c to q
   - WHILE q not empty AND frequency[q.front()] > 1:
     - POP from q
   - IF q empty: APPEND "#" to result
   - ELSE: APPEND q.front() to result
3. RETURN result
```

---

## ⚡ Time & Space Complexity

| Problem | Approach | Time | Space | Notes |
|---------|----------|------|-------|-------|
| Basic Sliding Window | Queue | O(n) | O(k) | Each element pushed/popped once |
| First Negative (Brute) | Queue | O(nk) | O(k) | Check each window separately |
| First Negative (Optimized) | Index Queue | O(n) | O(k) | Store indices, not values |
| Non-Repeating Stream | Queue + Array | O(n) | O(26) = O(1) | Constant space for alphabet |

---

## 🎨 Visual Flow Diagrams

### 🔄 **Sliding Window Mechanism**
```
Initial: [•][•][•][4][5][6][7]
         └─────k=3─────┘

Step 1:  [1][•][•][•][5][6][7]
         └─────k=3─────┘

Step 2:  [1][2][•][•][•][6][7]  
         └─────k=3─────┘

Step 3:  [1][2][3][•][•][•][7]
         └─────k=3─────┘
```

### 📊 **Queue State Changes**
```
Queue Operations Visualization:

PUSH(3) → [3]
PUSH(6) → [3,6]  
PUSH(7) → [3,6,7] → DISPLAY → POP() → [6,7]
PUSH(8) → [6,7,8] → DISPLAY → POP() → [7,8]  
PUSH(9) → [7,8,9] → DISPLAY → POP() → [8,9]
```

---

## 🧠 Key Takeaways

### ✅ **Best Practices**
- **Store indices instead of values** when you need to track positions
- **Use frequency arrays** for character-based problems
- **Clean up queue** by removing invalid/expired elements
- **Two-phase approach**: Pre-fill + Slide for optimal performance

### 🎯 **Common Patterns**
1. **Index Storage**: Store array indices in queue for position tracking
2. **Lazy Cleanup**: Remove invalid elements only when needed
3. **Frequency Tracking**: Use arrays/maps to track element occurrences
4. **Early Termination**: Stop processing when window constraints are violated

### 🚀 **Optimization Tips**
- Avoid copying entire windows - use pointers/indices
- Clean up data structures proactively to prevent memory bloat  
- Consider deque when you need both front and back operations
- Use const references to avoid unnecessary copying

---

## 🔗 **Related Topics**
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

---
