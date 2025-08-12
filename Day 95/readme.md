# Day 95 C++ Heap Implementation: Max Heap and Min Heap

## Overview

This code demonstrates a complete implementation of both **Max Heap** and **Min Heap** data structures in C++. A heap is a complete binary tree that satisfies the heap property:
- **Max Heap**: Parent nodes are always greater than or equal to their children
- **Min Heap**: Parent nodes are always less than or equal to their children

The implementation includes core operations: insertion, deletion, and heapify (maintaining heap property).

## Table of Contents
- [Max Heap Implementation](#max-heap-implementation)
- [Min Heap Implementation](#min-heap-implementation)
- [Example Usage](#example-usage)
- [Step-by-Step Walkthrough](#step-by-step-walkthrough)
- [Visual Representation](#visual-representation)
- [Time Complexity](#time-complexity)

## Max Heap Implementation

### Class Structure

```cpp
class Maxheap {
    int *arr;       // Dynamic array to store heap elements
    int size;       // Current number of elements in heap
    int total_size; // Maximum capacity of the heap
};
```

### Constructor
```cpp
Maxheap(int n) {
    arr = new int[n];
    size = 0;
    total_size = n;
}
```
- Allocates dynamic memory for `n` elements
- Initializes size to 0 (empty heap)
- Sets maximum capacity

### Insert Operation

```cpp
void insert(int value) {
    // 1. Check for overflow
    if (size == total_size) {
        cout << "Heap Overflow";
        return;
    }
    
    // 2. Insert at the end
    arr[size] = value;
    int index = size;
    size++;
    
    // 3. Bubble up to maintain heap property
    while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
        swap(arr[(index - 1) / 2], arr[index]);
        index = (index - 1) / 2;
    }
}
```

**Key Points:**
- **Parent formula**: `(index - 1) / 2`
- **Bubble up**: Compare with parent and swap if needed
- **Heap property**: Parent ≥ Children

### Delete Operation

```cpp
void Delete() {
    // 1. Check for underflow
    if (size == 0) {
        cout << "Heap Underflow" << endl;
        return;
    }
    
    // 2. Replace root with last element
    arr[0] = arr[size - 1];
    size--;
    
    // 3. Heapify from root
    if (size > 0) {
        Heapify(0);
    }
}
```

### Heapify Operation

```cpp
void Heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;   // Left child formula
    int right = 2 * index + 2;  // Right child formula
    
    // Find largest among parent, left child, right child
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If largest is not the parent, swap and recurse
    if (largest != index) {
        swap(arr[index], arr[largest]);
        Heapify(largest);
    }
}
```

## Min Heap Implementation

The Min Heap follows the same structure as Max Heap with key differences:

### Insert Comparison
```cpp
// Max Heap: Parent should be greater
while (index > 0 && arr[(index - 1) / 2] < arr[index])

// Min Heap: Parent should be smaller
while (index > 0 && arr[(index - 1) / 2] > arr[index])
```

### Heapify Comparison
```cpp
// Max Heap: Find largest
if (left < size && arr[left] > arr[largest])

// Min Heap: Find smallest
if (left < size && arr[left] < arr[smallest])
```

## Example Usage

### Max Heap Example
```cpp
Maxheap h(6);
h.insert(10);  // [10]
h.insert(20);  // [20, 10]
h.insert(4);   // [20, 10, 4]
h.insert(50);  // [50, 20, 4, 10]
h.insert(200); // [200, 50, 4, 10, 20]
```

### Min Heap Example
```cpp
MinHeap h(6);
h.insert(10);  // [10]
h.insert(20);  // [10, 20]
h.insert(50);  // [10, 20, 50]
h.insert(1);   // [1, 10, 50, 20]
```

## Step-by-Step Walkthrough

### Max Heap Insertion: insert(50) into [20, 10, 4]

```
Initial state: [20, 10, 4]
      20
     /  \
   10    4

Step 1: Insert 50 at end
[20, 10, 4, 50]
      20
     /  \
   10    4
  /
 50

Step 2: Compare with parent (10)
50 > 10, so swap
[20, 50, 4, 10]
      20
     /  \
   50    4
  /
 10

Step 3: Compare with parent (20)
50 > 20, so swap
[50, 20, 4, 10]
      50
     /  \
   20    4
  /
 10

Final result: [50, 20, 4, 10]
```

### Max Heap Deletion Walkthrough

```
Initial: [200, 50, 4, 10, 20]
        200
       /   \
     50     4
    /  \
   10  20

Step 1: Replace root with last element
[20, 50, 4, 10]
        20
       /  \
     50    4
    /
   10

Step 2: Heapify from root
Compare 20 with children (50, 4)
50 is largest, swap with 20
[50, 20, 4, 10]
        50
       /  \
     20    4
    /
   10

Result: Max heap property restored
```

## Visual Representation

### Array to Tree Mapping
```
Array: [a, b, c, d, e, f]
Tree:
       a
      / \
     b   c
    / \ /
   d  e f

Index relationships:
- Parent of i: (i-1)/2
- Left child of i: 2*i+1
- Right child of i: 2*i+2
```

### Max Heap vs Min Heap
```
Max Heap:           Min Heap:
    50                  1
   /  \                / \
  20   4             10  50
 /                  /
10                 20
```

## Time Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert    | O(log n)       | O(1)            |
| Delete    | O(log n)       | O(1)            |
| Heapify   | O(log n)       | O(log n) - recursive |
| Peek      | O(1)           | O(1)            |

## Key Formulas

- **Parent Index**: `(i - 1) / 2`
- **Left Child**: `2 * i + 1`
- **Right Child**: `2 * i + 2`

## Expected Output

### Max Heap Program Output:
```
10 is inserted in the the heap 
20 is inserted in the the heap 
4 is inserted in the the heap 
50 is inserted in the the heap 
200 is inserted in the the heap 
200 50 4 10 20 
200 Delete from the heap
50 Delete from the heap
20 Delete from the heap
10 Delete from the heap
4 Delete from the heap
Heap Underflow

```

### Min Heap Program Output:
```
10 is inserted into the minheap
20 is inserted into the minheap
50 is inserted into the minheap
1 is inserted into the minheap
1 10 50 20 
1 Is Deleted from the heap
10 50 20 
10 Is Deleted from the heap
20 50 
```

## Summary

This implementation demonstrates:

1. **Dynamic Memory Management**: Using arrays to represent complete binary trees
2. **Heap Property Maintenance**: Through bubble-up (insertion) and bubble-down (heapify) operations
3. **Efficient Operations**: All major operations run in O(log n) time
4. **Two Variants**: Max heap for priority queues, Min heap for finding minimums
5. **Complete Implementation**: Including edge cases like overflow/underflow handling


# Chatgpt response
# Day 95 — Heaps (MaxHeap & MinHeap) — introduction, insertion & deletion

## Overview

This README explains two C++ classes that implement binary heaps using a raw array:

* `Maxheap` — a **max-heap** (parent ≥ children). Supports `insert`, `Delete` (remove root), `print`, and `Heapify`.
* `MinHeap` — a **min-heap** (parent ≤ children). Same API and logic but with reversed comparisons.

I'll walk through the code section-wise, show example "inputs" (the sequences used in `main`) and the exact console outputs, do a step-by-step dry run for one example (detailed array + tree diagrams), highlight complexity and edge-cases, and finish with suggested improvements.

---

## MaxHeap — code + explanation

> Full C++ snippet (as provided)

```cpp
#include <iostream>
using namespace std;

class Maxheap
{
    int *arr;       // the array
    int size;       // total element in the heap
    int total_size; // total size of the array..

public:
    // constructor
    Maxheap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insert into the heap
    void insert(int value)
    {
        // edge cases size
        if (size == total_size)
        {
            cout << "Heap Overflow";
            return;
        }

        // insert element value inserted on index and then index ka size badha diya
        arr[size] = value;
        int index = size;
        size++;

        // element at the correct position compare with the parent
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2; // update the index;
        }
        cout << arr[index] << " is inserted in the the heap " << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // now here the largest will be store the index of the element which is greater betweeen parent , and left child and right child
        if (left < size && arr[left] > arr[largest])
        { // if left is big then replace with the largest
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        { // if right is the big then replace with the largest
            largest = right;
        }

        // so here if the largest value is changed then
        if (largest != index)
        {
            swap(arr[index], arr[largest]); // then swap it with the index;
            Heapify(largest);
        }
    }

    void Delete()
    {
        // value check
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }

        // delete
        cout << arr[0] << " Delete from the heap"<<endl;
        arr[0] = arr[size - 1]; // last index replace karna hai
        size--;                 // size decrease..

        if (size == 0)
        { // if size is 0;
            return;
        }

        Heapify(0);
    }
};

int main()
{
    Maxheap h(6);
    h.insert(10);
    h.insert(20);
    h.insert(4);
    h.insert(50);
    h.insert(200);
    h.print();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.print();
}
```

### Data members

* `int *arr;` — raw array storing heap elements (array-based binary heap).
* `int size;` — current number of elements stored.
* `int total_size;` — capacity allocated for the array.

> Note: `new` is used but there's **no destructor** — this causes a memory leak in longer-running programs. Later I suggest improvements.

### Constructor

```cpp
Maxheap(int n) {
    arr = new int[n];
    size = 0;
    total_size = n;
}
```

* Allocates `n` integers and initializes `size = 0`.

### `insert(int value)` — percolate-up to keep max-heap property

1. If `size == total_size` print `"Heap Overflow"` and return.
2. Place `value` at `arr[size]`, set `index = size`, then `size++`.
3. While `index > 0` and `parent < current`, swap with parent:

   * parent index = `(index - 1) / 2`
   * condition: `arr[parent] < arr[index]` (because this is max-heap).
4. Continue until new element reaches correct position.
5. Print message: `{arr[index]} is inserted in the the heap`.

Complexity: O(log n) per insert (height of heap).

### `print()` — array order (level-order)

* Iterates `i = 0..size-1` and prints `arr[i]` separated by spaces.
* Important: *this function does not print a newline* — so the next `cout` will continue on the same console line unless it prints an `endl`.

### `Heapify(int index)` — percolate-down (used during delete)

1. Compute children: `left = 2*index + 1`, `right = 2*index + 2`.
2. Find `largest` among `index`, `left`, and `right`.
3. If `largest != index`, swap `arr[index]` and `arr[largest]`, then recursively `Heapify(largest)`.

* This restores the max-heap property for the subtree rooted at `index`.

Complexity: O(log n).

### `Delete()` — remove root (maximum)

1. If `size == 0` print `"Heap Underflow"` and return.
2. Print `arr[0]` as deleted.
3. Replace `arr[0]` with last element `arr[size-1]`, `size--`.
4. If size becomes 0 after decrement, return (nothing to heapify).
5. Call `Heapify(0)` to restore max-heap property.

Complexity: O(log n) (heapify).

---

## MinHeap — code + explanation

> Full C++ snippet (as provided)

```cpp
#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insert
    void insert(int value)
    {
        // check is size
        if (size == total_size)
        {
            cout << "Heap overflow" << endl;
            return;
        }

        // value insert
        arr[size] = value;
        int index = size;
        size++;

        // comapring and making fixing means here it should min element top meh hoona chaiye
        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted into the minheap" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Heapify(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // left
        if (left < size && arr[left] < arr[smallest])
        {
            smallest = left;
        }

        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            Heapify(smallest);
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap underflow" << endl;
            return;
        }

        // delete
        cout << arr[0] << " Is Deleted from the heap" << endl;
        arr[0] = arr[size - 1]; // last element
        size--;

        if (size == 0)
            return;

        Heapify(0);
    }
};

int main()
{
    MinHeap h(6);
    h.insert(10);
    h.insert(20);
    h.insert(50);
    h.insert(1);
    h.print();
    h.Delete();
    h.print();
    h.Delete();
    h.print();
}
```

### Differences vs `Maxheap`

* Condition in insertion percolate-up is `parent > current` (so smaller values bubble up).
* `Heapify` chooses `smallest` child in percolate-down.
* Print ends with `endl` (so lines are separated in output).

Complexities same as `Maxheap`.

---

## Example inputs and expected outputs

> These are the sequences used in the provided `main()` functions. I show the outputs **in the order they are printed**.

### Example A — MaxHeap (`Maxheap h(6);`)

Operations performed:

```text
insert(10)
insert(20)
insert(4)
insert(50)
insert(200)
print()
Delete()  // called 6 times
print()
```

**Exact console output (chronological):**

```
10 is inserted in the the heap 
20 is inserted in the the heap 
4 is inserted in the the heap 
50 is inserted in the the heap 
200 is inserted in the the heap 
200 50 4 10 20
200 Delete from the heap
50 Delete from the heap
20 Delete from the heap
10 Delete from the heap
4 Delete from the heap
Heap Underflow
```

> Note: The `print()` method in `Maxheap` does not print a newline; the sequence above shows the printed array followed by subsequent `Delete()` messages on new lines for clarity (the `Delete()` calls print `endl`).

---

### Example B — MinHeap (`MinHeap h(6);`)

Operations performed:

```text
insert(10)
insert(20)
insert(50)
insert(1)
print()
Delete()
print()
Delete()
print()
```

**Exact console output (chronological):**

```
10 is inserted into the minheap
20 is inserted into the minheap
50 is inserted into the minheap
1 is inserted into the minheap
1 10 50 20
1 Is Deleted from the heap
10 20 50
10 Is Deleted from the heap
20 50
```

---

## Detailed dry-run (step-by-step) — MaxHeap example

We'll trace the MaxHeap example in detail for each insertion and deletion. I'll show the array representation and a small ASCII tree (level order).

**Initial state**

* `arr = [ ]` (size = 0)

---

### Insert 10

* Put 10 at index 0.
* index = 0 → no percolation (root).
* arr: `[10]` (size=1)

ASCII tree:

```
Index: 0
Value: 10
Tree:
    10
```

---

### Insert 20

* Place 20 at index 1.
* Parent index = (1-1)/2 = 0 → arr\[0]=10 < arr\[1]=20 → swap.
* index becomes 0 → stop.
* arr: `[20, 10]` (size=2)

Tree:

```
      20
     /
   10
Array: index0=20, index1=10
```

---

### Insert 4

* Place 4 at index 2.
* Parent index = 0 → arr\[0]=20 < 4 ? No → stop.
* arr: `[20, 10, 4]` (size=3)

Tree:

```
      20
     /  \
   10    4
```

---

### Insert 50

* Place 50 at index 3.
* Parent index = 1 → arr\[1]=10 < 50 → swap → index → 1
* New parent index = 0 → arr\[0]=20 < 50 → swap → index → 0
* arr: `[50, 20, 4, 10]` (size=4)

Tree:

```
        50
       /  \
     20    4
    /
  10
Array indices: [50,20,4,10]
```

---

### Insert 200

* Place 200 at index 4.
* Parent index = 1 → arr\[1]=20 < 200 → swap → index -> 1
* Parent index = 0 → arr\[0]=50 < 200 → swap → index -> 0
* arr: `[200, 50, 4, 10, 20]` (size=5)

Tree:

```
          200
         /   \
       50     4
      /  \
    10   20
Array: index0=200,1=50,2=4,3=10,4=20
```

**After initial `print()`** (level order array):

```
200 50 4 10 20
```

---

### Delete 1 (remove root)

* Deleted value: `200` (printed)
* Replace `arr[0]` with last element `arr[4]` (=20), size→4 → arr `[20,50,4,10]`
* `Heapify(0)`:

  * left=1 (50) right=2 (4): largest is left (50). swap index0 and index1 → `[50,20,4,10]`
  * Heapify(1): left=3 (10) right=4 (out): 10 < 20 → done.
* Final arr: `[50,20,4,10]`

Output line printed:

```
200 Delete from the heap
```

Tree after delete:

```
      50
     /  \
   20    4
  /
10
```

---

### Delete 2

* Deleted: `50` (printed)
* Replace arr\[0] with last element arr\[3] (10) → `[10,20,4]`, size→3
* Heapify(0): left=1 (20) right=2 (4) → largest = left (20) → swap → `[20,10,4]`
* Done.

Output:

```
50 Delete from the heap
```

Tree:

```
    20
   /  \
 10    4
```

---

### Delete 3

* Deleted: `20` (printed)
* Replace root with last arr\[2]=4 → `[4,10]`, size→2
* Heapify(0): left=1 (10) → largest=1 → swap → `[10,4]`
* Done.

Output:

```
20 Delete from the heap
```

Tree:

```
   10
  /
 4
```

---

### Delete 4

* Deleted: `10` (printed)
* Replace root with last arr\[1]=4 → `[4]`, size→1
* Heapify(0): children out of bounds → nothing
* Done.

Output:

```
10 Delete from the heap
```

---

### Delete 5

* Deleted: `4` (printed)
* Replace root with last arr\[0]=4 then size→0 → because size becomes 0, function returns early (no Heapify)
* Arr empty.

Output:

```
4 Delete from the heap
```

---

### Delete 6 (attempt to delete from empty heap)

* size == 0 → prints:

```
Heap Underflow
```

**Final `print()`** prints nothing (heap empty).

---

## Visual summary: array ↔ tree mapping (max-heap after first five inserts)

Array: `arr = [200, 50, 4, 10, 20]`

Index mapping:

```
index:  0    1   2   3   4
value: 200  50   4  10  20
```

Tree:

```
         arr[0] (200)
         /        \
    arr   arr
     /    \
 arr[3]  arr[4]
 (10)    (20)
```

Parent/child formulas:

* parent(i) = (i−1)/2
* left(i) = 2\*i + 1
* right(i) = 2\*i + 2

---

## Complexity & properties

* **Space:** O(n) array used.
* **Insertion:** O(log n) worst-case (percolate up).
* **Delete (root):** O(log n) worst-case (percolate down via `Heapify`).
* **Peek (root)**: O(1) — not implemented but trivial: return `arr[0]`.
* The array representation gives level-order traversal directly.

---

## Edge cases & gotchas in this implementation

1. **Memory leak:** `new int[n]` is used but there is **no destructor** (`delete[] arr;`). Add a destructor to avoid leak.
2. **No bounds checks for `print()` formatting:** `Maxheap::print()` doesn't output a newline (`endl`) — output formatting may be confusing.
3. **No `peek()` method** to view root without deleting — easy to add.
4. **`Delete()` messages/text mismatch**: MinHeap prints `"Is Deleted..."` and MaxHeap prints `"Delete from..."` — consider consistent messaging.
5. **No resizing:** capacity is fixed; if overflow occurs, user gets `"Heap Overflow"` but no dynamic growth. Consider using `std::vector<int>` and `push_back` and `reserve()`/`resize()` for automatic reallocation.
6. **No copy constructor/assignment operator** — raw pointer usage can lead to double-free or shallow-copy bugs if objects are copied. Use `std::vector` or implement Rule of Three/Five.

---

## Suggested improvements (quick list)

* Use `std::vector<int>` instead of raw `new`/pointer.
* Add `~Maxheap()` and `~MinHeap()` to `delete[] arr;` (if keeping raw pointer).
* Add methods: `peek()`, `isEmpty()`, `getSize()`.
* Provide `buildHeap` (heapify all elements in O(n) from an array).
* Consider using `std::priority_queue` for production (max-heap by default).
* Make consistent logging and add newline after `print()` in Maxheap.

---

## Final summary

* The provided code implements array-based MaxHeap and MinHeap with `insert` (percolate up), `Delete` (remove root + percolate down / Heapify), and `print`.
* Use-cases: priority queues, scheduling, heapsort (with extra logic), median-finding structures.
* Complexity: O(log n) for insert/delete, O(1) for peek.
* I gave a full dry-run of the MaxHeap example with array and tree diagrams so you can **see exactly** how elements move on each operation.
* If you want, I can:

  * Convert the classes to use `std::vector` and add destructor/peek/isEmpty methods.
  * Add `buildHeap` (O(n) construction from an unsorted array).
  * Provide a single-file, refactored, production-ready version (with tests). Which next?
