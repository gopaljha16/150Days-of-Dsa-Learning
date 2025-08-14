# Heap Sort and Priority Queue Implementation in C++

## Overview

This collection of C++ code demonstrates the implementation of heap data structure operations including:
- **Max Heap Construction**: Building a max heap from an unsorted array
- **Min Heap Construction**: Building a min heap from an unsorted array  
- **Heap Sort Algorithm**: Sorting an array using heap sort technique
- **Priority Queue Usage**: Using STL priority queue for both max heap and min heap operations

The heap is a complete binary tree stored as an array, where each parent node satisfies the heap property (either greater than or less than its children).

---

## Code Breakdown

### 1. Max Heap Implementation

```cpp
#include <iostream>
using namespace std;

void Heapify (int arr[] , int index , int n){
    int largest = index;           // Assume current node is largest
    int leftChild = 2*index+1;     // Left child index
    int rightChild = 2*index+2;    // Right child index

    // Check if left child exists and is greater than current largest
    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    
    // Check if right child exists and is greater than current largest
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }

    // If largest is not the current index, swap and recursively heapify
    if(largest != index){
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void MaxHeap(int arr[], int n){
    // Start from last non-leaf node and heapify each node
    for(int i = n/2-1; i >= 0; i--){
        Heapify(arr, i, n);
    }
}
```

**Line-by-line explanation:**
- `int largest = index`: Initialize largest element index as current node
- `int leftChild = 2*index+1`: Calculate left child index using heap array formula
- `int rightChild = 2*index+2`: Calculate right child index using heap array formula
- First `if` statement: Check if left child exists and is larger than current largest
- Second `if` statement: Check if right child exists and is larger than current largest
- Final `if` statement: If heap property is violated, swap elements and recursively heapify the affected subtree

### 2. Min Heap Implementation

```cpp
void Heapify (int arr[] , int index , int n){
    int largest = index;           // Note: variable name is misleading, should be 'smallest'
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;

    // Check if left child is SMALLER than current node (min heap property)
    if(leftChild<n && arr[leftChild]<arr[largest]){
        largest = leftChild;
    }
    
    // Check if right child is SMALLER than current node (min heap property)
    if(rightChild<n && arr[rightChild]<arr[largest]){
        largest = rightChild;
    }

    if(largest != index){
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}
```

**Key difference from Max Heap:** The comparison operators are changed from `>` to `<` to maintain min heap property.

### 3. Heap Sort Implementation

```cpp
void sortArray(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);      // Move current largest to end
        Heapify(arr, 0, i);        // Heapify reduced heap
    }
}
```

**Heap Sort Process:**
1. Build a max heap from unsorted array
2. Repeatedly extract the maximum element (root) and place it at the end
3. Reduce heap size and re-heapify to maintain heap property

### 4. Priority Queue (STL Implementation)

```cpp
// Max Heap (default)
priority_queue<int> p;

// Min Heap (with custom comparator)
priority_queue<int, vector<int>, greater<int>> p;
```

---

## Array to Heap Visualization

### Heap Array Indexing
For any element at index `i`:
- **Left Child**: `2*i + 1`
- **Right Child**: `2*i + 2`
- **Parent**: `(i-1)/2`

```
Array: [70, 45, 62, 10, 2, 54, 6, 8, 3, 1]
Index:  0   1   2   3  4   5  6  7  8  9

Tree Representation:
                70(0)
              /       \
           45(1)      62(2)
          /    \      /    \
       10(3)  2(4) 54(5)  6(6)
       /  \   /
    8(7) 3(8) 1(9)
```

---

## Example Walkthrough

### Input Array: `{1, 2, 54, 3, 45, 62, 6, 8, 10, 70}`

#### Step 1: Build Max Heap

**Initial Array:**
```
[1, 2, 54, 3, 45, 62, 6, 8, 10, 70]
 0  1   2  3   4   5  6  7   8   9
```

**Heapify Process (Bottom-up approach):**

Starting from last non-leaf node: `n/2-1 = 10/2-1 = 4`

