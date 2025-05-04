Here’s the complete, deeply explained note for **Day 53: Deletion in Singly Linked List and Deletion in Constant Time**, including:

1. ✅ Full working code for:

   * Deleting first node
   * Deleting last node
   * Deleting a node at a given position
   * Deleting in constant time (without head pointer)
2. 📘 Paragraph-wise detailed explanation of every line
3. 🔁 Flowchart for each deletion case
4. ⚔️ Comparison of deletion time: Array vs Linked List

---

## 🔹 1. Create Singly Linked List Class & Utility

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* CreateLinkedList(int arr[], int index, int size) {
    // Base case: Stop recursion when index reaches array size
    if(index == size) return NULL;

    // Create a node with current array value
    Node* temp = new Node(arr[index]);

    // Recursively attach the next node
    temp->next = CreateLinkedList(arr, index + 1, size);

    return temp;
}
```

### 🔍 Explanation:

* `Node` class defines a structure with `data` and pointer `next`.
* `CreateLinkedList` recursively creates nodes using array values.
* Base condition ends recursion.
* Every `temp->next` attaches the next node.

---

## 🔹 2. Delete First Node

```cpp
if(Head != NULL) {
    Node* temp = Head;       // Store the head
    Head = Head->next;       // Move head to next node
    delete temp;             // Delete the old head
}
```

### 🔍 Explanation:

* Safe-guard with `Head != NULL`.
* Temporarily store the current `Head`.
* Move `Head` forward by one.
* Delete the old node to prevent memory leak.

### 🔄 Flowchart:

```
START --> Head != NULL? --> Store temp = Head
                         --> Head = Head->next
                         --> delete temp
                         --> END
```

---

## 🔹 3. Delete Last Node

```cpp
if(Head != NULL) {
    if(Head->next == NULL) {
        delete Head;
        Head = NULL;
    } else {
        Node* prev = NULL;
        Node* curr = Head;

        while(curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }

        delete curr;
        prev->next = NULL;
    }
}
```

### 🔍 Explanation:

* If there’s only one node, delete `Head`.
* Else, traverse till the last node using `curr`, while storing `prev`.
* Once `curr` reaches the end:

  * Delete `curr`
  * Point `prev->next` to `NULL`.

### 🔄 Flowchart:

```
START --> Head != NULL?
        --> Head->next == NULL?
            --> delete Head --> Head = NULL
        --> ELSE
            --> while(curr->next != NULL)
                  --> prev = curr
                  --> curr = curr->next
            --> delete curr
            --> prev->next = NULL
```

---

## 🔹 4. Delete Node at Specific Position (e.g., 3rd)

```cpp
int x = 3;
if(x == 1) {
    Node* temp = Head;
    Head = Head->next;
    delete temp;
} else {
    x--;
    Node* curr = Head;
    Node* prev = NULL;
    while(x--) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}
```

### 🔍 Explanation:

* If position is 1, delete head directly.
* Else, decrement `x` so that we stop one node before the one to delete.
* Traverse using loop, track `prev` and `curr`.
* After traversal:

  * Link `prev->next = curr->next`
  * Delete `curr`.

---

## 🔹 5. GFG Version: Recursive Delete at Position

```cpp
Node* deleteNode(Node* curr, int x) {
    if(x == 1) {
        Node* temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deleteNode(curr->next, x - 1);
    return curr;
}
```

### 🔍 Explanation:

* Recursively traverse till position `x`.
* Once `x == 1`, delete current node.
* Recursively update the `next` pointer.
* Elegant recursive approach.

---

## 🔹 6. Delete Without Head Pointer (Constant Time)

```cpp
void deleteNode(Node* curr) {
    Node* temp = curr->next;
    curr->data = temp->data;
    curr->next = temp->next;
    delete temp;
}
```

### ✅ Works in O(1) time (but **not** if node is last)

### 🔍 Explanation:

* You cannot move backward in singly linked list.
* Trick: copy `data` of next node to current.
* Point `curr->next` to next of next node.
* Delete the original next node.

---

## 🔸 Array vs Linked List Deletion ⏱️

| Operation               | Array                     | Linked List                          |
| ----------------------- | ------------------------- | ------------------------------------ |
| Delete first element    | O(n) (shift all elements) | O(1) (just move head)                |
| Delete last element     | O(1) (if size known)      | O(n) (need to traverse to last node) |
| Delete at index `i`     | O(n) (shift after `i`)    | O(n) (traverse to node `i-1`)        |
| Delete in constant time | ❌ Not possible            | ✅ Possible if pointer to node given  |
| Memory Usage            | Contiguous                | Non-contiguous (more dynamic)        |

---

## 🧠 Example Dry Run

### Input:

```cpp
int arr[] = {10, 20, 30, 40};
```

### Create Linked List:

```
10 -> 20 -> 30 -> 40 -> NULL
```

### Delete at position 3:

* `prev = 20`, `curr = 30`
* `prev->next = 40`
* Delete 30

### Final List:

```
10 -> 20 -> 40 -> NULL
```

---

## 📌 Summary

* Deletion in linked list can be O(1) or O(n) depending on location.
* Recursive and iterative deletions both valid.
* Deletion without head is a trick for O(1) time but has edge cases.
* Arrays need element shifting—costly!
* Linked list is optimal for frequent insertion/deletion.

---

