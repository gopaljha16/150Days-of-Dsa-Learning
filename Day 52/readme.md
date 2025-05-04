Here are the **Day 52: Linked List Notes** with a detailed explanation of each program using your original code. Every line is broken down, and example outputs are also provided. The notes are written GitHub-style for clarity and future revision.

---

# 📘 Day 52 – Introduction to Linked List in C++

## 🔗 What is a Linked List?

A **linked list** is a dynamic data structure made of **nodes**. Each node contains:

1. **Data**
2. **Pointer to the next node**

### ✅ Key Points:

* Unlike arrays, linked lists don't require contiguous memory.
* You can easily insert/delete elements without shifting others.
* Types: Singly, Doubly, and Circular Linked Lists (today we focus on **Singly Linked List**).

---

## 📌 1. Static and Dynamic Node Creation

```cpp
class  Node{
    public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};
```

### 🔍 Explanation:

* `Node` is a class representing each node.
* `data`: stores the value.
* `next`: stores the address of the next node.
* Constructor initializes the data and sets next to `NULL`.

---

### 🔹 Static Node Creation

```cpp
// Node A1(4);
// cout<<A1.data<<endl; // prints 4
// cout<<A1.next<<endl; // prints 0 (NULL)
```

### 🔹 Dynamic Node Creation

```cpp
Node *Head;
Head = new Node(10);
cout<<Head->data<<endl; // 10
cout<<Head->next<<endl; // 0 (NULL)
```

🧠 This creates one node dynamically and stores its address in `Head`.

---

## 📌 2. Insertion at the Beginning (Using Array)

```cpp
int arr[] = {2, 4, 6, 8,10};
Node *Head = NULL;
```

### 🔄 For Loop:

```cpp
for (int i = 0; i < 5; i++)
{
    if (Head == NULL)
        Head = new Node(arr[i]);
    else {
        Node *temp = new Node(arr[i]);
        temp->next = Head;
        Head = temp;
    }
}
```

### 🧠 What's happening?

* First node becomes `Head`.
* Every new node is inserted before current `Head` and becomes the new `Head`.

### 📤 Output (Reversed order):

```
10 8 6 4 2
```

---

## 📌 3. Insertion at the End (Optimized with Tail Pointer)

```cpp
Node *Head = NULL, *Tail = NULL;
```

### 🔄 Loop:

```cpp
for (int i=0; i<5; i++) {
    if (Head == NULL) {
        Head = new Node(arr[i]);
        Tail = Head;
    } else {
        Tail->next = new Node(arr[i]);
        Tail = Tail->next;
    }
}
```

### 🔍 How it works:

* First node is head and tail.
* New nodes are linked at tail and tail is updated.

### 📤 Output:

```
2 4 5 6 7
```

Efficient as it avoids traversing the list to find the end.

---

## 📌 4. Recursive Creation of Linked List (End Insertion)

```cpp
Node* CreateLinkedList(int arr[], int index, int size)
{
    if (index == size) return NULL;

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp;
}
```

### 🧠 Explanation:

* Base Case: stop recursion if index equals size.
* Recursive Step: create a node and call function to create rest of list.

### 📤 Output:

```
2 3 4 5 6
```

---

## 📌 5. Recursive Creation (Insertion at Beginning)

```cpp
Node* CreateLinkedList(int arr[], int index, int size, Node *prev)
{
    if (index == size) return prev;

    Node *temp = new Node(arr[index]);
    temp->next = prev;
    return CreateLinkedList(arr, index + 1, size, temp);
}
```

### 🔍 Explanation:

* Works in reverse order because each node points to the previous one.
* Mimics inserting at the **beginning** recursively.

### 📤 Output:

```
6 5 4 3 2
```

---

## 📌 6. Insertion at Middle (After `x` nodes)

```cpp
int x = 3;
int value = 10;
Node *temp = Head;
x--;
while (x--) temp = temp->next;
```

### 📌 Insert New Node:

```cpp
Node *temp2 = new Node(value);
temp2->next = temp->next;
temp->next = temp2;
```

### 🧠 Steps:

1. Move `temp` to (x-1)-th node.
2. Create a new node with `value`.
3. Insert it after `temp`.

### 📤 Output:

If input is: `2 3 4 5 6` and we insert `10` at position 3 (after 3rd node):

```
2 3 4 10 5 6
```

---

## ✅ Summary

| Operation            | Method             | Complexity |
| -------------------- | ------------------ | ---------- |
| Insert at Start      | Iterative          | O(1)       |
| Insert at End        | With Tail          | O(1)       |
| Insert in Middle     | Iterative          | O(n)       |
| Create (Recursively) | Top-Down/Bottom-Up | O(n)       |
| Traverse & Print     | Iterative          | O(n)       |

---

## 🔚 Next Steps

* Learn deletion in linked list
* Handle edge cases like empty list, single node
* Practice dry-running each insertion step

---