1. **Heapify index 4 (value 45):**
   - Left child: index 9 (value 70)
   - Right child: index 10 (doesn't exist)
   - 70 > 45, so swap positions 4 and 9
   - Array: `[1, 2, 54, 3, 70, 62, 6, 8, 10, 45]`

2. **Heapify index 3 (value 3):**
   - Left child: index 7 (value 8)
   - Right child: index 8 (value 10)
   - 10 > 8 > 3, so swap positions 3 and 8
   - Array: `[1, 2, 54, 10, 70, 62, 6, 8, 3, 45]`

3. **Heapify index 2 (value 54):**
   - Left child: index 5 (value 62)
   - Right child: index 6 (value 6)
   - 62 > 54, so swap positions 2 and 5
   - Array: `[1, 2, 62, 10, 70, 54, 6, 8, 3, 45]`

4. **Heapify index 1 (value 2):**
   - Left child: index 3 (value 10)
   - Right child: index 4 (value 70)
   - 70 > 10 > 2, so swap positions 1 and 4
   - Array: `[1, 70, 62, 10, 2, 54, 6, 8, 3, 45]`
   - Recursively heapify index 4: swap with index 9
   - Array: `[1, 70, 62, 10, 45, 54, 6, 8, 3, 2]`

5. **Heapify index 0 (value 1):**
   - Left child: index 1 (value 70)
   - Right child: index 2 (value 62)
   - 70 > 62 > 1, so swap positions 0 and 1
   - Array: `[70, 1, 62, 10, 45, 54, 6, 8, 3, 2]`
   - Recursively heapify index 1: swap with index 4
   - Array: `[70, 45, 62, 10, 1, 54, 6, 8, 3, 2]`
   - Recursively heapify index 4: swap with index 9
   - Final Array: `[70, 45, 62, 10, 2, 54, 6, 8, 3, 1]`

**Max Heap Result:** `[70, 45, 62, 10, 2, 54, 6, 8, 3, 1]`

#### Step 2: Heap Sort Process

1. **Iteration 1:** Swap 70 with 1, heapify with size 9
   - Array: `[1, 45, 62, 10, 2, 54, 6, 8, 3, 70]`
   - After heapify: `[62, 45, 54, 10, 2, 1, 6, 8, 3, 70]`

2. **Iteration 2:** Swap 62 with 3, heapify with size 8
   - Array: `[3, 45, 54, 10, 2, 1, 6, 8, 62, 70]`
   - After heapify: `[54, 45, 6, 10, 2, 1, 3, 8, 62, 70]`

3. **Continue until sorted...**

**Final Sorted Array:** `[1, 2, 3, 6, 8, 10, 45, 54, 62, 70]`

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Heapify | O(log n) | O(log n) recursion |
| Build Heap | O(n) | O(log n) |
| Heap Sort | O(n log n) | O(log n) |
| Priority Queue Insert | O(log n) | O(1) |
| Priority Queue Extract | O(log n) | O(1) |

---

## Example Inputs and Outputs

### Max Heap Construction
```
Input:  [1, 2, 54, 3, 45, 62, 6, 8, 10, 70]
Output: [70, 45, 62, 10, 2, 54, 6, 8, 3, 1]
```

### Min Heap Construction
```
Input:  [1, 2, 54, 3, 45, 62, 6, 8, 10, 70]
Output: [1, 2, 6, 3, 45, 62, 54, 8, 10, 70]
```

### Heap Sort
```
Input:  [1, 2, 54, 3, 45, 62, 6, 8, 10, 70]
Output: [1, 2, 3, 6, 8, 10, 45, 54, 62, 70]
```

### Priority Queue (Min Heap)
```
Input elements: 10, 30, 420, 45, 6, 1
Output sequence: 1 6 10 30 45 420
```

---

## Key Concepts

### Heap Properties
- **Max Heap**: Parent ≥ Children
- **Min Heap**: Parent ≤ Children
- **Complete Binary Tree**: All levels filled except possibly the last
- **Array Representation**: Efficient storage without pointers

### Applications
- **Priority Queues**: Task scheduling, Dijkstra's algorithm
- **Heap Sort**: In-place sorting algorithm
- **Selection Algorithms**: Finding kth largest/smallest elements

---

## Summary

This code demonstrates three fundamental heap operations:

1. **Heap Construction**: Converting an unsorted array into a heap using bottom-up heapify approach with O(n) time complexity
2. **Heap Sort**: An efficient O(n log n) sorting algorithm that works by repeatedly extracting the maximum element from a max heap
3. **Priority Queue**: STL implementation providing convenient heap operations for both max heap and min heap configurations

The key insight is that heaps provide efficient access to the maximum (or minimum) element while maintaining the heap property through the heapify operation. The array-based representation makes heaps memory-efficient and cache-friendly compared to pointer-based tree structures.

# Chatgpt Response 
# Day 96 — Heap Sort / Build Heap in C++ / Priority Queue

## Overview

This README explains four related C++ snippets that demonstrate:

* Building a **Max-Heap** from an array (`MaxHeap` + `Heapify`)
* Building a **Min-Heap** from an array (`MinHeap` + `Heapify`)
* Performing **Heap Sort** (in-place, O(n log n)) using a Max-Heap
* Using C++ STL **`priority_queue`** as a Max-Heap and Min-Heap

You’ll find:

* Section-wise (and key line-by-line) explanations
* Example inputs with expected outputs
* A detailed dry run of Heap Sort on a sample array
* ASCII diagrams for heap indexing and flowcharts for `Heapify`
* A quick complexity & gotchas summary

> **Note:** These are four **standalone programs**. Compile/run them separately (each has its own `main()`).

---

## 1) Build a Max-Heap from an Array

### Code: `max_heap_build.cpp`

```cpp
#include <iostream>
using namespace std;

// Sifts the element at `index` down the heap (range [0, n))
void Heapify (int arr[], int index, int n) {
    int largest = index;                // assume current index is largest
    int leftChild  = 2 * index + 1;     // 0-based left child
    int rightChild = 2 * index + 2;     // 0-based right child

    // If left child exists and is greater than current largest, update
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    // If right child exists and is greater than current largest, update
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // If either child was larger, swap and continue sifting down
    if (largest != index) {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);       // recursively fix affected subtree
    }
}

// Bottom-up heap construction (a.k.a. "step-down" or "sift-down" approach)
void MaxHeap(int arr[], int n) {
    // Only non-leaf nodes need heapify: from last parent down to root
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 54, 3, 45, 62, 6, 8, 10, 70};
    MaxHeap(arr, 10);
    print(arr, 10);
}
```

### What it does (section-wise)

* **`Heapify`**: Ensures the subtree rooted at `index` satisfies the **Max-Heap** property. Compares parent with children; if a child is larger, swap and recurse.
* **`MaxHeap`**: Builds a max-heap **bottom-up** by calling `Heapify` on all internal nodes from `n/2 - 1` down to `0`.
* **`print`**: Utility to print array contents.
* **`main`**: Builds a max-heap from the given array and prints the array **in heap order** (array representation of the heap, not sorted order).

### Example

**Input array:** `{1, 2, 54, 3, 45, 62, 6, 8, 10, 70}`
**Expected output (heap array):**

```
70 45 62 10 2 54 6 8 3 1
```

*(This is a valid max-heap array; values are not globally sorted, but every parent ≥ children.)*

### ASCII: Heap Indexing (0-based)

```
index:      0
          /   \
        1       2
      /  \     /  \
     3    4   5    6
    / \  / \
   7  8 9  10 (if exist)

left(i)  = 2*i + 1
right(i) = 2*i + 2
parent(i)= (i-1)/2
```

### Flowchart: `Heapify` (Max)

```
           +---------------------------+
           | Heapify(arr, index, n)    |
           +-------------+-------------+
                         |
                   largest = index
                         |
          +--------------+---------------+
          |                              |
  left=2i+1 < n ?                  right=2i+2 < n ?
          |                              |
    arr[left] > arr[largest]?       arr[right] > arr[largest]?
          |                              |
     largest=left                   largest=right
          \                              /
           +-------------+--------------+
                         |
                largest != index ?
                         |
            +------------+-----------+
            |                        |
         swap(arr[index], arr[largest])
                   |
               Heapify(arr, largest, n)
```

---

## 2) Build a Min-Heap from an Array

### Code: `min_heap_build.cpp`

```cpp
#include <iostream>
using namespace std;

void Heapify (int arr[], int index, int n) {
    int largest = index;                // name says 'largest', but it's used as 'smallest'
    int leftChild  = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && arr[leftChild] < arr[largest]) {
        largest = leftChild;            // actually tracking 'smallest'
    }
    if (rightChild < n && arr[rightChild] < arr[largest]) {
        largest = rightChild;           // actually tracking 'smallest'
    }

    if (largest != index) {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void MinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);             // builds Min-Heap
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 54, 3, 45, 62, 6, 8, 10, 70};
    MinHeap(arr, 10);
    print(arr, 10);
}
```

### Notes

* This is the **Min-Heap** version: comparisons use `<` so **parent ≤ children**.
* Variable name `largest` is a misnomer here—logically it tracks the **smallest** index. (It still works; just be aware.)

### Example

**Input array:** `{1, 2, 54, 3, 45, 62, 6, 8, 10, 70}`
**Expected output (heap array):**

```
1 2 6 3 45 62 54 8 10 70
```

*(Valid min-heap array; not globally sorted.)*

---

## 3) Heap Sort (Ascending) using a Max-Heap

### Code: `heap_sort.cpp`

```cpp
#include <iostream>
using namespace std;

void Heapify (int arr[], int index, int n) {
    int largest = index;
    int leftChild  = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void MaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// In-place heap sort (ascending)
void sortArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[0]);   // move current max to end
        Heapify(arr, 0, i);     // restore heap property on reduced heap [0, i)
    }
}

int main() {
    int arr[] = {1, 2, 54, 3, 45, 62, 6, 8, 10, 70};
    MaxHeap(arr, 10);           // build max-heap
    sortArray(arr, 10);         // sort ascending
    print(arr, 10);
}
```

### What it does

1. **Build a Max-Heap** (largest element at index 0).
2. **Repeatedly swap** the root with the last unsorted element.
3. **Shrink heap** by 1 and **heapify** the root to restore heap property.
4. The array becomes sorted **ascending**.

### Example

**Input array:** `{1, 2, 54, 3, 45, 62, 6, 8, 10, 70}`
**Expected output (sorted ascending):**

```
1 2 3 6 8 10 45 54 62 70
```

### Detailed Dry Run (Heap Sort on the example)

Array states (heap shown as array). `build` = after building the initial Max-Heap.

| Step            | Array state                                  |
| --------------- | -------------------------------------------- |
| build           | `[70, 45, 62, 10, 2, 54, 6, 8, 3, 1]`        |
| swap(0,9)       | `[1, 45, 62, 10, 2, 54, 6, 8, 3, 70]`        |
| heapify(size=9) | `[62, 45, 54, 10, 2, 1, 6, 8, 3, 70]`        |
| swap(0,8)       | `[3, 45, 54, 10, 2, 1, 6, 8, 62, 70]`        |
| heapify(size=8) | `[54, 45, 6, 10, 2, 1, 3, 8, 62, 70]`        |
| swap(0,7)       | `[8, 45, 6, 10, 2, 1, 3, 54, 62, 70]`        |
| heapify(size=7) | `[45, 10, 6, 8, 2, 1, 3, 54, 62, 70]`        |
| swap(0,6)       | `[3, 10, 6, 8, 2, 1, 45, 54, 62, 70]`        |
| heapify(size=6) | `[10, 8, 6, 3, 2, 1, 45, 54, 62, 70]`        |
| swap(0,5)       | `[1, 8, 6, 3, 2, 10, 45, 54, 62, 70]`        |
| heapify(size=5) | `[8, 3, 6, 1, 2, 10, 45, 54, 62, 70]`        |
| swap(0,4)       | `[2, 3, 6, 1, 8, 10, 45, 54, 62, 70]`        |
| heapify(size=4) | `[6, 3, 2, 1, 8, 10, 45, 54, 62, 70]`        |
| swap(0,3)       | `[1, 3, 2, 6, 8, 10, 45, 54, 62, 70]`        |
| heapify(size=3) | `[3, 1, 2, 6, 8, 10, 45, 54, 62, 70]`        |
| swap(0,2)       | `[2, 1, 3, 6, 8, 10, 45, 54, 62, 70]`        |
| heapify(size=2) | `[2, 1, 3, 6, 8, 10, 45, 54, 62, 70]`        |
| swap(0,1)       | `[1, 2, 3, 6, 8, 10, 45, 54, 62, 70]`        |
| heapify(size=1) | `[1, 2, 3, 6, 8, 10, 45, 54, 62, 70]` (done) |

---

## 4) `priority_queue` (STL) as Max-Heap and Min-Heap

### Code: `priority_queue_demo.cpp`

```cpp
#include <iostream>
#include <bits/stdc++.h> // non-standard, but available on many compilers
using namespace std;

int main() {
    // --------- Max-Heap (default) ----------
    // priority_queue<int> p; // largest element at top

    // p.push(10);
    // p.push(30);
    // p.push(420);
    // p.push(45);
    // p.push(6);
    // p.push(1);

    // cout << p.top() << " "; // prints current max (420)
    // p.pop();                // remove max
    // cout << p.top() << " "; // next max
    // cout << p.size() << " ";

    // while (!p.empty()) {
    //     cout << p.top() << " ";
    //     p.pop(); // prints in descending order
    // }

    // --------- Min-Heap using comparator ----------
    priority_queue<int, vector<int>, greater<int>> p; // smallest at top

    p.push(10);
    p.push(30);
    p.push(420);
    p.push(45);
    p.push(6);
    p.push(1);

    while (!p.empty()) {
        cout << p.top() << " "; // prints ascending
        p.pop();
    }
}
```

### What it does

* **Max-Heap (default)**: `priority_queue<int>` keeps the **largest** element at `top()`.
* **Min-Heap**: `priority_queue<int, vector<int>, greater<int>>` keeps the **smallest** element at `top()` using `greater<int>` comparator.

### Example (Min-Heap section active)

**Inserted:** `10, 30, 420, 45, 6, 1`
**Expected output:**

```
1 6 10 30 45 420
```

> ⚠️ Note: `#include <bits/stdc++.h>` is **non-standard** (works on GCC/Clang toolchains). Prefer individual headers in production (e.g., `<queue>`, `<vector>`, `<functional>`, `<iostream>`).

---

## Visuals & Intuition

### Max-Heap vs Min-Heap Property

```
Max-Heap: parent >= children       Min-Heap: parent <= children

     70                                1
   /    \                            /   \
  45     62                        2      6
 / \    /  \                     /  \    / \
10  2  54  6                   3   45  62  54
/ \                          / \
8  3                        8  10
```

---

## Complexity & Characteristics

| Operation                  | Time Complexity | Space | Notes                    |
| -------------------------- | --------------- | ----- | ------------------------ |
| Build heap (bottom-up)     | O(n)            | O(1)  | In-place                 |
| `Heapify` (single call)    | O(log n)        | O(1)  | Height of heap           |
| Heap Sort (full)           | O(n log n)      | O(1)  | **Not stable**, in-place |
| `priority_queue::push/pop` | O(log n)        | O(1)  | Top access is O(1)       |

**Edge cases & gotchas**

* Always check bounds: `leftChild < n`, `rightChild < n` (correct in provided code).
* For Min-Heap code, `largest` is a **name mismatch**; it actually tracks the smallest element.
* Heap Sort here produces **ascending** order by using a **Max-Heap**.
* Arrays are **0-based** indexed.

---

## Quick Reference: Example I/O Summary

| Program               | Input Array                               | Output                                       |
| --------------------- | ----------------------------------------- | -------------------------------------------- |
| Max-Heap build        | `{1,2,54,3,45,62,6,8,10,70}`              | `70 45 62 10 2 54 6 8 3 1`                   |
| Min-Heap build        | `{1,2,54,3,45,62,6,8,10,70}`              | `1 2 6 3 45 62 54 8 10 70`                   |
| Heap Sort (ascending) | `{1,2,54,3,45,62,6,8,10,70}`              | `1 2 3 6 8 10 45 54 62 70`                   |
| `priority_queue` min  | pushes `10,30,420,45,6,1` (in that order) | `1 6 10 30 45 420` (ascending while popping) |

---

## Summary

* **`Heapify`** is the fundamental operation: it fixes the heap property locally by sifting a node down.
* **`MaxHeap` / `MinHeap`** build heaps **bottom-up in O(n)** time.
* **Heap Sort** uses a **Max-Heap** to sort **ascending** in **O(n log n)** time, in-place (but **not stable**).
* STL **`priority_queue`** gives you a ready-to-use **Max-Heap** (default) or **Min-Heap** (with `greater<>`).
