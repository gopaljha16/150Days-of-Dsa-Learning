Here are your **Day 56 Notes: Introduction to Doubly Linked List (DLL) — Insertion & Deletion** — explained in a GitHub-style markdown format, with code walk-through, diagrams, and detailed concepts.

---

# 📘 Day 56: Doubly Linked List – Insertion and Deletion

A **Doubly Linked List (DLL)** is a linear data structure where each node contains:

* `data`: the value
* `next`: pointer to the next node
* `prev`: pointer to the previous node

This allows **bidirectional traversal**.

---

## 🔁 Structure of a DLL Node

```cpp
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};
```

---

## 📌 Insertion Operations in DLL

### ✅ 1. Insertion at Start

#### 🧠 Logic:

* If list is empty, directly assign `head = new Node(val)`.
* Else:

  * Create new node.
  * Set `newNode->next = head` and `head->prev = newNode`.
  * Update `head = newNode`.

#### 🧾 Code:

```cpp
Node* head = NULL;
if (head == NULL) {
    head = new Node(5);
} else {
    Node* temp = new Node(5);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
```

---

### ✅ 2. Insertion at End

#### 🧠 Logic:

* Traverse to last node.
* Create new node and link its `prev` to current last.
* Update current's `next` to new node.

#### 🧾 Code:

```cpp
Node* head = NULL;
if (head == NULL) {
    head = new Node(5);
} else {
    Node* curr = head;
    while (curr->next != NULL) curr = curr->next;

    Node* temp = new Node(5);
    curr->next = temp;
    temp->prev = curr;
}
```

---

### ✅ 3. Insertion at Given Position (Middle)

#### 🧠 Logic:

* Traverse to node just before the desired position.
* Create new node and adjust `next` and `prev` pointers accordingly.
* Handle 3 cases:

  * Insert at start
  * Insert at end
  * Insert in middle

#### 🧾 Code:

```cpp
int pos = 2;
Node* curr = head;
while (--pos) curr = curr->next;

Node* temp = new Node(5);

if (curr->next == NULL) { // Insert at end
    temp->prev = curr;
    curr->next = temp;
} else { // Insert in middle
    temp->next = curr->next;
    temp->prev = curr;
    curr->next = temp;
    temp->next->prev = temp;
}
```

---

## ❌ Deletion Operations in DLL

### 🧹 1. Delete from Start

#### 🧠 Logic:

* If only one node, delete and make `head = NULL`.
* Else:

  * Store `head->next` to temp.
  * Delete `head`, assign `head = temp`, and `head->prev = NULL`.

#### 🧾 Code:

```cpp
if (head != NULL) {
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        head->prev = NULL;
    }
}
```

---

### 🧹 2. Delete from End

#### 🧠 Logic:

* Traverse to last node.
* If only one node, delete and set `head = NULL`.
* Else, set `curr->prev->next = NULL` and delete last node.

#### 🧾 Code:

```cpp
if (head != NULL) {
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* curr = head;
        while (curr->next != NULL) curr = curr->next;

        curr->prev->next = NULL;
        delete curr;
    }
}
```

---

## 🔁 DLL Creation Using Recursion

#### 🧠 Recursive Creation Function:

```cpp
Node* createDLL(int arr[], int index, int size, Node* back) {
    if (index == size) return NULL;

    Node* temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = createDLL(arr, index + 1, size, temp);
    return temp;
}
```

#### 🔄 Reverse DLL Creation:

```cpp
Node* createDLLReverse(int arr[], int index, int size, Node* back) {
    if (index == size) return back;

    Node* temp = new Node(arr[index]);
    temp->next = back;
    if (back != NULL) back->prev = temp;

    return createDLLReverse(arr, index + 1, size, temp);
}
```

---

## 📊 Diagram: DLL Node Structure

```
NULL <- [1] <-> [2] <-> [3] <-> [4] -> NULL
```

Each node stores:

* `prev` pointing to the previous node
* `next` pointing to the next node

---

## 🧪 Example: Print DLL

```cpp
Node* temp = head;
while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
}
```

---

## 📝 Summary

| Operation          | Time Complexity |
| ------------------ | --------------- |
| Insertion (start)  | O(1)            |
| Insertion (end)    | O(n)            |
| Insertion (middle) | O(n)            |
| Deletion (start)   | O(1)            |
| Deletion (end)     | O(n)            |

---

## ✅ Best Use Cases

* Navigating both directions (e.g. browsers, undo-redo)
* Efficient insertions and deletions from both ends

---

